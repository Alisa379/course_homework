// В этом задании вы вынесете математические функции в отдельный файл.

// Даны следующие математически функции : сложение, вычитание, умножение, деление, возведение в степень.

// Вам нужно разместить их в отдельном файле исходного кода и воспользоваться ими из функции main.

// Попросите пользователя ввести два числа и выбрать операцию.Выведите результат ему на консоль.

#include <iostream>
#include "1.h"

int main() {
	int x, y, n;
	std::cout << "Insert the first number: ";
	std::cin >> x;
	std::cout << std::endl << "Insert the second number: ";
	std::cin >> y;
	std::cout << "Choose the operation (1 - addition, 2 - subtraction, 3 - multiplication, 4 - division, 5 - exponentiation)" << std::endl;
	std::cin >> n;
	switch(n) {
	case 1:
		addition(x, y);
		break;
	case 2:
		subtraction(x, y);
		break;
	case 3:
		multiplication(x, y);
		break;
	case 4:
		division(x, y);
		break;
	case 5:
		exponentiation(x, y);
		break;
	}
	
}