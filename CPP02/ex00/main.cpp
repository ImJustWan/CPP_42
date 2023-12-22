#include "Fixed.hpp"
#include <iostream>

int main( void ) {
	Fixed a;
	Fixed b( a );
	Fixed c;
	c = b;
	std::cout << "\nValue in a is : " << a.getRawBits() << std::endl;
	std::cout << "Value in b is : " << b.getRawBits() << std::endl;
	std::cout << "Value in c is : " << c.getRawBits() << std::endl;
	b.setRawBits(8);
	std::cout << "Value in b is now : " << b.getRawBits() << std::endl;
	return 0;
}
