#include "qadrilateral.h"
#include <iostream>

qadrilateral :: qadrilateral(int a, int b, int c, int d, int A, int B, int C, int D) : Figure(a, b, c, d, A, B, C, D) {
	name = "qadrilateral";
	this->a = a;
	this->b = b;
	this->c = c;
	this->d = d;
	this->A = a;
	this->B = b;
	this->C = C;
	this->D = D;
}
void qadrilateral :: print_info() {
	std::cout << name << std::endl << "Sides: " << "a=" << a << " b=" << b << " c=" << c << " d=" << d << std::endl;
	std::cout << "Angles: " << "A=" << A << " B=" << B << " C=" << C << " D=" << D << std::endl << std::endl;
}
