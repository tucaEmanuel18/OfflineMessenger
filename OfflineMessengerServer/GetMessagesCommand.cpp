#include "GetMessagesCommand.h"

GetMessagesCommand::GetMessagesCommand(sqlite3* db, string auth, string id_room)
{
	assert(db);
	this->db = db;
	if(auth.empty()){
		throw std::domain_error("Unauthorized! The auth field should not be empty!");
	}
	
	if(id_room.empty()){
		throw std::invalid_argument("The id_room field should not be empty!");
	}
	
	this->auth = auth;
	this->id_room = id_room;
}

GetMessagesCommand::~GetMessagesCommand()
{
}

json GetMessagesCommand::execute(){
	printf("Get messeges from room with id_room = %s\n", id_room.c_str());
	json response;
	
	// prepare query
	std::stringstream ss;
	ss << "SELECT m.*, r.id_sender as reply_sender, r.content as reply_content, r.time as reply_time FROM " <<
	"(SELECT * FROM messages WHERE id_room='" << id_room.c_str() << "') as m "
	"LEFT JOIN messages as r on m.reply_to = r.id_message ORDER BY datetime(m.time) DESC;";
	string select_messages_sql = ss.str();
	
	// execute querry
	json data = DatabaseManager::execute_dql(db, select_messages_sql.c_str());
	
	int result = data["result_code"];
	// prepare response
	if(result == SQLITE_OK){
		response = {
					{"status", 200},
					{"messages", data["data"]}
		};
	}else{
		response = {
			{"status", 500},
			{"message", "[Database Error] - Something went wrong when trying to query for room messages!"},
			{"db_message", data["error_message"]}
		};
	}
	return response;
}
