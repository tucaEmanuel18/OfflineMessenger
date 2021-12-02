#pragma once
#include <ICommand.h>
#include <string>

using namespace std;
class RegisterCommand : public ICommand
{
private:
	string username;
	string password;
public:
	RegisterCommand(string username, string password);
	~RegisterCommand();
	json execute() override;
};