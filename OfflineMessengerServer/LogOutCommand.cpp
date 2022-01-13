#include "LogOutCommand.h"

LogOutCommand::LogOutCommand(sqlite3* db, string auth)
{
	assert(db);
	this->db = db;
	if(auth.empty()){
		throw std::domain_error("The username should not be empty!");
	}
	
	this->auth = auth;
}

LogOutCommand::~LogOutCommand()
{
}

json LogOutCommand::execute(){
	printf("LogOut user with id = %s\n", this->auth.c_str());
	json response;
	
	// prepare query
	std::stringstream ss;
	ss << "UPDATE users SET connected = 0 WHERE id_user = '" << auth.c_str() << "';";
			string update_connected_sql = ss.str();
			json update_data = DatabaseManager::execute_ddl(db, update_connected_sql.c_str());
			int update_result = update_data["result_code"];
			if(update_result == SQLITE_OK){
				response = {
					{"status", 200},
					{"message", "Log out with success!"}
				};
			}else{
				response = {
					{"status", 500},
					{"message", "[Database Error] - Something went wrong when trying to log out the user!"}
				};
			}
	return response;
}
