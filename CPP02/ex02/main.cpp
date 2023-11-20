#include "Fixed.hpp"
#include <iostream>
#include "colors.hpp"


int main()
{
	Fixed a;
	Fixed b( 8 );
	Fixed c( 3.14f );
	Fixed d( 42.42f );
	Fixed e = b;
	std::cout << _BOLD"\n\n------------------- START -------------------\n" << std::endl;
	std::cout << "\nInitial values :\n" _END << std::endl;
	std::cout << "\ta is " << a << std::endl;
	std::cout << "\tb is " << b << std::endl;
	std::cout << "\tc is " << c << std::endl;
	std::cout << "\td is " << d << std::endl;
	std::cout << "\te is " << e << std::endl;

	std::cout << _BOLD "\n\n------------------------";
	std::cout << "------------------------\n" _END << std::endl;
	
	std::cout << _BOLD _AQUAMARINE "\n\t\tCOMPARISON OPERATORS : \n" _END << std::endl;

	std::cout << _ITALIC _AQUAMARINE "max / min\n" _END << std::endl;
	std::cout << "\tmax(a, b) = " << Fixed::max(a, b) << std::endl;
	std::cout << "\tmin(a, b) = " << Fixed::min(a, b) << std::endl;
	std::cout << "\tmax(c, d) = " << Fixed::max(c, d) << std::endl;
	std::cout << "\tmin(b, e) = " << Fixed::min(b, e) << std::endl;

	std::cout << _ITALIC _AQUAMARINE "\nother funnsies\n" _END << std::endl;
	std::cout << "\t(a < e)  ? = " << (a < e ? "True" : "False") << std::endl;
	std::cout << "\t(c <= a) ? = " << (c <= a ? "True" : "False") << std::endl;
	std::cout << "\t(e > b)  ? = " << (e > b ? "True" : "False") << std::endl;
	std::cout << "\t(d >= e) ? = " << (d >= e ? "True" : "False") << std::endl;
	std::cout << "\t(b == e) ? = " << (b == e ? "True" : "False") << std::endl;
	std::cout << "\t(b != e) ? = " << (b != e ? "True" : "False") << std::endl;

	std::cout << _BOLD "\n\n------------------------";
	std::cout << "------------------------" _END << std::endl;
	
	std::cout << _BOLD _RIVIERA "\n\n\t\tARITHMETIC OPERATORS :" _END << std::endl;
	
	std::cout << _BOLD _RIVIERA "\n\naddition : \n" _END << std::endl;
	std::cout << _ITALIC "\tStart value of a : " << a << _END << std::endl;
	std::cout << "\n\ta = b + b" _END << std::endl;
	std::cout << "\ta = " << b << " + " << b << std::endl;
	std::cout << "\ta = " << b + b << std::endl;
	a = b + b;
	std::cout << _ITALIC _BOLD "\n\tFinal value of a : " << a << _END << std::endl;

	std::cout << _BOLD _RIVIERA "\n\nsubstraction : \n" _END << std::endl;
	std::cout << _ITALIC "\tStart value of b : " << b << _END << std::endl;
	std::cout << "\n\tb = d - 12" _END << std::endl;
	std::cout << "\tb = " << d << " - 12" << std::endl;
	std::cout << "\tb = " << d - 12 << std::endl;
	b = d - 12;
	std::cout << _ITALIC _BOLD "\n\tFinal value of b : " << b << _END << std::endl;

	std::cout << _BOLD _RIVIERA "\n\nproduct : \n" _END << std::endl;
	std::cout << _ITALIC "\tStart value of c : " << c << _END << std::endl;
	std::cout << "\tc = c * 4" _END << std::endl;
	std::cout << "\tc = " << c << " * 4" << std::endl;
	std::cout << "\tc = " << c * 4 << std::endl;
	c = c * 4;
	std::cout << _ITALIC _BOLD "\n\tFinal value of c : " << c << _END << std::endl;

	std::cout << _BOLD _RIVIERA "\n\ndivision : \n" _END << std::endl;
	std::cout << _ITALIC "\tStart value of d : " << d << _END << std::endl;
	std::cout << "\n\td = 1764 / d.toInt()" _END << std::endl;
	std::cout << "\td = " << "1764 / " << d.toInt() << std::endl;
	std::cout << "\td = " << 1764 / d.toInt() << std::endl;
	d = 1764 / d.toInt();
	std::cout << _ITALIC _BOLD "\n\tFinal value of d : " << d << _END << std::endl;
	
	std::cout << _BOLD _RIVIERA "\n\nspecial case : \n" _END << std::endl;
	std::cout << _ITALIC "\tStart value of e : " << e << _END << std::endl;
	std::cout << "\n\te = d / (a - e * 2)" _END << std::endl;
	std::cout << "\te = " << d << " / (" << a << " - " << e * 2 << ")" << std::endl;
	e = d / (a - e * 2);
	std::cout << _ITALIC _BOLD "\n\tFinal value of e : " << e << _END << std::endl;

	std::cout << _BOLD "\n\n------------------------";
	std::cout << "------------------------" _END << std::endl;

	std::cout << _BOLD _SALMON "\n\n\t\tINCREMENT/DECREMENT OPERATORS :" _END << std::endl;

	std::cout << _ITALIC _SALMON "\nIncrement with b(" << b << ")\n" _END << std::endl;
	std::cout << "\tb++ (post): \t" << b++ << std::endl;
	std::cout << "\tb is now :\t" << b << std::endl;
	std::cout << "\t++b (pre): \t" << ++b << std::endl;
	std::cout << "\tb is now :\t" << b << std::endl;

	std::cout << _ITALIC _SALMON "\nDecrement with b(" << b << ")\n" _END << std::endl;
	std::cout << "\tb-- (post): \t" << b-- << std::endl;
	std::cout << "\tb is now :\t" << b << std::endl;
	std::cout << "\t--b (pre): \t" << --b << std::endl;
	std::cout << "\tb is now :\t" << b << std::endl;

	std::cout << _BOLD"\n\n-------------------- END --------------------\n" << std::endl;
	return 0;
}

// int main( void ) {
// 	Fixed a;
// 	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
// 	std::cout << a << std::endl;
// 	std::cout << ++a << std::endl;
// 	std::cout << a << std::endl;
// 	std::cout << a++ << std::endl;
// 	std::cout << a << std::endl;
// 	std::cout << b << std::endl;
// 	std::cout << Fixed::max( a, b ) << std::endl;
// 	return 0;
// }

// int main( void )
// {
// 	Fixed a;
// 	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
// 	std::cout << a << std::endl;
// 	// std::cout << ++a << std::endl;
// 	std::cout << a << std::endl;
// 	// std::cout << a++ << std::endl;
// 	std::cout << a << std::endl;
// 	std::cout << b << std::endl;
// 	// std::cout << Fixed::max( a, b ) << std::endl;
// 	return 0;
// }