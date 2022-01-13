#pragma once
#include <ICommand.h>
#include <string>
#include "DatabaseManager.h"
#include <sqlite3.h>
#include <sstream> 
#include <string>

using namespace std;
class LogOutCommand : ICommand
{
private:
	sqlite3* db;
	string auth;
public:
	LogOutCommand(sqlite3* db, string auth);
	~LogOutCommand();
	json execute() override;
};

