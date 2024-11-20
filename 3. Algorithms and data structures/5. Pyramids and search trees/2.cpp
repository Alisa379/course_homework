
#include <iostream>
#include <string>

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
}

void up(int &floor, std::string &entity, int &i) {
    if (floor != 0) {
        std::cout << "Ok" << std::endl;
        floor--;
        if (entity == "left") {
            i = (i - 1) / 2;
        }
        if (entity == "right") {
            i = (i - 2) / 2;
        }
        if (i == 0) {
            entity = "root";
        }
        if (i % 2 != 0 && i != 0) {
            entity = "left";
        }
        if (i % 2 == 0 && i != 0) {
            entity = "right";
        }
    }
    else {
        std::cout << "Error! Parent is absent" << std::endl;
    }
}
void left(int& floor, std::string& entity, int &i, int size) {
    if ((i * 2 + 1) < size) {
        std::cout << "Ok" << std::endl;
        floor++;
        entity = "left";
        i = i * 2 + 1;
    }
    else {
        std::cout << "Error! Left descendant is absent" << std::endl;
    }
}

void right(int& floor, std::string& entity, int &i, int size) {
    if ((i * 2 + 2) < size) {
        std::cout << "Ok" << std::endl;
        floor++;
        entity = "right";
        i = i * 2 + 2;
    }
    else {
        std::cout << "Error! Right descendant is absent" << std::endl;
    }
}

int main()
{
    int arr1[] = { 1, 3, 6, 5, 9, 8 };
    int arr2[] = { 94, 67, 18, 44, 55, 12, 6, 42 };
    int arr3[] = { 16, 11, 9, 10, 5, 6, 8, 1, 2, 4 };
    int floor = 0, i = 0;
    std::string entity = "root";
    print_pyramid(sizeof(arr1) / 4, arr1);
    while (true) {
        std::string command;
        if (floor == 0) {
            std::cout << "You are here: " << floor << " " << entity << " " << arr1[i] << "\n" << "Enter the command: ";
        }
        if (floor != 0) {
            if (i % 2 != 0) {
                std::cout << "You are here: " << floor << " left(" << arr1[(i - 1) / 2] << ") " << arr1[i] << "\n" << "Enter the command: ";
            }
            else {
                std::cout << "You are here: " << floor << " right(" << arr1[(i - 2) / 2] << ") " << arr1[i] << "\n" << "Enter the command: ";
            }
        }
        std::cin >> command;
        if (command == "up") {
            up(floor, entity, i);
        }
        if (command == "left") {
            left(floor, entity, i, sizeof(arr1)/4);
        }
        if (command == "right") {
            right(floor, entity, i, sizeof(arr1) / 4);
        }
        if (command == "exit") {
            return 0;
        }
    }
}
