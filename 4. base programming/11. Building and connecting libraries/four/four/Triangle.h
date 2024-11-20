#pragma once
#include "Figure.h"

LIBRARY_API class Triangle : public Figure {
public:
	Triangle(int a, int b, int c, int A, int B, int C);
	void print_info();
};