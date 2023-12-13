#include <iostream>

int main()
{
	int			a = 42;							// Ref value

	int const	*b = &a;						// Implicit promotion -> OK
	// int			*c = b;							// Implicit demotion -> NOPE
	int const	*d = const_cast<int *>(b);		// Explicit demotion -> OK, we're in charge

	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << d << std::endl;
}
