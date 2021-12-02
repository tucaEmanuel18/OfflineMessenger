#include "CommandRouter.h"

CommandRouter::CommandRouter()
{
}

CommandRouter::~CommandRouter()
{
}

ICommand* CommandRouter::route(json command){
	if(command.at("command").get<std::string>().compare("register") == 0){
		printf("This is a register command!!\n");
		return new RegisterCommand(command.at("username"), command.at("password"));
	}else if(command.at("command").get<std::string>().compare("quit") == 0){
		printf("This is a quit command!!\n");
		return nullptr;
	}
	return nullptr;
}