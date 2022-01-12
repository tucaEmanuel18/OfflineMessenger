#include "CommandProcessor.h"

CommandProcessor::CommandProcessor(sqlite3* db, string log_prefix)
{
	this->db = db;
	this->log_prefix = log_prefix;
}

CommandProcessor::CommandProcessor(sqlite3* db)
{
	this->db = db;
	this->log_prefix = "";
}

CommandProcessor::~CommandProcessor()
{
}

json CommandProcessor::process(json command){
	json response;
	if(command.at("command").get<std::string>().compare("register") == 0){
		printf("%s Register command\n", log_prefix.c_str());

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
		printf("%s Login command\n", log_prefix.c_str());
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
	
	else if(command.at("command").get<std::string>().compare("create_conv") == 0){
		printf("%s Create conversation command\n", log_prefix.c_str());

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
	}
	
	else if(command.at("command").get<std::string>().compare("get_conv") == 0){
		printf("%s Get conversation command\n", log_prefix.c_str());

		if(command.contains("auth")){
			try{
				GetAllConversationsCommand get_conv_command(db, command.at("auth"));
				response = get_conv_command.execute();
			}
			catch(std::invalid_argument const& e){
				response = {
					{"status", 401},
					{"message", e.what()}
				};
			}
		}else{
			response = {
					{"status", 401},
					{"message", "Unauthorized! This request should have auth in payload!"}
				};
		}
	}
	
	else if(command.at("command").get<std::string>().compare("create_msg") == 0){
		printf("%s Create message command\n", log_prefix.c_str());

		if(command.contains("auth")){
			if(command.contains("id_room")){
				if(command.contains("content")){
					string reply_to = command.contains("reply_to") ? (command.at("reply_to").empty()? "NULL" : command.at("reply_to")) : "NULL";
					try{
						CreateMessageCommand create_msg_command(db, command.at("auth"), command.at("id_room"), 
																	command.at("content"), reply_to);
						response = create_msg_command.execute();
					}catch(std::domain_error const& e){
						response = {
							{"status", 401},
							{"message", e.what()}
						};
					}catch(std::invalid_argument const& e){
						response = {
							{"status", 400},
							{"message", e.what()}
						};
					}
				}else{
					response = {
						{"status", 400},
						{"message", "This request must have content field in payload!"}
					};
				}
			}else{
				response = {
					{"status", 400},
					{"message", "This request must have id_room field in payload!"}
				};
			}
		}else{
			response = {
					{"status", 401},
					{"message", "Unauthorized! This request should have auth in payload!"}
				};
		}
	}

	else if(command.at("command").get<std::string>().compare("get_msg") == 0){
		printf("%s Get messages command\n", log_prefix.c_str());

		if(command.contains("auth") && command.contains("id_room")){
			try{
				GetMessagesCommand get_messages_command(db, command.at("auth"), command.at("id_room"));
				response = get_messages_command.execute();
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
				{"message", "This request should have auth and a id_room in payload!"}
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

