#pragma once

#include <stdexcept>
#include <string>
#include "sqlite3.h"

#define db_file_name "../../database/offline_messenger.db"
class DbConnectionFactory
{
private:
	static void create_database_structure(sqlite3* db_conn);
	static int ddl_callback(void *NotUsed, int argc, char **argv, char **azColName);
	static int dql_callback(void *data, int argc, char **argv, char **azColName);
public:
	DbConnectionFactory();
	~DbConnectionFactory();
	static sqlite3* get_connection();
	static void close_connection(sqlite3* db_conn);
	static int execute_ddl(sqlite3* db_conn, const char* sql);
	static int execute_dql(sqlite3* db_conn, const char* sql);
};

