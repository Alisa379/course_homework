#include "Triangle.h"
#include <iostream>

Triangle :: Triangle(int a, int b, int c, int A, int B, int C) : Figure(a, b, c, A, B, C) {
	name = "Triangle";
	this->a = a;
	this->b = b;
	this->c = c;
	this->A = a;
	this->B = b;
	this->C = C;
}
void Triangle :: print_info() {
	std::cout << name << std::endl << "Sides: " << "a=" << a << " b=" << b << " c=" << c << std::endl;
	std::cout << "Angles: " << "A=" << A << " B=" << B << " C=" << C << std::endl << std::endl;
}