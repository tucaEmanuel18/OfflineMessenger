#pragma once
#include <nlohmann/json.hpp>

using json = nlohmann::json;
class ICommand
{
public:
	ICommand(){}
	virtual ~ICommand(){}
	virtual json execute() = 0;
};

