
#include <iostream>

struct point {
	int m_x, m_y;
	point(int x, int y) {
		m_x = x;
		m_y = y;
	}
};

void print_point(const point& point_object) {
	std::cout << "x:" << point_object.m_x << ", y: " << point_object.m_y << std::endl;
}

int main()
{
	for (int i = 0; i < 5; i++) {
		point my_point(i, 2 * i);
		print_point(my_point);
	}
	return 0;
}

