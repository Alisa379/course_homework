// сортировка слиянием

#include <iostream>

void merge(int *arr, int low, int high, int mid);
void merge_sort(int *arr, int low, int high)
{
    int mid;
    if (low < high) {
        mid = (low + high) / 2;
        merge_sort(arr, low, mid);
        merge_sort(arr, mid + 1, high);
        merge(arr, low, high, mid);
    }
}

void merge(int *arr, int low, int high, int mid)
{
    int i, j, k, c[50];
    i = low;
    k = low;
    j = mid + 1;
    while (i <= mid && j <= high) {
        if (arr[i] < arr[j]) {
            c[k] = arr[i];
            k++;
            i++;
        }
        else {
            c[k] = arr[j];
            k++;
            j++;
        }
    }
    while (i <= mid) {
        c[k] = arr[i];
        k++;
        i++;
    }
    while (j <= high) {
        c[k] = arr[j];
        k++;
        j++;
    }
    for (i = low; i < k; i++) {
        arr[i] = c[i];
    }
}

void show(int *arr, int a) {
	for (int i = 0; i < a; ++i) {
		std::cout << arr[i] << "\t";
	}
	std::cout << "\n";
}


int main() {
	int arr1[10] = { 3, 43, 38, 29, 18, 72, 57, 61, 2, 33 };
	int arr2[15] = { 88, 91, 87, 59, 53, 49, 29, 16, 4, 27, 28, 89, 2, 25, 74 };
	int arr3[18] = { 24, 66, 20, 79, 30, 16, 19, 62, 94, 59, 0, 7, 59, 90, 84, 60, 95, 62 };
	merge_sort(arr1, 0, 9);
	merge_sort(arr2, 0, 14);
	merge_sort(arr3, 0, 17);
	show(arr1, 10);
	show(arr2, 15);
	show(arr3, 18);
}