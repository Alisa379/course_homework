#include "Header.h"
#include <iostream>

const char* exceptions::getError() {
	return error.c_str();
}

exceptions::exceptions(std::string name, std::string ERR) : error(ERR) {
	this->name = name;
}