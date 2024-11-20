
#include <iostream>

void print_pyramid(int size, int array[]) {
    int floor = 0;
    std::cout << "Source array: ";
    for (int i = 0; i < size; ++i) {
        std::cout << array[i] << " ";
    }
    std::cout << "\n" << "Pyramid:" << std::endl;
    for (int i = 0; i < size; ++i) {
        if (i == 0) {
            std::cout << floor << " root " << array[i] << std::endl;
            floor++;
            continue;
        }
        if (i % 2 != 0) {
            std::cout << floor << " left(" << array[(i - 1) / 2] << ") " << array[i] << std::endl;
        }
        else {
            std::cout << floor << " right(" << array[(i - 2) / 2] << ") " << array[i] << std::endl;
            if (i + 2 >= pow(2, floor + 1)) {
                floor++;
            }
        }
    }
    std::cout << "\n" << std::endl;
}

int main()
{
    int arr1[] = {1, 3, 6, 5, 9, 8};
    int arr2[] = {94, 67, 18, 44, 55, 12, 6, 42};
    int arr3[] = {16, 11, 9, 10, 5, 6, 8, 1, 2, 4};
    print_pyramid(sizeof(arr1)/4, arr1);
    print_pyramid(sizeof(arr2) / 4, arr2);
    print_pyramid(sizeof(arr3) / 4, arr3);
}

