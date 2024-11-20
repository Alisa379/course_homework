#pragma once
#include <iostream>

class exceptions {
public: 
	std::string error;
	std::string name;
	exceptions(std::string name, std::string ERR);
	const char* getError();
};