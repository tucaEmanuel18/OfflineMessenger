#pragma once
#include <ICommand.h>
#include <string>
#include "DatabaseManager.h"
#include <sqlite3.h>
#include <sstream> 

using namespace std;

class LogInCommand : public ICommand
{
private:
	sqlite3* db;
	string username;
	string password;
public:
	LogInCommand(sqlite3* db, string username, string password);
	~LogInCommand();
	json execute() override;
};

