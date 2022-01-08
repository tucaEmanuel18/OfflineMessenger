#include "CreateMessageCommand.h"

CreateMessageCommand::CreateMessageCommand(sqlite3* db, string auth, string id_room, string content, string reply_to)
{
	assert(db);
	this->db = db;
	if(auth.empty()){
		throw std::domain_error("Unauthorized! The auth field is empty!");
	}
	if(id_room.empty()){
		throw std::invalid_argument("The id_room may not be empty!");
	}
	if(content.empty()){
		throw std::invalid_argument("The content field may not be empty");
	}
	this->auth = auth;
	this->id_room = id_room;
	this->content = content;
	this->reply_to = reply_to;
}

CreateMessageCommand::~CreateMessageCommand()
{
}


json CreateMessageCommand::execute(){
	printf("Create new message message: sender = %s | room = %s | content: %s | reply_to: %s\n", 
			auth.c_str(), id_room.c_str(), content.c_str(), reply_to.c_str());
	json response;
	
	// prepare query
	std::stringstream ss;
	ss << "INSERT INTO messages (id_sender, id_room, content, reply_to) " <<
			"VALUES ('" << auth.c_str() << "', '" << 
						id_room.c_str() << "', '" << 
						content.c_str() <<"', '" << 
						reply_to.c_str() << "');";
	string create_message_sql = ss.str();
	printf("Create_message_sql = %s", create_message_sql.c_str());
	
	// execute querry
	json data = DatabaseManager::execute_ddl(db, create_message_sql.c_str());
	
	int result = data["result_code"];
	// prepare response
	if(result == SQLITE_OK){
		response = {
			{"status", 201},
			{"message", "New message created!"}
		};
	}else{
		response = {
			{"status", 500},
			{"message", "[Database Error] - Something went wrong when trying to create a new message!"},
			{"db_message", data["error_messsage"]}
		};
	}
	return response;
}

