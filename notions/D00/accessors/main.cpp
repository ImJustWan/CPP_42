#include <iostream>
#include "Sample.class.hpp"

int main() {

	Sample	instance;

	instance.setFoo(42);
	std::cout << "instance.getFoo(): " << instance.getFoo() << std::endl;
	instance.setFoo(-42);
	std::cout << "instance.getFoo(): " << instance.getFoo() << std::endl;

	return 0;
}