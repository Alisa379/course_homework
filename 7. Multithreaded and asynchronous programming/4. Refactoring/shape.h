#pragma once
class Shape
{
public:
	Shape() = default;
};

class Line : public Shape {
public:
	int x1 = 0, y1 = 0,
		x2 = 0, y2 = 0;
	double volume;
	double square;
	Line(int _x1, int _x2, int _y1, int _y2);
	void setSquare();
	void setVolume();
	void shift(Line& shape, int m, int n);
	void scaleX(Line& shape, int a);
	void scaleY(Line& shape, int d);
	void scale(Line& shape, int s);
};

class Sqr : public Shape {
public:
	int x1 = 0, y1 = 0,
		x2 = 0, y2 = 0,
		x3 = 0, y3 = 0;
	double volume;
	double square;
	int a;
	Sqr(int _x1, int _x2, int _x3, int _y1, int _y2, int _y3);
	void setSquare();
	void setVolume();
	void shift(Sqr& shape, int m, int n);
	void scaleX(Sqr& shape, int a);
	void scaleY(Sqr& shape, int d);
	void scale(Sqr& shape, int s);
};

class Cube : public Shape {
public:
	int x1 = 0, y1 = 0, z1 = 0,
		x2 = 0, y2 = 0, z2 = 0,
		x3 = 0, y3 = 0, z3 = 0,
		x4 = 0, y4 = 0, z4 = 0;
	double volume;
	double square;
	int a;
	Cube(int _x1, int _y1, int _z1, int _x2, int _y2, int _z2, int _x3, int _y3, int _z3, int _x4, int _y4, int _z4);
	void setSquare();
	void setVolume();
	void shift(Cube& shape, int m, int n, int k);
	void scaleX(Cube& shape, int a);
	void scaleY(Cube& shape, int d);
	void scaleZ(Cube& shape, int e);
	void scale(Cube& shape, int s);
};

class Circle : public Shape {
public:
	int x1 = 0, y1 = 0;
	double volume;
	double square;
	double radius;
	Circle(int _x1, int _y1, double _radius);
	void setSquare();
	void setVolume();
};

class Cylinder : public Shape {
public:
	int x1 = 0, y1 = 0;
	double volume;
	double square;
	double height;
	double radius;
	Cylinder(int _x1, int _y1, double _radius, double height);
	void setSquare();
	void setVolume();
};