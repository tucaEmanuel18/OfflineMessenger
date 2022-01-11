#include "DatabaseManager.h"
#include <sqlite3.h>

using namespace std;
typedef vector<vector<pair<string, string> > > table_type;

DatabaseManager::DatabaseManager()
{
}

DatabaseManager::~DatabaseManager()
{
}

sqlite3* DatabaseManager::get_connection(){
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

void DatabaseManager::close_connection(sqlite3* db_conn){
	sqlite3_close(db_conn);
}

int DatabaseManager::ddl_callback(void *NotUsed, int argc, char **argv, char **azColName){
//	int i;
//	for(i = 0; i<argc; i++) {
//		printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
//	}
//	printf("\n");
	return 0;
}

json DatabaseManager::execute_ddl(sqlite3* db_conn, const char* sql){
	char* err_msg = 0;
	json response;
	int rc;
	int count = 0;
	do{
		rc = sqlite3_exec(db_conn, sql, ddl_callback, 0, &err_msg);
		if(count > 2){
			printf("[Log] DDL - Check for BUSY\n");
		}
		count++;
	}while(rc == SQLITE_BUSY);
	
	response["result_code"] = rc;
	
	if(rc != SQLITE_OK){
		fprintf(stderr, "SQL error: %s\n", err_msg);
		response["error_message"] = err_msg;
		sqlite3_free(err_msg);
	}else{
		fprintf(stdout, "DDL query successfully run\n");
	}
	return response;
}

int DatabaseManager::dql_callback(void *ptr, int argc, char **argv, char **azColName){
	int i;
	table_type* table = static_cast<table_type*>(ptr);
	vector<pair<string, string> > row;
	for(i = 0; i<argc; i++){
//		printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
		pair<string, string> entity(string(azColName[i]), argv[i] ? string(argv[i]) : string("NULL"));
		row.push_back(entity);
	}
	table->push_back(row);
	return 0;
}


json DatabaseManager::execute_dql(sqlite3* db_conn, const char* sql){
	char* err_msg = 0;
	table_type table;
	json response;
	int rc;
	int count = 0;
	do{
		rc = sqlite3_exec(db_conn, sql, dql_callback, &table, &err_msg);
		if(count > 2){
			printf("[Log] DQL - Check for BUSY\n");
		}
		count++;
	}while(rc == SQLITE_BUSY);
	response["result_code"] = rc;
	
	if(rc != SQLITE_OK){
		fprintf(stderr, "SQL error: %s\n", err_msg);
		response["error_message"] = err_msg;
		sqlite3_free(err_msg);
	}else{
		fprintf(stdout, "DQL query successfully run\n");
		response["data"] = json::array();
		for(auto &row : table){
			json j_row;
			for (auto &entity : row){
				j_row[entity.first.c_str()] = entity.second.c_str();
			}
			response["data"].push_back(j_row);
		}
	}
	return response;
}

void DatabaseManager::create_database_structure(sqlite3* db_conn){
	const char* user_table_sql = "CREATE TABLE IF NOT EXISTS USERS("
		"id_user INTEGER PRIMARY KEY AUTOINCREMENT, "
		"username TEXT NOT NULL UNIQUE, "
		"password TEXT NOT NULL, "
		"connected INTEGER NOT NULL);";
	execute_ddl(db_conn, user_table_sql);
	
	const char* rooms_table_sql = "CREATE TABLE IF NOT EXISTS ROOMS("
	"id_room INTEGER PRIMARY KEY AUTOINCREMENT, "
	"participant_1 INTEGER NOT NULL, "
	"participant_2 INTEGER NOT NULL CHECK(participant_2 != participant_1), "
	"FOREIGN KEY(participant_1) REFERENCES users(id_user), "
	"FOREIGN KEY(participant_2) REFERENCES users(id_user)"
	");";
	execute_ddl(db_conn, rooms_table_sql);
	
	
	const char* messages_table_sql = "CREATE TABLE IF NOT EXISTS MESSAGES("
		"id_message INTEGER PRIMARY KEY AUTOINCREMENT, "
		"id_sender INTEGER NOT NULL, "
		"id_room INTEGER NOT NULL, "
		"reply_to INTEGER, "
		"content TEXT NOT NULL, "
		"FOREIGN KEY(id_sender) REFERENCES users(id_user), "
		"FOREIGN KEY(id_room) REFERENCES rooms(id_room), "
		"FOREIGN KEY(reply_to) REFERENCES messages(id_message)"
		");";
	execute_ddl(db_conn, messages_table_sql);
	

}