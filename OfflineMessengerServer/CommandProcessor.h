#pragma once
#include <nlohmann/json.hpp>
#include <RegisterCommand.h>
#include <LogInCommand.h>
#include <CreateConversationCommand.h>
#include <GetAllConversationsCommand.h>
#include <CreateMessageCommand.h>
#include <GetMessagesCommand.h>
#include <sqlite3.h>
#include <string>

using json = nlohmann::json;
using namespace std;
class CommandProcessor
{
private:
	sqlite3 * db;
	string log_prefix;
public:
	CommandProcessor(sqlite3* db);
	CommandProcessor(sqlite3* db, string log_prefix);
	~CommandProcessor();
	json process(json command);
};