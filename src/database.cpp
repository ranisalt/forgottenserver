/**
 * The Forgotten Server - a free and open-source MMORPG server emulator
 * Copyright (C) 2016  Mark Samman <mark.samman@gmail.com>
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

#include <errmsg.h>

extern ConfigManager g_config;

std::string Query::escapeBlob(const char* s, std::size_t length) const
{
	// the worst case is 2n + 1
	size_t maxLength = (length * 2) + 1;

	std::string escaped;
	escaped.reserve(maxLength);

	if (length != 0) {
		query.escape_string(&escaped, s, length);
	}

	return escaped;
}

std::string Query::escapeString(const std::string& s) const
{
	return escapeBlob(s.data(), s.length());
}

bool Database::connect()
{
	// connection handle initialization
	handle.connect(g_config.getString(ConfigManager::MYSQL_DB).data(),
				   g_config.getString(ConfigManager::MYSQL_HOST).data(),
				   g_config.getString(ConfigManager::MYSQL_USER).data(),
				   g_config.getString(ConfigManager::MYSQL_PASS).data(),
				   g_config.getNumber(ConfigManager::SQL_PORT));
	if (!handle.connected()) {
		std::cout << std::endl << "Failed to initialize MySQL connection handle." << std::endl;
		std::cout << std::endl << "MySQL Error Message: " << handle.error() << std::endl;
		return false;
	}

	// automatic reconnect
	handle.set_option(new mysqlpp::ReconnectOption(true));

	DBResult_ptr result = storeQuery("SHOW VARIABLES LIKE 'max_allowed_packet'");
	if (result) {
		maxPacketSize = result->getNumber<uint64_t>("Value");
	}
	return true;
}

Query Database::createQuery(const std::string& qstr) {
	return {handle.query(qstr)};
}

Transaction Database::createTransaction() {
	return {handle};
}

bool Database::beginTransaction()
{
	transaction.reset(new mysqlpp::Transaction{handle});
	databaseLock.lock();
	return true;
}

bool Database::rollback()
{
	transaction->rollback();
	databaseLock.unlock();
	return true;
}

bool Database::commit()
{
	transaction->commit();
	databaseLock.unlock();
	return true;
}

bool Database::executeQuery(const std::string& query)
{
	bool success = true;

	// executes the query
	databaseLock.lock();
	auto my_query = handle.query(query);

	while (!my_query.execute()) {
		std::cout << "[Error - mysql_real_query] Query: " << query << std::endl << "Message: " << my_query.error() << std::endl;
		auto error = my_query.errnum();
		if (error != CR_SERVER_LOST && error != CR_SERVER_GONE_ERROR && error != CR_CONN_HOST_ERROR && error != 1053/*ER_SERVER_SHUTDOWN*/ && error != CR_CONNECTION_ERROR) {
			success = false;
			break;
		}
		std::this_thread::sleep_for(std::chrono::seconds(1));
	}

	my_query.store();
	databaseLock.unlock();

	return success;
}

bool Database::executeQuery(Query& query)
{
	bool success = true;

	// executes the query
	databaseLock.lock();

	while (!query.execute()) {
		std::cout << "[Error - query::execute] Query: " << query.str() << std::endl << "Message: " << handle.error() << std::endl;
		auto error = handle.errnum();
		if (error != CR_SERVER_LOST && error != CR_SERVER_GONE_ERROR && error != CR_CONN_HOST_ERROR && error != 1053/*ER_SERVER_SHUTDOWN*/ && error != CR_CONNECTION_ERROR) {
			success = false;
			break;
		}
		std::this_thread::sleep_for(std::chrono::seconds(1));
	}

	query.store();
	databaseLock.unlock();

	return success;
}

DBResult_ptr Database::storeQuery(const std::string& query)
{
	databaseLock.lock();
	auto my_query = handle.query(query);

	retry:
	while (!my_query.execute()) {
		std::cout << "[Error - mysql_real_query] Query: " << query << std::endl << "Message: " << my_query.error() << std::endl;
		auto error = my_query.errnum();
		if (error != CR_SERVER_LOST && error != CR_SERVER_GONE_ERROR && error != CR_CONN_HOST_ERROR && error != 1053/*ER_SERVER_SHUTDOWN*/ && error != CR_CONNECTION_ERROR) {
			break;
		}
		std::this_thread::sleep_for(std::chrono::seconds(1));
	}

	auto res = my_query.store();
	if (!res) {
		std::cout << "[Error - mysql_store_result] Query: " << query << std::endl << "Message: " << my_query.error() << std::endl;
		auto error = my_query.errnum();
		if (error != CR_SERVER_LOST && error != CR_SERVER_GONE_ERROR && error != CR_CONN_HOST_ERROR && error != 1053/*ER_SERVER_SHUTDOWN*/ && error != CR_CONNECTION_ERROR) {
			databaseLock.unlock();
			return nullptr;
		}
		goto retry;
	}
	databaseLock.unlock();

	// retrieving results of query
	DBResult_ptr result = std::make_shared<DBResult>(res);
	if (!result->hasNext()) {
		return nullptr;
	}
	return result;
}

DBResult_ptr Database::storeQuery(Query& query) {
	databaseLock.lock();

	retry:
	while (!query.execute()) {
		std::cout << "[Error - query::execute] Query: " << query.str() << std::endl << "Message: " << handle.error() << std::endl;
		auto error = handle.errnum();
		if (error != CR_SERVER_LOST && error != CR_SERVER_GONE_ERROR && error != CR_CONN_HOST_ERROR && error != 1053/*ER_SERVER_SHUTDOWN*/ &&
			error != CR_CONNECTION_ERROR) {
			break;
		}
		std::this_thread::sleep_for(std::chrono::seconds(1));
	}

	auto res = query.store();
	if (!res) {
		std::cout << "[Error - query::store] Query: " << query.str() << std::endl << "Message: " << handle.error() << std::endl;
		auto error = handle.errnum();
		if (error != CR_SERVER_LOST && error != CR_SERVER_GONE_ERROR && error != CR_CONN_HOST_ERROR && error != 1053/*ER_SERVER_SHUTDOWN*/ && error != CR_CONNECTION_ERROR) {
			databaseLock.unlock();
			return nullptr;
		}
		goto retry;
	}
	databaseLock.unlock();

	// retrieving results of query
	DBResult_ptr result = std::make_shared<DBResult>(res);
	if (!result->hasNext()) {
		return nullptr;
	}
	return result;
}

DBResult::DBResult(const mysqlpp::StoreQueryResult& res) : res(res) {
	std::size_t index = 0;
	auto fieldNames = res.field_names();
	for (const auto& name : *fieldNames) {
		listNames[name] = index++;
	}
	row = res.begin();
}

std::string DBResult::getString(const std::string& s) const
{
	auto it = listNames.find(s);
	if (it == listNames.end()) {
		std::cout << "[Error - DBResult::getString] Column '" << s << "' does not exist in result set." << std::endl;
		return std::string();
	}

	try {
		return row->at(it->second).data();
	} catch (const mysqlpp::BadIndex&) {
		std::cout << "[Warning - DBResult::getString] Column '" << s << "' does not exist in row values." << std::endl;
		return {};
	}
}

const char* DBResult::getStream(const std::string& s, unsigned long& size) const
{
	auto it = listNames.find(s);
	if (it == listNames.end()) {
		std::cout << "[Error - DBResult::getStream] Column '" << s << "' doesn't exist in the result set" << std::endl;
		size = 0;
		return nullptr;
	}

	size = row->at(it->second).size();
	return row->at(it->second).data();
}

bool DBResult::hasNext() const
{
	return row != res.end();
}

bool DBResult::next()
{
	++row;
	return hasNext();
}
