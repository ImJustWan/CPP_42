#include "Fixed.hpp"
#include "Point.hpp"
#include "colors.hpp"

void	question(bool answer)
{
	if (answer == true)
		std::cout << _EMMERALD _BOLD "\t\tIT IS IN CAP'N\n" _END << std::endl;
	else
		std::cout << _RED _BOLD "\t\tHAHA, NOPE.\n" _END << std::endl;
}

int main( void ) {

	Point	a(2.0f, 4.0f);
	Point	b(5.0f, 7.0f);
	Point	c(7.0f, 3.0f);
	std::cout << "\nOur triangle as the following coordinates :\n" << std::endl;
	std::cout << "\t\tA(2,4)" << std::endl;
	std::cout << "\t\tB(5,7)" << std::endl;
	std::cout << "\t\tC(7,3)\n" << std::endl;

	Point point(5.0f, 5.0f);
	std::cout << "\nIs the point P(5,5) inside this triangle ?\n" << std::endl;
	question(Point::bsp(a, b, c, point));

	Point qPoint(1, 2);
	std::cout << "\nIs the point Q(1,2) inside this triangle ?\n" << std::endl;
	question(Point::bsp(a, b, c, qPoint));

	Point aBis(2.0f, 4.0f);
	std::cout << "\nIs the point aBis(2,4) inside this triangle ?\n" << std::endl;
	question(Point::bsp(a, b, c, aBis));

	Point last(6, 4);
	std::cout << "\nIs the last_point(6,4) inside this triangle ?\n" << std::endl;
	question(Point::bsp(a, b, c, last));
	return 0;
}
