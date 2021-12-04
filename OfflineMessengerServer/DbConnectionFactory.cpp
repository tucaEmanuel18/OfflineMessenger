#include "DbConnectionFactory.h"
#include <sqlite3.h>
DbConnectionFactory::DbConnectionFactory()
{
}

DbConnectionFactory::~DbConnectionFactory()
{
}

sqlite3* DbConnectionFactory::get_connection(){
	sqlite3* db_conn;
	if(sqlite3_open(db_file_name, &db_conn)){
		std::string errmsg = "Database connection can't be opened! Error: ";
		errmsg.append(sqlite3_errmsg(db_conn));
		throw errmsg.c_str();
	}else{
		create_database_structure(db_conn);
		return db_conn;
	}
}

void DbConnectionFactory::close_connection(sqlite3* db_conn){
	sqlite3_close(db_conn);
}

int DbConnectionFactory::ddl_callback(void *NotUsed, int argc, char **argv, char **azColName){
	int i;
	for(i = 0; i<argc; i++) {
		printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
	}
	printf("\n");
	return 0;
}

int DbConnectionFactory::dql_callback(void *data, int argc, char **argv, char **azColName){
	int i;
   fprintf(stderr, "%s: ", (const char*)data);
   
   for(i = 0; i<argc; i++){
      printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
   }
   
   printf("\n");
   return 0;
}

int DbConnectionFactory::execute_ddl(sqlite3* db_conn, const char* sql){
	char* err_msg = 0;
	int rc = sqlite3_exec(db_conn, sql, ddl_callback, 0, &err_msg);
	if(rc != SQLITE_OK){
		fprintf(stderr, "SQL error: %s\n", err_msg);
		sqlite3_free(err_msg);
	}else{
		fprintf(stdout, "DDL query successfully run\n");
	}
	
	return rc;
}
int DbConnectionFactory::execute_dql(sqlite3* db_conn, const char* sql){
	char* err_msg = 0;
	const char* data = "Callback function called";
	int rc = sqlite3_exec(db_conn, sql, dql_callback, (void*) data, &err_msg);
	if(rc != SQLITE_OK){
		fprintf(stderr, "SQL error: %s\n", err_msg);
		sqlite3_free(err_msg);
	}else{
		fprintf(stdout, "DQL query successfully run\n");
	}
	
	return rc;
}

void DbConnectionFactory::create_database_structure(sqlite3* db_conn){
	const char* user_table_sql = "CREATE TABLE IF NOT EXISTS USERS("
		"id_user INTEGER PRIMARY KEY AUTOINCREMENT, "
		"username TEXT NOT NULL UNIQUE, "
		"password TEXT NOT NULL, "
		"connected INTEGER NOT NULL);";
	execute_ddl(db_conn, user_table_sql);
}