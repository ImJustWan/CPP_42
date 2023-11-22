#include "colors.hpp"
#include "Fixed.hpp"
#include <iostream>

// int main()
// {
// 	Fixed a;
// 	Fixed b( 8 );
// 	Fixed c( 3.14f );
// 	Fixed d( b );
// 	std::cout << _BOLD"\n-------- START --------\n" << std::endl;
// 	std::cout <<  "Initial values :\n" _END << std::endl;
// 	std::cout << "\ta is " << a << std::endl;
// 	std::cout << "\tb is " << b << std::endl;
// 	std::cout << "\tc is " << c << std::endl;
// 	std::cout << "\td is " << d << std::endl;

// 	std::cout <<  _BOLD "\nValue to Int :\n" _END << std::endl;

// 	std::cout << "\ta is " << a.toInt() << " as integer" << std::endl;
// 	std::cout << "\tb is " << b.toInt() << " as integer" << std::endl;
// 	std::cout << "\tc is " << c.toInt() << " as integer" << std::endl;
// 	std::cout << "\td is " << d.toInt() << " as integer" << std::endl;

// 	std::cout <<  _BOLD "\nAnd now to Float :\n" _END << std::endl;

// 	std::cout << "\ta is " << a.toFloat() << " as float" << std::endl;
// 	std::cout << "\tb is " << b.toFloat() << " as float" << std::endl;
// 	std::cout << "\tc is " << c.toFloat() << " as float" << std::endl;
// 	std::cout << "\td is " << d.toFloat() << " as float" << std::endl;

// 	std::cout <<  _BOLD "\n\nMaking some changes : \n" _END << std::endl;
// 	a = Fixed( 1234.43f );
// 	d = b;
// 	std::cout << "\n\tNow a is " << a << std::endl;
// 	std::cout << "\tNow d is " << d << "\n" << std::endl;
// 	std::cout << _BOLD "\n-------- END --------\n" _END << std::endl;
// 	return 0;
// }

int main( void )
{
	Fixed a;
	Fixed const b( 10 );
	Fixed const c( 42.42f );
	Fixed const d( b );
	a = Fixed( 1234.4321f );
	std::cout << "a is " << a << std::endl;
	std::cout << "b is " << b << std::endl;
	std::cout << "c is " << c << std::endl;
	std::cout << "d is " << d << std::endl;
	std::cout << "a is " << a.toInt() << " as integer" << std::endl;
	std::cout << "b is " << b.toInt() << " as integer" << std::endl;
	std::cout << "c is " << c.toInt() << " as integer" << std::endl;
	std::cout << "d is " << d.toInt() << " as integer" << std::endl;
	return 0;
}