#pragma once
#include <ICommand.h>
#include <string>
#include "DatabaseManager.h"
#include <sqlite3.h>
#include <sstream>

using namespace std;

class GetAllConversationsCommand: public ICommand
{
private:
	sqlite3* db;
	string id;
public:
	GetAllConversationsCommand(sqlite3* db, string auth);
	~GetAllConversationsCommand();
	json execute() override;
};


