#pragma once
#include <map>
#include <nlohmann/json.hpp>
#include "ICommand.h"
#include "RegisterCommand.h"
#include <string.h>

using json = nlohmann::json;
class CommandRouter
{
public:
	CommandRouter();
	~CommandRouter();
	ICommand* route(json command);
};

