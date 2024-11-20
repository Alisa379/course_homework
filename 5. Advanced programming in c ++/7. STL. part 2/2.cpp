
#include <iostream>
#include <vector>
#include <list>
#include <set>
#include <algorithm>

template<typename T>
void print(T a) {
    std::for_each(a.begin(), a.end(), [](auto el) { std::cout << el << ", "; });
    std::cout << std::endl;
}

int main()
{
    std::set<std::string> test_set = { "one", "two", "three", "four" };
    std::list<std::string> test_list = { "one", "two", "three", "four" };
    std::vector<std::string> test_vector = { "one", "two", "three", "four" };
    print(test_set);
    print(test_list);
    print(test_vector);
}

