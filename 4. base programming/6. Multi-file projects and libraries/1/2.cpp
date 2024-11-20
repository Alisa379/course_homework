#include <iostream>
#include "1.h"

void  addition(int x, int y) {
	std::cout << x << " plus " << y << " = " << x + y;
}

void subtraction(int x, int y) {
	std::cout << x << " minus " << y << " = " << x - y;
}

void multiplication(int x, int y) {
	std::cout << x << " multiply " << y << " = " << x * y;
}

void division(int x, int y) {
	std::cout << x << " devise " << y << " = " << x / y;
}
void exponentiation(int x, int y) {
	std::cout << x << " exponentiate " << y << " = " << pow(x, y);
}


