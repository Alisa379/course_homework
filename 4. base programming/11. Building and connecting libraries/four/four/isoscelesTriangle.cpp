#include "isoscelesTriangle.h"

isoscelesTriangle::isoscelesTriangle(int a, int b, int c, int A, int B, int C) : Triangle(a, b, c, A, B, C) {
	name = "isoscelesTriangle";
	this->a = a;
	this->b = b;
	this->c = c;
	this->A = a;
	this->B = b;
	this->C = C;
}
