#include <iostream>

int main()
{
	int 	a = 42;							// Ref value

	double	b = a;							// Implicit promotion -> OK
	int		c = b;							// Implicit demotion -> NOPE
	int		d = static_cast<int>(b);		// Explicit demotion -> Ok, we're in charge

	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << c << std::endl;
	std::cout << d << std::endl;
	return 0;
}