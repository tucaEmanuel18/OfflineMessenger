#include "LogInCommand.h"

LogInCommand::LogInCommand(sqlite3* db, string username, string password)
{
	assert(db);
	this->db = db;
	if(username.empty()){
		throw std::invalid_argument("The username should not be empty!");
	}
	
	if(password.empty()){
		throw std::invalid_argument("The password should not be empty!");
	}
	
	this->username = username;
	this->password = password;
}

LogInCommand::~LogInCommand()
{
}

json LogInCommand::execute(){
	printf("LogIn user with username: %s | password = %s\n", this->username.c_str(), this->password.c_str());
	json response;
	
	// prepare query
	std::stringstream ss;
	ss << "SELECT id_user, username, connected FROM USERS "
		<<"WHERE username = '" << username.c_str()
		<<"' AND password = '" << password.c_str() << "';";
	string select_user_sql = ss.str();
	
	// execute querry
	json data = DatabaseManager::execute_dql(db, select_user_sql.c_str());
	
	int result = data["result_code"];
	// prepare response
	if(result == SQLITE_OK){
		if(data["data"].size() != 0){
			ss << "UPDATE users SET connected = 1 WHERE username = '" << username.c_str() << "';";
			string update_connected_sql = ss.str();
			json update_data = DatabaseManager::execute_dql(db, update_connected_sql.c_str());
			int update_result = update_data["result_code"];
			if(update_result == SQLITE_OK){
				data["data"].at(0).at("connected") = "1";
				response = {
					{"status", 200},
					{"user", data["data"].at(0)}
				};
			}else{
				response = {
					{"status", 500},
					{"message", "[Database Error] - Something went wrong when trying to update connected state for logged in user!"}
				};
			}
		}
		else
		{	
			response = {
				{"status", 401},
				{"message", "Invalid credentials!"}
			};
		}
	}else{
		response = {
			{"status", 500},
			{"message", "[Database Error] - Something went wrong when trying to query for an existing user!"}
		};
	}
	
	return response;
}
