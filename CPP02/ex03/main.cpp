#include "Fixed.hpp"
#include "Point.hpp"

int main( void ) {

	Point	a(2.0f, 4.0f);
	Point	b(5.0f, 7.0f);
	Point	c(7.0f, 3.0f);
	Point	point(5.0f, 5.0f);
	if (Point::bsp(a, b, c, point) ==  true)
		std::cout << "IT'S IN BABY" << std::endl;
	else
		std::cout << "HAHA, NOPE." << std::endl;
	return 0;
}
