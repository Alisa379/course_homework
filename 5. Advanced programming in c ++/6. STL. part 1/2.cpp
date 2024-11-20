

#include <iostream>
#include <set>
#include <vector>

int main()
{
	std::set<int, std::greater<int>> s;
	int amount;
	std::cout << "[IN]:" << std::endl;
	std::cin >> amount;
	for (int i = 0; i < amount; ++i) {
		int it;
		std::cin >> it;
		s.insert(it);
	}
	std::cout << "[OUT]:" << std::endl;
	for (auto it : s) {
		std::cout << it << std::endl;
	}
}
