
#include <iostream>

void print_dynamic_array(int* arr, int logical_size, int actual_size) {
    int k = 0;
    for (int i = 0; i < actual_size; ++i) {
        if (k < logical_size) {
            std::cout << arr[k] << "\t";
            k++;
        }
        else {
            std::cout << "_" << "\t";
        }
    }
    std::cout << std::endl;
}

int main()
{
    int logical_size, actual_size;
    std::cout << "Enter the actual size of the array: ";
    std::cin >> actual_size;
    std::cout << "Enter the logical size of the array: ";
    std::cin >> logical_size;
    if (logical_size > actual_size) {
        std::cout << "Error! The logical size of an array cannot exceed the actual size!\n";
        return 0;
    }
    else {
        int* array;
        array = new int[logical_size];
        for (int i = 0; i < logical_size; ++i) {
            std::cout << "Enter arr[" << i << "]: ";
            std::cin >> array[i];
        }
        print_dynamic_array(array, logical_size, actual_size);
    }
}

