
#include <iostream>

void print_dynamic_array(int* arr, int logical_size, int actual_size) {
    int k = 0;
    if (logical_size == 0) {
        std::cout << "_";
    }
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

int* remove_dynamic_array_head(int* array, int *logical_size, int *actual_size) {
    if ((*logical_size - 1) > (*actual_size / 3)) {
        for (int i = 1; i < *logical_size; ++i) {
            array[i - 1] = array[i];
        }
        --*logical_size;
        return array;
    }
    else {
        int* arr;
        arr = new int[*actual_size / 3];
        --*logical_size;
        *actual_size = *actual_size / 3;
        for (int i = 0; i < *logical_size; ++i) {
            arr[i] = array[i + 1];
        }
        delete[] array;
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
        print_dynamic_array(array, logical_size, actual_size);
        while (true) {
            std::string answer;
            std::cout << "Remove first element? ";
            std::cin >> answer;
            if (answer == "yes") {
                if (logical_size == 0) {
                    std::cout << "The first element cannot be removed because the array is empty. Goodbye!";
                    return 0;
                }
                else {
                    array = remove_dynamic_array_head(array, &logical_size, &actual_size);
                    std::cout << "Dynamic array: ";
                    print_dynamic_array(array, logical_size, actual_size);
                }
            }
            if (answer == "no") {
                std::cout << "Thank you! Your dynamic array: ";
                print_dynamic_array(array, logical_size, actual_size);
                return 0;
            }
            if (answer != "yes" && answer != "no") {
                std::cout << "Incorrect answer! Try again" << std::endl;
            }
        }
    }
}

