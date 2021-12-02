#pragma once
#include <nlohmann/json.hpp>
#include <RegisterCommand.h>
using json = nlohmann::json;
class CommandProcessor
{
public:
	CommandProcessor();
	~CommandProcessor();
	json process(json command);
};

