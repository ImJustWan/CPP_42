#ifndef POINT_HPP
# define POINT_HPP

#include <iostream>
#include <math.h>
#include "Fixed.hpp"

class Point {
public:
	Point(void);                // canon
	Point(Point const &src);	// canon
	Point(float const xf, float const yf);
	~Point(void);				// canon

	int	tmp;

	Point   		&operator=(Point const &rhs);
	static bool		bsp(Point const a, Point const b, Point const c, Point const point);
	static float	triangleArea(Point const a, Point const b, Point const c);

private:
	const Fixed	_x;
	const Fixed	_y;

};

#endif