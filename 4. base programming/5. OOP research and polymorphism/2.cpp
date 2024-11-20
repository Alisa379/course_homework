
//Задача: спроектировать и реализовать классы, описывающие предметную область. 
//Продемонстрируйте их работу: создайте по одному экземпляру каждой фигуры и выведите на экран информацию о длинах её сторон и величине её углов. 
//Значения используйте произвольные.

#include <iostream>

class Figure {
public:
	std::string name;
	int a, b, c, d;
	int A, B, C, D;
public:
	virtual void print_info() {
		
	}
};

class Triangle : public Figure {
public:
	Triangle(int a, int b, int c, int A, int B, int C) {
		this->a = a;
		this->b = b;
		this->c = c;
		this->A = A;
		this->B = B;
		this->C = C;
		name = "Triangle";
	}
	void print_info() override {
		std::cout << name << std::endl << "Sides: " << "a=" << a << " b=" << b << " c=" << c << std::endl;
		std::cout << "Angles: " << "A=" << A << " B=" << B << " C=" << C << std::endl << std::endl;
	}
};

class rightTriangle : public Triangle {
public:
	rightTriangle(int a, int b, int c, int A, int B, int C) : Triangle(a, b, c, A, B, 90) {
		name = "rightTriangle";
	}
};

class isoscelesTriangle : public Triangle {
public:
	isoscelesTriangle(int a, int b, int c, int A, int B, int C) : Triangle(a, b, a, A, B, A) {
		name = "isoscelesTriangle";
	}
};

class equilateralTriangle : public Triangle {
public:
	equilateralTriangle(int a, int b, int c, int A, int B, int C) : Triangle(a, a, a, 60, 60, 60) {
		name = "equilateralTriangle";
	}
};

class qadrilateral : public Figure {
public:
	qadrilateral(int a, int b, int c, int d, int A, int B, int C, int D) {
		this->a = a;
		this->b = b;
		this->c = c;
		this->d = d;
		this->A = A;
		this->B = B;
		this->C = C;
		this->D = D;
		name = "qadrilateral";
	}
	void print_info() override {
		std::cout << name << std::endl << "Sides: " << "a=" << a << " b=" << b << " c=" << c << " d=" << d << std::endl;
		std::cout << "Angles: " << "A=" << A << " B=" << B << " C=" << C << " D=" << D << std::endl << std::endl;
	}
};

class square : public qadrilateral {
public:
	square(int a, int b, int c, int d, int A, int B, int C, int D) : qadrilateral(a, a, a, a, 90, 90, 90, 90) {
		name = "square";
	}
};

class parallelogram : public qadrilateral {
public:
	parallelogram(int a, int b, int c, int d, int A, int B, int C, int D) : qadrilateral(a, b, a, b, A, B, A, B) {
		name = "parallelogram";
	}
};

class rhombus : public qadrilateral {
public:
	rhombus(int a, int b, int c, int d, int A, int B, int C, int D) : qadrilateral(a, a, a, a, A, B, A, B) {
		name = "rhombus";
	}
};

void print_info(Figure* a) {
	a->print_info();
}


int main() {
	Triangle f1(10, 20, 30, 50, 60, 70);
	print_info(&f1);
	rightTriangle f2(10, 20, 30, 50, 60, 90);
	print_info(&f2);
	isoscelesTriangle f3(10, 20, 10, 50, 60, 50);
	print_info(&f3);
	equilateralTriangle f4(30, 30, 30, 60, 60, 60);
	print_info(&f4);
	qadrilateral f5(10, 20, 10, 20, 90, 90, 90, 90);
	print_info(&f5);
	square f6(20, 20, 20, 20, 90, 90, 90, 90);
	print_info(&f6);
	parallelogram f7(20, 30, 20, 30, 30, 40, 30, 40);
	print_info(&f7);
	rhombus f8(30, 30, 30, 30, 30, 40, 30, 40);
	f8.print_info();
	print_info(&f8);
}
