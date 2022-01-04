#pragma once
#include <ICommand.h>
#include <string>
#include "DatabaseManager.h"
#include <sqlite3.h>
#include <sstream>      

using namespace std;
class RegisterCommand : public ICommand
{
private:
	sqlite3* db;
	string username;
	string password;
public:
	RegisterCommand(sqlite3* db, string username, string password);
	~RegisterCommand();
	json execute() override;
};