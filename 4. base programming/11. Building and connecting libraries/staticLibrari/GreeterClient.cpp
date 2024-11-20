#include <iostream>
#include <Header.h>
#include <string>

int main()
{
    std::string s;
    std::cout << "Insert your name: ";
    std::cin >> s;
    Greeter c;
    std::cout << c.greet(s) << std::endl;
}

