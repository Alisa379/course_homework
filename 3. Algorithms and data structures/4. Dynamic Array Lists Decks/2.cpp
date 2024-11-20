#include <iostream>

void print_dynamic_array(int* arr, int logical_size, int actual_size) {
    int k = 0;
    for (int i = 0; i < actual_size; i++) {
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

int* append_to_dynamic_array(int *arr, int *logical_size, int *actual_size, int item) {
    if (*logical_size > *actual_size) {
        int* array;
        array = new int[(*actual_size) * 2];
        for (int i = 0; i < (*logical_size - 1); i++) {
            array[i] = arr[i];
        }
        *actual_size = *actual_size * 2;
        array[*logical_size - 1] = item;
        delete[] arr;
        return array;
    }
    else  {
        arr[*logical_size - 1] = item;
        return arr;
    }
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
        while (true) {
            print_dynamic_array(array, logical_size, actual_size);
            std::cout << "Enter the item to add: ";
            int i;
            std::cin >> i;
            if (i == 0) {
                std::cout << "Thanks! Your array is: ";
                print_dynamic_array(array, logical_size, actual_size);
                return 0;
            }
            else {
                ++logical_size;
                array = append_to_dynamic_array(array, &logical_size, &actual_size, i);
            }
        }
    }
}