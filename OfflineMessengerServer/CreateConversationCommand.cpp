#include "CreateConversationCommand.h"

CreateConversationCommand::CreateConversationCommand(sqlite3* db, string my_id, string friend_username)
{
	assert(db);
	this->db = db;
	if(my_id.empty()){
		throw std::domain_error("Unauthorized! The id field is empty!");
	}
	if(friend_username.empty()){
		throw std::invalid_argument("The friend username should not be empty!");
	}
	this->my_id = my_id;
	this->friend_username = friend_username;
}

CreateConversationCommand::~CreateConversationCommand()
{
}


json CreateConversationCommand::execute(){
	printf("Create new room between me (id = %s) and user with username: %s\n", 
				this->my_id.c_str(), this->friend_username.c_str());
	json response;
	
	// Check if user with friend_username exists
	std::stringstream ss;
	ss << "SELECT id_user FROM users WHERE username = '" << friend_username.c_str() << "';";
	string check_user_sql = ss.str();
	
	json data = DatabaseManager::execute_dql(db, check_user_sql.c_str());
	int result = data["result_code"];
	
	if(result == SQLITE_OK){
		if(data["data"].size() == 0){
			response = {
				{"status", 400},
				{"message", "User with this username doesn't exists!"}
			};
			return response;
		}
	}else{
		printf("Querry Result = %d", result);
		response = {
			{"status", 500},
			{"message", "[Database Error] - Something went wrong when trying to query for check existence of user with given username!"},
			{"db_message", data["error_message"]}
		};
		return response;
	}
	
	string friend_id = data["data"].at(0).at("id_user").dump();
	friend_id.erase(remove(friend_id.begin(), friend_id.end(), '"'), friend_id.end());

	// check if room with this users already exists
		std::stringstream ss_rooms;
		ss_rooms << "SELECT id_room FROM rooms WHERE " << 
						"(participant_1 = "<< my_id.c_str() << " AND participant_2 = " << friend_id.c_str() << ") " <<
							"OR (participant_2 = " << my_id.c_str() << " AND participant_1 = " << friend_id.c_str() << ");";
	string select_rooms_sql = ss_rooms.str();
	
	data = DatabaseManager::execute_dql(db, select_rooms_sql.c_str());
	result = data["result_code"];
	
	if(result == SQLITE_OK){
		if(data["data"].size() != 0){
			response = {
				{"status", 403},
				{"message", "A conversation with this user is already created!"}
			};
			return response;
		}
	}else{
		printf("Querry Result = %d", result);
		response = {
			{"status", 500},
			{"message", "[Database Error] - Something went wrong when trying to query for check existence of user with given username!"},
			{"db_message", data["error_message"]}
		};
		return response;
	}
	
	
	// prepare insert query
	ss << "INSERT INTO ROOMS (participant_1, participant_2) "
		<<"VALUES('" << my_id.c_str() << "', " << "(SELECT id_user FROM users WHERE username = '" << friend_username.c_str() << "'));";
	string insert_room_sql = ss.str();
	
	// execute querry
	data = DatabaseManager::execute_ddl(db, insert_room_sql.c_str());
	
	result = data["result_code"];
	// prepare response
	if(result == SQLITE_OK){
		response = {
			{"status", 201},
			{"message", "New conversation created!"}
		};
	}else{
		printf("Querry Result = %d", result);
		response = {
			{"status", 500},
			{"message", "[Database Error] - Something went wrong when trying to create a new conversation room!"},
			{"db_message", data["error_message"]}
		};
	}
	
	return response;
}

