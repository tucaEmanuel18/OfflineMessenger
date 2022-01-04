#pragma once
#include <nlohmann/json.hpp>
#include <RegisterCommand.h>
#include <LogInCommand.h>
#include <sqlite3.h>

using json = nlohmann::json;
class CommandProcessor
{
private:
	sqlite3 * db;
public:
	CommandProcessor(sqlite3* db);
	~CommandProcessor();
	json process(json command);
};