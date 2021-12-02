#pragma once
#include <string>

using namespace std;
class ICommand
{
public:
	virtual string create() = 0;
};

