#include "rhombus.h"

rhombus	:: rhombus(int a, int b, int c, int d, int A, int B, int C, int D) : qadrilateral(a, b, c, d, A, B, C, D) {
		name = "rhombus";
		this->a = a;
		this->b = b;
		this->c = c;
		this->d = d;
		this->A = a;
		this->B = b;
		this->C = C;
		this->D = D;
}
