#pragma once
#include <ICommand.h>
#include <string>
#include "DatabaseManager.h"
#include <sqlite3.h>
#include <sstream> 

using namespace std;

class GetMessagesCommand : public ICommand
{
private:
	sqlite3* db;
	string auth;
	string id_room;
public:
	GetMessagesCommand(sqlite3* db, string auth, string id_room);
	~GetMessagesCommand();
	json execute() override;
};

