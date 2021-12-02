#pragma once
#include "ICommand.h"
#include <nlohmann/json.hpp>
#include <iostream>

using namespace std;
using json = nlohmann::json;

class RegisterCommand : ICommand
{
private:
	string username;
	string password;
public:
	RegisterCommand(string username, string password);
	RegisterCommand();
	~RegisterCommand();
	string create() override;
};

