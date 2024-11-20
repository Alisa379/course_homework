//В этом задании вы запретите создавать экземпляры классов геометрических фигур с неправильными данными.
//Создайте собственный класс исключения для ошибки создания геометрической фигуры.
//Подумайте, от какого типа его унаследовать, и не забудьте поместить новый класс в отдельную пару файлов.
//Возьмите иерархию классов из предыдущего задания.Теперь при создании экземпляров классов вам нужно проверять аргументы, 
//Причина ошибки должна быть сформулирована на уровне конструктора и выведена на экран при обработке ошибок.

#include <iostream>
#include "Header.h"
/*class exceptions {
public:
	std::string error;
	std::string name;
	exceptions(std::string name, std::string ERR) : error(ERR) {
		this->name = name;
	}
	const char* getError() {
		return error.c_str();
	}
};*/


class Figure {
public:
	int sides;
	std::string name;
	int a, b, c, d;
	int A, B, C, D;
	Figure(int sides) {
		this->name = "Figure";
		this->sides = sides;
	}
	Figure(int sides, int a, int b, int c, int A, int B, int C) {
		this->sides = sides;
		this->a = a;
		this->b = b;
		this->c = c;
		this->A = A;
		this->B = B;
		this->C = C;
	}
	Figure(int sides, int a, int b, int c, int d, int A, int B, int C, int D) {
		this->sides = sides;
		this->a = a;
		this->b = b;
		this->c = c;
		this->d = d;
		this->A = A;
		this->B = B;
		this->C = C;
		this->D = D;
	}
	virtual void print_info() {
		std::cout << name << " was created" << std::endl;
	}
};

class Triangle : public Figure {
public:
	Triangle(int sides, int a, int b, int c, int A, int B, int C) : Figure(sides, a, b, c, A, B, C) {
		name = "Triangle";
		if (sides != 3) {
			throw exceptions("Triangle", "The number of sides is not equal to 3");
		}
		if (A + B + C != 180) {
			throw exceptions("Triangle", "The sum of the angles is not equal to 180");
		}
	}
	void print_info() override {
		std::cout << name << " (sides: " << a << ", " << b << ", " << c << "; angles: " << A << ", " << B << ", " << C << ") was created" << std::endl;
	}
};

class rightTriangle : public Triangle {
public:
	rightTriangle(int sides, int a, int b, int c, int A, int B, int C) : Triangle(sides, a, b, c, A, B, C) {
		name = "Right triangle";
		if (C != 90) {
			throw exceptions("Right triangle", "Angle C is not equal to 90");
		}
	}
};

class isoscelesTriangle : public Triangle {
public:
	isoscelesTriangle(int sides, int a, int b, int c, int A, int B, int C) : Triangle(sides, a, b, a, A, B, A) {
		name = "Isosceles triangle";
		if (a != c || A != C) {
			throw exceptions("Isosceles triangle", "The edges of a triangle are not equal");
		}
	}
};

class equilateralTriangle : public Triangle {
public:
	equilateralTriangle(int sides, int a, int b, int c, int A, int B, int C) : Triangle(sides, a, b, c, A, B, C) {
		name = "Equilateral triangle";
		if (a != b || b != c || A != 60 || B != 60 || C != 60) {
			throw exceptions("Equilateral Triangle", "The sides of the triangle are not equal");
		}
	}
};

class qadrilateral : public Figure {
public:
	qadrilateral(int sides, int a, int b, int c, int d, int A, int B, int C, int D) : Figure(sides, a, b, a, b, A, B, C, D) {
		name = "Qadrilateral";
		if (sides != 4) {
			throw exceptions("Qadrilateral", "The number of sides is not equal to 4");
		}
		if (A + B + C + D != 360) {
			throw exceptions("Qadrilateral", "The sum of the angles is not equal to 360");
		}
	}
	void print_info() override {
		std::cout << name << " (sides: " << a << ", " << b << ", " << c << ", " << d << "; angles: " << A << ", " << B << ", " << C << ", " << D << ") was created" << std::endl;
	}
};

class square : public qadrilateral {
public:
	square(int sides, int a, int b, int c, int d, int A, int B, int C, int D) : qadrilateral(sides, a, b, c, d, A, B, C, D) {
		name = "Square";
		if (a != b || b != c || c != d) {
			throw exceptions("Square", "Sides are not equal");
		}
		if (A != 90 || B != 90 || C != 90 || D != 90) {
			throw exceptions("Square", "Corners are not straight");
		}
	}
};

class parallelogram : public qadrilateral {
public:
	parallelogram(int sides, int a, int b, int c, int d, int A, int B, int C, int D) : qadrilateral(sides, a, b, c, d, A, B, C, D) {
		name = "Parallelogram";
		if (a != c || b != d) {
			throw exceptions("Parallelogram", "Opposite sides are not equal");
		}
		if (A != C || B != D) {
			throw exceptions("Parallelogram", "Opposite angles are not equal");
		}
	}
};

class rhombus : public qadrilateral {
public:
	rhombus(int sides, int a, int b, int c, int d, int A, int B, int C, int D) : qadrilateral( sides, a, b, c, d, A, B, C, D) {
		name = "Rhombus";
		if (a != b || b != c || c != d) {
			throw exceptions("Rhombus", "Sides are not equal");
		}
		if (A != C || B != D) {
			throw exceptions("Rhombus", "Opposite angles are not equal");
		}
	}
};

class rectangle : public qadrilateral {
public:
	rectangle(int sides, int a, int b, int c, int d, int A, int B, int C, int D) : qadrilateral(sides, a, b, c, d, A, B, C, D) {
		name = "Rectangle";
		if (a != c || b != d) {
			throw exceptions("Parallelogram", "Opposite sides are not equal");
		}
		if (A != 90 || B != 90 || C != 90 || D != 90) {
			throw exceptions("Square", "Corners are not straight");
		}
	}
};


int main() {
	try 
	{
		Figure f(0);
		f.print_info();
		Triangle f1(3, 10, 20, 30, 50, 60, 70);
		f1.print_info();
		rightTriangle f2(3, 10, 20, 30, 50, 40, 90);
		f2.print_info();
		isoscelesTriangle f3(3, 10, 20, 10, 55, 70, 55);
		f3.print_info();
		equilateralTriangle f4(3, 30, 30, 30, 60, 60, 60);
		f4.print_info();
		qadrilateral f5(4, 10, 20, 30, 40, 50, 60, 70, 180);
		f5.print_info();
		square f6(4, 20, 20, 20, 20, 90, 90, 90, 90);
		f6.print_info();
		parallelogram f7(4, 20, 30, 20, 30, 30, 150, 30, 150);
		f7.print_info();
		rhombus f8(4, 30, 30, 30, 30, 80, 100, 80, 100);
		f8.print_info();
		rectangle f9(4, 10, 20, 10, 20, 90, 90, 90, 90);
		f9.print_info();
	}
	catch (exceptions& error) {
		std::cerr <<  error.name <<  " creation error. Reason: " << error.getError();
	}
}
