
#include <iostream>
#include <functional>
#include <vector>

int main()
{
	std::function<void(float)> sin = [](int angle) {};
	std::vector <float> angles;
	std::vector <>  functions;
	for (const auto& angle : angles) {
		std::cout << angle << ": ";
		for (const auto& function : functions)
			function(angle);
		std::cout << std::endl;
	}
}

