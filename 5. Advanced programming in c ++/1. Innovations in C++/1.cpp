
#include <iostream>
#include <vector>
#include <algorithm>


int main()
{
    std::vector <int> array{ 4, 7, 9, 14, 12 };
    std::cout << "Input data: ";
    std::for_each(array.begin(), array.end(), [&array](int const i) -> void {
        std:: cout << i << " ";
    });
    std::for_each(array.begin(), array.end(), [&array](int &i) -> void {
        if (i % 2 != 0) {
            i = i * 3;
        }
    });
    std::cout << std::endl << "Ouyput data: ";
    std::for_each(array.begin(), array.end(), [&array](int const i) -> void {
        std::cout << i << " ";
    });
}