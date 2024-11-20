
#include <iostream>
#include "class.h"

int main() {
	int a = 1;
	bool x = 0;
	std::string answer;
	char command;
	std::cout << "You want to set  counter's initual value? Input yes or no: ";
	std::cin >> answer;
	if (answer == "yes") {
		std::cout << "Input counter's initual value: ";
		std::cin >> a;
	}
	Counter num(a);
	do {
		std::cout << "Insert the command ('+', '-', '=' or 'x'): ";
		std::cin >> command;
		if (command == '+') {
			num.increment();
		}
		if (command == '-') {
			num.decrement();
		}
		if (command == '=') {
			std::cout << num.rt() << std::endl;
		}
		if (command == 'x') {
			x = 1;
		}
	} while (x == 0);
	std::cout << "Goodbye!";
}