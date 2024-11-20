#define _USE_MATH_DEFINES
#include"shape.h"
#include<cmath>


Line::Line(int _x1, int _x2, int _y1, int _y2) : x1(_x1), x2(_x2), y1(_y1), y2(_y2) {
	setSquare();
	setVolume();
}
void Line::setSquare() {
	square = 0;
}
void Line::setVolume() {
	volume = 0;
}


Sqr::Sqr(int _x1, int _x2, int _x3, int _y1, int _y2, int _y3) : x1(_x1), x2(_x2), y1(_y1), y2(_y2), x3(_x3), y3(_y3) {
	a = abs(x1 - x2);
	setSquare();
	setVolume();
}
void Sqr::setSquare() {
	square = pow(a, 2);
}
void Sqr::setVolume() {
	volume = 0;
}


Cube::Cube(int _x1, int _y1, int _z1, int _x2, int _y2, int _z2, int _x3, int _y3, int _z3, int _x4, int _y4, int _z4) 
	: x1(_x1), x2(_x2), y1(_y1), y2(_y2), x3(_x3), x4(_x4), y3(_y3), y4(_y4), z1(_z1), z2(_z2), z3(_z3), z4(_z4) {
	a = abs(x1 - x2);
	setSquare();
	setVolume();
}
void Cube::setSquare() {
	square = pow(a, 2) * 6;
}
void Cube::setVolume() {
	volume = pow(a, 3);
}


Circle::Circle(int _x1, int _y1, double _radius) : x1(_x1), y1(_y1), radius(_radius) {
	setSquare();
	setVolume();
}
void Circle::setSquare() {
	square = M_PI * pow(radius, 2);
}
void Circle::setVolume() {
	volume = 0;
}

Cylinder::Cylinder(int _x1, int _y1, double _radius, double _height) : x1(_x1), y1(_y1), radius(_radius), height(_height) {
	setSquare();
	setVolume();
}
void Cylinder::setSquare() {
	square = 2 * M_PI * radius * (height + radius);
}
void Cylinder::setVolume() {
	volume = M_PI * pow(radius, 2) * height;
}

void Line::shift(Line& shape, int m, int n) {
	shape.x1 += m; shape.y1 += n;
	shape.x2 += m; shape.y2 += n;
}
void Sqr::shift(Sqr& shape, int m, int n) {
	shape.x1 += m; shape.y1 += n;
	shape.x2 += m; shape.y2 += n;
	shape.x3 += m; shape.y3 += n;
}
void Cube::shift(Cube& shape, int m, int n, int k) {
	shape.x1 += m; shape.y1 += n; shape.z1 += k;
	shape.x2 += m; shape.y2 += n; shape.z2 += k;
	shape.x3 += m; shape.y3 += n; shape.z3 += k;
	shape.x4 += m; shape.y4 += n; shape.z4 += k;
}
void Line::scaleX(Line& shape, int a) {
	shape.x1 *= a;
	shape.x2 *= a;
}
void Sqr::scaleX(Sqr& shape, int a) {
	shape.x1 *= a;
	shape.x2 *= a;
	shape.x3 *= a;
}
void Cube::scaleX(Cube& shape, int a) {
	shape.x1 *= a;
	shape.x2 *= a;
	shape.x3 *= a;
	shape.x4 *= a;
}
void Line::scaleY(Line& shape, int d) {
	shape.y1 *= d;
	shape.y2 *= d;
}
void Sqr::scaleY(Sqr& shape, int d) {
	shape.y1 *= d;
	shape.y2 *= d;
	shape.y3 *= d;
}
void Cube::scaleY(Cube& shape, int d) {
	shape.y1 *= d;
	shape.y2 *= d;
	shape.y3 *= d;
	shape.y4 *= d;
}
void Cube::scaleZ(Cube& shape, int e) {
	shape.z1 *= e;
	shape.y2 *= e;
	shape.z3 *= e;
	shape.z4 *= e;
}
void Line::scale(Line& shape, int s) {
	shape.x1 /= s; shape.y1 /= s;
	shape.x2 /= s; shape.y2 /= s;
}
void Sqr::scale(Sqr& shape, int s) {
	shape.x1 /= s; shape.y1 /= s;
	shape.x2 /= s; shape.y2 /= s;
	shape.x3 /= s; shape.y3 /= s;
}
void Cube::scale(Cube& shape, int s) {
	shape.x1 /= s; shape.y1 /= s; shape.z1 /= s;
	shape.x2 /= s; shape.y2 /= s; shape.z2 /= s;
	shape.x3 /= s; shape.y3 /= s; shape.z3 /= s;
	shape.x4 /= s; shape.y4 /= s; shape.z4 /= s;
}