#include <iostream>
#include "Sample.class.hpp"

int main() {

	Sample		instance;
	Sample *	instanceptr = &instance;

	int		Sample::*ptr = NULL;
	void	(Sample::*f)(void) const;

	ptr = &Sample::foo;

	std::cout << "Value of member foo: " << instance.foo << std::endl;
	instance.*ptr = 21;
	std::cout << "Value of member foo: " << instance.foo << std::endl;
	instance.*ptr = 42;
	std::cout << "Value of member foo: " << instance.foo << std::endl;

	f = &Sample::bar;

	(instance.*f)();
	(instanceptr->*f)();

	return 0;
}