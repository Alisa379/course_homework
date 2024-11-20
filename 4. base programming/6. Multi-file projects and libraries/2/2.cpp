#include "class.h"
#include <iostream>

Counter::Counter(int a) {
	this->a = a;
}
void Counter::increment() {
	a++;
}
void Counter::decrement() {
	a--;
}
int Counter::rt() {
	return a;
}
