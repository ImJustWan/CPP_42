#include <iostream>
#include "Basics.hpp"

int main()
{

	std::cout << _BOLD _GREY "\n🔹 INT 🔹\n" _END << std::endl;
	int	a = 42;
	int	b = 24;

	std::cout << "a(" << a << ") and b(" << b << ")" << std::endl;
	std::cout << "min(a, b) : " << ::min(a, b) << std::endl;
	std::cout << "max(a, b) : " << ::max(a, b) << std::endl;
	::swap(a, b);
	std::cout << _ITALIC _GREY "After swap : " _END << std::endl;
	std::cout << "a(" << a << ") and b(" << b << ")\n" << std::endl;
	
	std::cout << _BOLD _GREY "\n🔹 FLOAT 🔹\n" _END << std::endl;

	float c = 8.8f; // different types can't be called in the same function
	// std::cout << "a(" << a << ") and c(" << c << ")" << std::endl; 

	float d = -3.14f;
	std::cout << "c(" << c << ") and d(" << d << ")" << std::endl;
	std::cout << "min(c, d) : " << ::min(c, d) << std::endl;
	std::cout << "max(c, d) : " << ::max(c, d) << std::endl;
	::swap(c, d);
	std::cout << _ITALIC _GREY "After swap : " _END << std::endl;
	std::cout << "c(" << c << ") and d(" << d << ")" << std::endl;

	std::cout << _BOLD _GREY "\n🔹 STRING 🔹\n" _END << std::endl;

	std::string e = "Airsick lowlanders";
	std::string f = "Gancho";
	std::cout << "e(" << e << ") and f(" << f << ")" << std::endl;
	std::cout << "min(e, f) : " << ::min(e, f) << std::endl;
	std::cout << "max(e, f) : " << ::max(e, f) << std::endl;
	::swap(e, f);
	std::cout << _ITALIC _GREY "After swap : " _END << std::endl;
	std::cout << "e(" << e << ") and f(" << f << ")\n" << std::endl;
	std::cout << "min(e, f) : " << ::min(e, f) << std::endl;

	// For strings, we get the lexicographically result,
	// which means the one that would come first in a dictionary.

	return 0;
}

// int main( void ) {
// 	int a = 2;
// 	int b = 3;
// 	::swap( a, b );
// 	std::cout << "a = " << a << ", b = " << b << std::endl;
// 	std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
// 	std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
// 	std::string c = "chaine1";
// 	std::string d = "chaine2";
// 	::swap(c, d);
// 	std::cout << "c = " << c << ", d = " << d << std::endl;
// 	std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
// 	std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
// 	return 0;
// }