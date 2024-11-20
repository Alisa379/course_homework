

#include <iostream>
#include <variant>
#include <vector>

std::variant<int, std::string, std::vector<int>> get_variant() {
	std::srand(std::time(nullptr));
	int random_variable = std::rand() % 3;

	std::variant<int, std::string, std::vector<int>> result;
	switch (random_variable)
	{
	case 0:
		result = 5;
		break;
	case 1:
		result = "string";
		break;
	case 2:
		result = std::vector<int>{ 1, 2, 3, 4, 5 };
		break;
	default:
		break;
	}
	return result;
}

int main()
{
	auto i = get_variant();
	switch (i.index()) {
	case 0:
		std::cout << std::get<int>(i) * 2;
		break;
	case 1:
		std::cout << std::get<std::string>(i);
		break;
	case 2:
		for (int item : std::get<std::vector<int>>(i)) {
			std::cout << item << " ";
		}
		break;
	}
}
