#include "RegisterCommand.h"

RegisterCommand::RegisterCommand(sqlite3* db, string username, string password)
{
	assert(db);
	this->db = db;
	if(username.empty()){
		throw std::invalid_argument("The username should not be empty!");
	}
	
	if(password.empty()){
		throw std::invalid_argument("The password should not be empty!");
	}
	
	if(password.length() < 8){
		throw std::invalid_argument("Password must be at least 8 characters long");
	}
	this->username = username;
	this->password = password;
}

RegisterCommand::~RegisterCommand()
{
}

json RegisterCommand::execute(){
	printf("Register user with username: %s | password = %s\n", this->username.c_str(), this->password.c_str());
	json response;
	
	// prepare query
	std::stringstream ss;
	ss << "INSERT INTO USERS(username, password, connected) "
		<<"VALUES('" << username << "', '" << password << "', 0);";
	string insert_user_sql = ss.str();
	
	// execute querry
	json data = DatabaseManager::execute_ddl(db, insert_user_sql.c_str());
	int result = data["result_code"];
	// prepare response
	if(result == SQLITE_OK){
		response = {
			{"status", 201},
			{"message", "User was registered!"}
		};
	}else if(result == SQLITE_CONSTRAINT){
		response = {
			{"status", 409},
			{"message", "This username is already in use! Please select another username!"}
		};
	}else{
		response = {
			{"status", 500},
			{"message", "[Database Error] - Something went wrong when trying to create a new user!"},
			{"db_message", data["error_message"]}
		};
	}
	
	return response;
	
}
