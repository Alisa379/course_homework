
#include <iostream>

class smart_array {
public:
	int amount, n = 0;
	int* array;
	smart_array(int am) : amount(am) {
		array = new int[amount];
	}
	~smart_array() {
		delete[] array;
	}
	smart_array(const smart_array& other) {
		if (this != &other) {
			amount = other.amount;
			n = other.n;
			array = new int[amount];
			for (int j = 0; j < n; ++j) {
				array[j] = other.array[j];
			}
		}
	}
	void add_element(int i) {
		if (n < amount) {
			array[n] = i;
			n++;
		}
		else {
			throw std::exception("Array is full!");
		}
	}
	int get_element(int i) {
		if (i < amount && i > 0) {
			return array[i];
		}
		else {
			throw std::exception("The index is incorrect!");
		}
	}
	smart_array& operator=(const smart_array& other) {
		if (this != &other)  {
			delete[] array;
			amount = other.amount;
			n = other.n;
			array = new int[amount];
			for (int j = 0; j < n; ++j) {
				array[j] = other.array[j];
			}
		}
		return *this;
	}
};


int main()
{
	try {
		smart_array arr(5);
		arr.add_element(1);
		arr.add_element(4);
		arr.add_element(155);

		smart_array new_array(6);
		new_array.add_element(44);
		new_array.add_element(34);

		arr = new_array;

	}
	catch (const std::exception& ex) {
		std::cout << ex.what() << std::endl;
	}
}
