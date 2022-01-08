#include "GetAllConversationsCommand.h"

GetAllConversationsCommand::GetAllConversationsCommand(sqlite3* db, string auth)
{
	assert(db);
	this->db = db;
	if(auth.empty()){
		throw std::invalid_argument("Unauthorized! The auth field may not be empty!");
	}
	this->id = auth;
}

GetAllConversationsCommand::~GetAllConversationsCommand()
{
}


json GetAllConversationsCommand::execute(){
	printf("Get all conversations of user with id: %s\n", this->id.c_str());
	json response;
	
	// prepare query
	std::stringstream ss;
	ss <<   "SELECT f_p_1.id_room, u.id_user, u.username, u.connected FROM " <<
				"(SELECT id_room, participant_2 FROM rooms WHERE participant_1 = " << id.c_str() << ") as f_p_1 " << 
			"JOIN USERS u ON f_p_1.participant_2 = u.id_user " <<
		"UNION " <<
			"SELECT f_p_2.id_room, u.id_user, u.username, u.connected FROM " <<
				"(SELECT id_room, participant_1 FROM rooms WHERE participant_2 = " << id.c_str() << ") as f_p_2 " << 
			"JOIN USERS u ON f_p_2.participant_1 = u.id_user;";
	string select_user_sql = ss.str();
	
	// execute querry
	json data = DatabaseManager::execute_dql(db, select_user_sql.c_str());
	
	int result = data["result_code"];
	// prepare response
	if(result == SQLITE_OK){
		response = {
				{"status", 200},
				{"conversations", data["data"]}
		};
	}else{
		response = {
			{"status", 500},
			{"message", "[Database Error] - Something went wrong when trying to query for conversation user!"},
			{"db_message", data["error_message"]}
		};
	}
	
	return response;
}


