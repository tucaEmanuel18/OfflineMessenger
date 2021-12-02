#include "RegisterCommand.h"

RegisterCommand::RegisterCommand(string username, string password)
{
	this->username = username;
	this->password = password;
}

RegisterCommand::~RegisterCommand()
{
}

json RegisterCommand::execute(){
	printf("Register user with username: %s | password = %s\n", this->username.c_str(), this->password.c_str());
	json response = {
			{"status", 201},
			{"message", "User was registered"}
		};
	return response;
	
}
