#include <iostream>

int calc(int point, int *arr, int size) {
	int left = 0;
	int right = size - 1;
	int middle = (left + right) / 2;
	int result = 0;
	int m=0;
	size -= 1;
	if ((right - left) == 1) {
		if (point < arr[1]) {
			return 2;
		}
		if (point < arr[0]) {
			return 1;
		}
		else {
			return 0;
		}
	}
	if ((right - left) == 0) {
		if (point < arr[0]) {
			return 1;
		}
		else {
			return 0;
		}
	}
	while ((right - left) >= 1) {
		if (point == arr[middle]) {
			if (middle == size) {
				return 0;
			}
			left = middle;
			middle = (left + right) / 2;
			result = size - middle;
			if (m == middle) {
				return result;
			}
			m = middle;
		}   
		if (point > arr[middle]) {
			if (middle == size) {
				return 0;
			}
			left = middle; 
			middle = (left + right) / 2;
			if (m == middle) {
				if (middle == (size - 1)) {
					middle += 1;
				}
				else {
					return result;
				}
			}
			m = middle;
		}
		if (point < arr[middle]) {
			if (middle == size) {
				return 1;
			}
			right = middle;
			middle = (right + left) / 2;
			result = size - middle;
			if (middle == 0){
				if (point < arr[middle]) {
					return size+1;
				}
				else {
					return size;
				}
			}
			if (m == middle) {
				return result;
			}
			m = middle;
		}
	}

	return result;
}

int main() {
	int point;
	int arr[] = {14, 16, 19, 32, 32, 32, 56, 69, 72};
	int size = 9;
	std::cout << "Enter a reference point: ";
	std::cin >> point;
	std::cout << "The number of elements in the array greater than " << point << ": " << calc(point, arr, size);
	return 0;
}