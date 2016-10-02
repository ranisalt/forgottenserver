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

#ifndef FS_DATABASE_H_A484B0CDFDE542838F506DCE3D40C693
#define FS_DATABASE_H_A484B0CDFDE542838F506DCE3D40C693

#include <boost/lexical_cast.hpp>

#include <mysql++/mysql++.h>

class DBResult;
typedef std::shared_ptr<DBResult> DBResult_ptr;

class Query;
class Transaction;

class Database
{
	public:
		Database() = default;

		// non-copyable
		Database(const Database&) = delete;
		Database& operator=(const Database&) = delete;

		/**
		 * Singleton implementation.
		 *
		 * @return database connection handler singleton
		 */
		static Database& getInstance()
		{
			static Database instance;
			return instance;
		}

		/**
		 * Connects to the database
		 *
		 * @return true on successful connection, false on error
		 */
		bool connect();

		Query createQuery(const std::string& statement);
		Transaction createTransaction();

		bool executeQuery(const std::string& query);
		bool executeQuery(Query& query);
		DBResult_ptr storeQuery(const std::string& query);
		DBResult_ptr storeQuery(Query& query);

		/**
		 * Retrieve id of last inserted row
		 *
		 * @return id on success, 0 if last query did not result on any rows with auto_increment keys
		 */
		uint64_t getLastInsertId() const {
			return 0;
			//return static_cast<uint64_t>(handle);
		}

		/**
		 * Get database engine version
		 *
		 * @return the database engine version
		 */
		std::string getClientVersion() const {
			return handle.client_version();
		}

		uint64_t getMaxPacketSize() const {
			return maxPacketSize;
		}

	protected:
		/**
		 * Transaction related methods.
		 *
		 * Methods for starting, commiting and rolling back transaction. Each of the returns boolean value.
		 *
		 * @return true on success, false on error
		 */
		bool beginTransaction();
		bool rollback();
		bool commit();

	private:
		mysqlpp::Connection handle{false};
		std::recursive_mutex databaseLock;
		std::unique_ptr<mysqlpp::Transaction> transaction;
		uint64_t maxPacketSize = 1048576;

	friend class Transaction;
};

class DBResult
{
	public:
		explicit DBResult(const mysqlpp::StoreQueryResult& res);

		// non-copyable
		DBResult(const DBResult&) = delete;
		DBResult& operator=(const DBResult&) = delete;

		template<typename T>
		T getNumber(const std::string& s) const
		{
			auto it = listNames.find(s);
			if (it == listNames.end()) {
				std::cout << "[Error - DBResult::getNumber] Column '" << s << "' doesn't exist in the result set" << std::endl;
				return static_cast<T>(0);
			}

			return row->at(it->second);
		}

		std::string getString(const std::string& s) const;
		const char* getStream(const std::string& s, unsigned long& size) const;

		bool hasNext() const;
		bool next();

	private:
		const mysqlpp::StoreQueryResult& res;
		mysqlpp::StoreQueryResult::const_iterator row;
		std::map<std::string, size_t> listNames;

	friend class Database;
};

class Query
{
	public:
		Query(mysqlpp::Query query) : query(std::move(query)) {
			query.parse();
		}

		bool execute() {
			auto res = query.execute(params);
			params.clear();
			return res;
		}

		mysqlpp::StoreQueryResult store() {
			auto res = query.store(params);
			params.clear();
			return res;
		}

		std::string escapeBlob(const char* s, std::size_t length) const;
		std::string escapeString(const std::string& s) const;
		std::string str() { return query.str(params); }

		template<class T>
		Query& operator<<(const T& value)
		{
			params << value;
			return *this;
		}

	protected:
		mysqlpp::Query query;
		mysqlpp::SQLQueryParms params;
};

class Transaction
{
	public:
		Transaction(mysqlpp::Transaction transaction) : transaction(std::move(transaction)) {}

		~Transaction() {
			if (state == STATE_START) {
				transaction.rollback();
			}
		}

		// non-copyable
		Transaction(const Transaction&) = delete;
		Transaction& operator=(const Transaction&) = delete;

		// movable
		Transaction(Transaction&&) = default;
		Transaction& operator=(Transaction&&) = default;

		bool begin() {
			state = STATE_START;
			return Database::getInstance().beginTransaction();
		}

		bool commit() {
			if (state != STATE_START) {
				return false;
			}

			state = STEATE_COMMIT;
			transaction.commit();
			return true;
		}

	private:
		enum TransactionStates_t {
			STATE_NO_START,
			STATE_START,
			STEATE_COMMIT,
		};

		mysqlpp::Transaction transaction;
		TransactionStates_t state = STATE_NO_START;
};

#endif
