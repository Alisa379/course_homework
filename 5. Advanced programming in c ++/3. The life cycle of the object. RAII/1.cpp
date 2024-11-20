
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

	smart_array(const smart_array&) = delete;
	smart_array& operator=(const smart_array&) = delete;

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
};

int main()
{
	try {
		smart_array arr(5);
		arr.add_element(1);
		arr.add_element(4);
		arr.add_element(155);
		arr.add_element(14);
		arr.add_element(15);
		std::cout << arr.get_element(1) << std::endl;
	}
	catch (const std::exception& ex) {
		std::cout << ex.what() << std::endl;
	}
}
