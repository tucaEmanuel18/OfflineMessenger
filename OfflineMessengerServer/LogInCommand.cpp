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
	ss << "SELECT * FROM USERS "
		<<"WHERE username = '" << username.c_str()
		<<"' AND password = '" << password.c_str() << "';";
	printf("Querry= %s\n", ss.str().c_str());
	string select_user_sql = ss.str();
	
	// execute quterry
	json data = DatabaseManager::execute_dql(db, select_user_sql.c_str());
	
	int result = data["result_code"];
	// prepare response
	if(result == SQLITE_OK){
		if(data["data"].size() == 0){
			response = {
				{"status", 401},
				{"message", "Invalid credentials!"}
			};
		}
		else
		{
			response = {
				{"status", 200},
				{"user", data["data"].at(0)}
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
