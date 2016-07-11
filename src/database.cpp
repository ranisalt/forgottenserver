/**
 * The Forgotten Server - a free and open-source MMORPG server emulator
 * Copyright (C) 2017  Mark Samman <mark.samman@gmail.com>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 */

#include "otpch.h"

#include "configmanager.h"
#include "database.h"

extern ConfigManager g_config;

Database::~Database()
{
	sqlite3_close(handle);
}

bool Database::connect()
{
	// connection handle initialization
	if (sqlite3_open(g_config.getString(ConfigManager::SQLITE_DB).c_str(), &handle) != SQLITE_OK) {
		std::cout << std::endl << "Failed to initialize SQLite connection handle." << std::endl;
		sqlite3_close(handle);
		return false;
	}
	return true;
}

bool Database::beginTransaction()
{
	return executeQuery("BEGIN");
}

bool Database::rollback()
{
	if (!executeQuery("ROLLBACK")) {
		std::cout << "[Error - sqlite3_rollback] Message: " << sqlite3_errmsg(handle) << std::endl;
		return false;
	}
	return true;
}

bool Database::commit()
{
	if (!executeQuery("COMMIT")) {
		std::cout << "[Error - sqlite3_commit] Message: " << sqlite3_errmsg(handle) << std::endl;
		return false;
	}
	return true;
}

bool Database::executeQuery(const std::string& query)
{
	// executes the query
	std::lock_guard<std::recursive_mutex> lock(databaseLock);

	sqlite3_stmt* stmt;
	if (sqlite3_prepare_v2(handle, query.c_str(), static_cast<int>(query.size()), &stmt, nullptr) != SQLITE_OK) {
		sqlite3_finalize(stmt);
		std::cout << "[Error - sqlite3_prepare] Query: " << query.substr(0, 256) << std::endl << "Message: " << sqlite3_errmsg(handle) << std::endl;
		return false;
	}

	auto rc = sqlite3_step(stmt);
	while (rc != SQLITE_OK && rc != SQLITE_DONE && rc != SQLITE_ROW) {
		sqlite3_finalize(stmt);
		std::cout << "[Error - sqlite3_step] Query: " << query.substr(0, 256) << std::endl << "Message: " << sqlite3_errmsg(handle) << std::endl;
		return false;
	}

	sqlite3_finalize(stmt);
	return true;
}

DBResult_ptr Database::storeQuery(const std::string& query)
{
	std::lock_guard<std::recursive_mutex> lock(databaseLock);

	sqlite3_stmt* stmt;
	if (sqlite3_prepare_v2(handle, query.c_str(), static_cast<int>(query.size()), &stmt, nullptr) != SQLITE_OK) {
		sqlite3_finalize(stmt);
		std::cout << "[Error - sqlite3_prepare] Query: " << query.substr(0, 256) << std::endl << "Message: " << sqlite3_errmsg(handle) << std::endl;
		std::this_thread::sleep_for(std::chrono::seconds(1));
	}

	auto rc = sqlite3_step(stmt);
	if (rc != SQLITE_OK && rc != SQLITE_DONE && rc != SQLITE_ROW) {
		sqlite3_finalize(stmt);
		std::cout << "[Error - sqlite3_step] Query: " << query.substr(0, 256) << std::endl << "Message: " << sqlite3_errmsg(handle) << std::endl;
		return nullptr;
	}

	DBResult_ptr result = std::make_shared<DBResult>(stmt, rc == SQLITE_ROW);
	if (!result->hasNext()) {
		return nullptr;
	}
	return result;
}

std::string Database::escapeString(const std::string& s) const
{
	return escapeBlob(s.c_str(), s.length(), false);
}

std::string Database::escapeBlob(const char* s, uint32_t length, bool binary/* = true*/) const
{
	// the worst case is 2n + 1
	size_t maxLength = (length * 2) + 1;

	std::string escaped;
	escaped.reserve(maxLength + 3); // maxLength + x + quotation marks
	/*if (binary) {
		escaped.push_back('x');
	}*/
	escaped.push_back('\'');

	for (const char* ch = s; ch < s + length; ++ch) {
		if (*ch == '\'' || *ch == '\\') {
			escaped.push_back('\\');
		}
		escaped.push_back(*ch);
	}

	escaped.push_back('\'');
	return escaped;
}

DBResult::DBResult(sqlite3_stmt* res, bool rowAvailable): handle(res), rowAvailable(rowAvailable)
{
	for (int i = 0; i < sqlite3_column_count(handle); ++i) {
		listNames[sqlite3_column_name(handle, i)] = i;
	}
}

DBResult::~DBResult()
{
	sqlite3_finalize(handle);
}

std::string DBResult::getString(const std::string& s) const
{
	auto it = listNames.find(s);
	if (it == listNames.end()) {
		std::cout << "[Error - DBResult::getString] Column '" << s << "' does not exist in result set." << std::endl;
		return std::string();
	}

	const char* data = reinterpret_cast<const char*>(sqlite3_column_text(handle, it->second));
	if (data == nullptr) {
		return std::string();
	}
	return data;
}

const char* DBResult::getStream(const std::string& s, unsigned long& size) const
{
	auto it = listNames.find(s);
	if (it == listNames.end()) {
		std::cout << "[Error - DBResult::getStream] Column '" << s << "' doesn't exist in the result set" << std::endl;
		size = 0;
		return nullptr;
	}

	const char* data = reinterpret_cast<const char*>(sqlite3_column_blob(handle, it->second));
	size = static_cast<unsigned long>(sqlite3_column_bytes(handle, it->second));
	return data;
}

bool DBResult::hasNext() const
{
	return rowAvailable;
}

bool DBResult::next()
{
	rowAvailable = sqlite3_step(handle) == SQLITE_ROW;
	return rowAvailable;
}

DBInsert::DBInsert(std::string query) : query(std::move(query))
{
	this->length = this->query.length();
}

bool DBInsert::addRow(const std::string& row)
{
	// adds new row to buffer
	const size_t rowLength = row.length();
	length += rowLength;
	if (length > SQLITE_LIMIT_LENGTH && !execute()) {
		return false;
	}

	if (values.empty()) {
		values.reserve(rowLength + 2);
		values.push_back('(');
		values.append(row);
		values.push_back(')');
	} else {
		values.reserve(values.length() + rowLength + 3);
		values.push_back(',');
		values.push_back('(');
		values.append(row);
		values.push_back(')');
	}
	return true;
}

bool DBInsert::addRow(std::ostringstream& row)
{
	bool ret = addRow(row.str());
	row.str(std::string());
	return ret;
}

bool DBInsert::execute()
{
	if (values.empty()) {
		return true;
	}

	// executes buffer
	bool res = Database::getInstance().executeQuery(query + values);
	values.clear();
	length = query.length();
	return res;
}
