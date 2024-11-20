
#include <iostream>
#include "Header.h"

int main()
{
    std::string s;
    std::cout << "Insert your name: ";
    std::cin >> s;
    Leaver c;
    std::cout << c.leave(s) << std::endl;
}
