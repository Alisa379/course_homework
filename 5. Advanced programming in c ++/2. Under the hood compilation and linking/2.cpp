
#include <iostream>
#include "Header.h"  // ошибка линковки - файла не существует, нужно убрать строчку

integer main()       // синтаксическая ошибка - int main()
{
    int x = 6, y = 4;
    if(!(x > y)) {                      // семантическая ошибка - x > y
        cout << "x is grater than y" << endl;   // ошибка линковки - std::cout, std::endl
    }
    std::cout << "Hello World!\n";
}

