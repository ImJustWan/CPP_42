#include "Point.hpp"

Point::Point(void) : _x(0), _y(0) {
	return;
}

Point::Point(float const xf, float const yf) : _x(xf), _y(yf) {
	return;
}

Point::Point(Point const &src) : _x(src._x), _y(src._y) {
	*this = src;
	return;
}

Point::~Point(void) {
	return;
}

/* MEMBER FUNCTIONS (METHODS) */

Point &Point::operator=(Point const &rhs) {
	this->tmp = rhs.tmp;
	return *this;
}

