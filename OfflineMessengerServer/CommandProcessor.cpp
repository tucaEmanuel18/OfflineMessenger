#include "CommandProcessor.h"

CommandProcessor::CommandProcessor(sqlite3* db)
{
	this->db = db;
}

CommandProcessor::~CommandProcessor()
{
}

json CommandProcessor::process(json command){
	json response;
	if(command.at("command").get<std::string>().compare("register") == 0){
		
		if(command.contains("username") && command.contains("password")){
			try{
				RegisterCommand register_command(db, command.at("username"), command.at("password"));
				response = register_command.execute();
			}catch(std::invalid_argument const& e){
				response = {
					{"status", 400},
					{"message", e.what()}
				};
			}
		}else{
			response = {
					{"status", 400},
					{"message", "This request should have an username and a password in payload!"}
				};
		}

	}
	
	else if(command.at("command").get<std::string>().compare("log") == 0){
		if(command.contains("username") && command.contains("password")){
			try{
				LogInCommand login_command(db, command.at("username"), command.at("password"));
				response = login_command.execute();
			}catch(std::invalid_argument const& e){
				response = {
					{"status", 400},
					{"message", e.what()}
				};
			}
		}else{
			response = {
					{"status", 400},
					{"message", "This request should have an username and a password in payload!"}
				};
		}
	}
	
	else if(command.at("command").get<std::string>().compare("new_conv") == 0){
		if(command.contains("auth") && command.contains("friend_username")){
			try{
				CreateConversationCommand new_conv_command(db, command.at("auth"), command.at("friend_username"));
				response = new_conv_command.execute();
			}catch(std::domain_error const& e){
				response = {
					{"status", 401},
					{"message", e.what()}
				};
			}
			catch(std::invalid_argument const& e){
				response = {
					{"status", 400},
					{"message", e.what()}
				};
			}
		}else{
			response = {
					{"status", 400},
					{"message", "This request should have auth and a friend_username in payload!"}
				};
		}
	}else{
		response = {
				{"status", 405},
				{"message", "Unknown command!"}
			};
	}
	
	
	
	return response;
}

