
#include <iostream>
#include <string>

int function(std::string str, int forbidden_length) {
    if (str.length() != forbidden_length) {
        return str.length();
    }
    throw std::exception();
}

int main()
{
    int length;
    std::string string;
    std::cout << "Input forbidden length: ";
    std::cin >> length;
    while (true)  {
        std::cout << "Input a word: ";
        std::cin >> string;
        try {
            int l = function(string, length);
            std::cout << "The length of word \"" << string << "\"" << " equels " << l << std::endl;
        }
        catch (const std::exception&) {
            std::cout << "You inputted forbidden length word! Goodbye";
            return 0;
        }
    }
    
}

