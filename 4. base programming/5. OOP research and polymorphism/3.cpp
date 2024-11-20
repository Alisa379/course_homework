
//Задача: спроектировать и реализовать классы, описывающие предметную область. 
//Продемонстрируйте их работу: создайте по одному экземпляру каждой фигуры и выведите на экран информацию о длинах её сторон и величине её углов. 
//Значения используйте произвольные.

#include <iostream>

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
	virtual void check() {
		if (sides==0) {
			std::cout << "right" << std::endl;
		}
		else {
			std::cout << "wrong" << std::endl;
		}
	}
	virtual void print_info() {
		std::cout << name << std::endl;
		check();
		std::cout << "Amount of sides: " << sides << std::endl << std::endl;
	}
};

class Triangle : public Figure {
public:
	Triangle(int sides, int a, int b, int c, int A, int B, int C) : Figure(sides, a, b, c, A, B, C) {
		name = "Triangle";
	}
	void check() override {
		if (sides == 3 && A + B + C == 180) {
			std::cout << "right" << std::endl;
		}
		else {
			std::cout << "wrong" << std::endl;
		}
	}
	 void print_info() override {
		std::cout << name << std::endl;
		check();
		std::cout << "Amount of sides: " << sides << std::endl;
		std::cout << "Sides: " << "a=" << a << " b=" << b << " c=" << c << std::endl;
		std::cout << "Angles: " << "A=" << A << " B=" << B << " C=" << C << std::endl << std::endl;
	}
};

class rightTriangle : public Triangle {
public:
	rightTriangle(int sides, int a, int b, int c, int A, int B, int C) : Triangle(sides, a, b, c, A, B, C) {
		name = "rightTriangle";
	}
	void check() override {
		if (C==90) {
			Triangle::check();
		}
		else {
			std::cout << "wrong" << std::endl;
		}
	}
};

class isoscelesTriangle : public Triangle {
public:
	isoscelesTriangle(int sides, int a, int b, int c, int A, int B, int C) : Triangle(sides, a, b, a, A, B, A) {
		name = "isoscelesTriangle";
	}
	void check() override {
		if (a == c && A == C) {
			Triangle::check();
		}
		else {
			std::cout << "wrong" << std::endl;
		}
	}
};

class equilateralTriangle : public Triangle {
public:
	equilateralTriangle(int sides, int a, int b, int c, int A, int B, int C) : Triangle(sides, a, b, c, A, B, C) {
		name = "equilateralTriangle";
	}
	void check() override {
		if (a == b && b == c && A == 60 && B == 60 && C == 60) {
			Triangle::check();
		}
		else {
			std::cout << "wrong" << std::endl;
		}
	}
};

class qadrilateral : public Figure {
public:
	qadrilateral(int sides, int a, int b, int c, int d, int A, int B, int C, int D) : Figure (sides, a, b, a, b, A, B, C, D) {
		name = "qadrilateral";
	}
	void check() override {
		if (sides == 4 && A + B + C + D == 360) {
			std::cout << "right" << std::endl;
		}
		else {
			std::cout << "wrong" << std::endl;
		}
	}
	void print_info() override {
		std::cout << name << std::endl;
		check();
		std::cout << "Amount of sides: " << sides << std::endl;
		std::cout << "Sides: " << "a=" << a << " b=" << b << " c=" << c << " d=" << d << std::endl;
		std::cout << "Angles: " << "A=" << A << " B=" << B << " C=" << C << " D=" << D << std::endl << std::endl;
	}
};

class square : public qadrilateral {
public:
	square(int sides, int a, int b, int c, int d, int A, int B, int C, int D) : qadrilateral(sides, a, b, c, d, A, B, C, D) {
		name = "square";
	}
	void check() override {
		if (a == b && b == c && c == d && A == 90 && B == 90 && C == 90 && D == 90) {
			qadrilateral::check();
		}
		else {
			std::cout << "wrong" << std::endl;
		}
	}
};

class parallelogram : public qadrilateral {
public:
	parallelogram(int sides, int a, int b, int c, int d, int A, int B, int C, int D) : qadrilateral(sides, a, b, c, d, A, B, C, D) {
		name = "parallelogram";
	}
	void check() override {
		if (a == c && b == d && A == C && B == D) {
			qadrilateral::check();
		}
		else {
			std::cout << "wrong" << std::endl;
		}
	}
};

class rhombus : public qadrilateral {
public:
	rhombus(int sides, int a, int b, int c, int d, int A, int B, int C, int D) : qadrilateral(sides, a, b, c, d, A, B, C, D) {
		name = "rhombus";
	}
	void check() override {
		if (a == b && b == c && c == d && A == C && B == D) {
			qadrilateral::check();
		}
		else {
			std::cout << "wrong" << std::endl;
		}
	}
};

class rectangle : public qadrilateral {
public:
	rectangle(int sides, int a, int b, int c, int d, int A, int B, int C, int D) : qadrilateral(sides, a, b, c, d, A, B, C, D) {
		name = "rectangle";
	}
	void check() override {
		if (a == c && b == d && A == 90 && B == 90 && C == 90 && D == 90) {
			qadrilateral::check();
		}
		else {
			std::cout << "wrong" << std::endl;
		}
	}
};

int main() {
	Figure f(0);
	f.print_info();
	Triangle f1(3, 10, 20, 30, 50, 60, 70);
	f1.print_info();
	rightTriangle f2(3, 10, 20, 30, 50, 60, 90);
	f2.print_info();
	rightTriangle f22(3, 10, 20, 30, 50, 40, 90);
	f22.print_info();
	isoscelesTriangle f3(3, 10, 20, 10, 50, 60, 50);
	f3.print_info();
	equilateralTriangle f4(3, 30, 30, 30, 60, 60, 60);
	f4.print_info();
	qadrilateral f5(4, 10, 20, 30, 40, 50, 60, 70, 80);
	f5.print_info();
	square f6(4, 20, 20, 20, 20, 90, 90, 90, 90);
	f6.print_info();
	parallelogram f7(4, 20, 30, 20, 30, 30, 40, 30, 40);
	f7.print_info();
	rhombus f8(4, 30, 30, 30, 30, 30, 40, 30, 40);
	f8.print_info();
	rectangle f9(4, 10, 20, 10, 20, 90, 90, 90, 90);
	f9.print_info();
}
