#pragma once
#include <ICommand.h>
#include <string>
#include "DatabaseManager.h"
#include <sqlite3.h>
#include <sstream> 

using namespace std;
class CreateConversationCommand: public ICommand
{
private:
	sqlite3* db;
	string my_id;
	string friend_username;
public:
	CreateConversationCommand(sqlite3* db, string my_id, string friend_username);
	~CreateConversationCommand();
	json execute() override;
};

