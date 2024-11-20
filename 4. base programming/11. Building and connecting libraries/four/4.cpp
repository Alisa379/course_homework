#include <iostream>
#include "Figure.h"
#include "Triangle.h"
#include "rightTriangle.h"
#include "isoscelesTriangle.h"
#include "equilateralTriangle.h"
#include "qadrilateral.h"
#include "square.h"
#include "parallelogram.h"
#include "rhombus.h"

int main()
{
	Triangle f1(10, 20, 30, 50, 60, 70);
	f1.print_info();
	rightTriangle f2(10, 20, 30, 50, 60, 90);
	f2.print_info();
	isoscelesTriangle f3(10, 20, 10, 50, 60, 50);
	f3.print_info();
	equilateralTriangle f4(30, 30, 30, 60, 60, 60);
	f4.print_info();
	qadrilateral f5(10, 20, 10, 20, 90, 90, 90, 90);
	f5.print_info();
	square f6(20, 20, 20, 20, 90, 90, 90, 90);
	f6.print_info();
	parallelogram f7(20, 30, 20, 30, 30, 40, 30, 40);
	f7.print_info();
	rhombus f8(30, 30, 30, 30, 30, 40, 30, 40);
	f8.print_info();
}
