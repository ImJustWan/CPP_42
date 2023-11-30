#pragma once

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

	static bool		bsp(Point const a, Point const b, Point const c, Point const point);
	static float	triangleArea(Point const a, Point const b, Point const c);

private:
	Point	&operator=(Point const &rhs);
	Fixed	const	_x;
	Fixed	const	_y;

};
