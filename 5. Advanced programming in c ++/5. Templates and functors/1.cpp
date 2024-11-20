
#include <iostream>
#include <vector>

template <class T> 
void square(T& var) {
    var = var * var;
};

template <class T> 
void square(std::vector<T>& vec) {
    for (auto i = vec.begin(); i != vec.end(); ++i) {
        *i = *i * *i;
    }
};
  
int main()
{
    int a = 9;
    std::vector <double> vector = { -1, 4, 8 };
    square(vector);
    square(a);
    std::cout << a << std::endl;
    for (const auto i : vector) {
        std::cout << i << " ";
    }
}