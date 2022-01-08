#pragma once
#include <ICommand.h>
#include <string>
#include "DatabaseManager.h"
#include <sqlite3.h>
#include <sstream> 

using namespace std;
class CreateMessageCommand: public ICommand
{
private:
	sqlite3* db;
	string auth;
	string id_room;
	string content;
	string reply_to;
public:
	CreateMessageCommand(sqlite3* db, string auth, string id_room, string content, string reply_to);
	~CreateMessageCommand();
	json execute() override;
};

