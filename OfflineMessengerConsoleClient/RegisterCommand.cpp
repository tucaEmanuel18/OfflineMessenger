#include "RegisterCommand.h"

RegisterCommand::RegisterCommand()
{
	printf("Get a username for the new account: ");
	fflush(stdout);
	getline (cin, this->username);
	printf("\nUsername = %s\n", username.c_str());
	
	printf("Choose a password for the new account: ");
	getline (cin, this->password);
	printf("\nPassword = %s\n", password.c_str());
}

RegisterCommand::~RegisterCommand()
{
}

string RegisterCommand::create(){
	json j;
	j["command"] = "register";
	j["username"] = this->username;
	j["password"] = this->password;
	
	return j.dump().c_str();
}

