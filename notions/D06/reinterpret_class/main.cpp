#include <iostream>

int main()
{
	float 	a = 420.042f;							// Ref value

	void	*b = &a;								// Implicit promotion -> OK
	int		*c = reinterpret_cast<int *>(b);		// Explicit demotion -> Ok, we're in charge
	int		&d = reinterpret_cast<int &>(b);		// Explicit demotion -> Ok, we're in charge

	// retypage	std::cout << c << std::endl;


	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << c << std::endl;
	std::cout << d << std::endl;
	return 0;
}