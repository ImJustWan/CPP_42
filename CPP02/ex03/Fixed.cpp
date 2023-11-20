#include "Fixed.hpp"
#include "colors.hpp"

Fixed::Fixed(void) : _n(0) {
	return;
}

Fixed::Fixed(int const n) : _n(n << _rawBits) {
	return;
}

Fixed::Fixed(float const f) : _n(roundf(f * (1 << _rawBits))) {
	return;
}

// Fixed::Fixed(float const f) : _n(static_cast<int>(f * (1 << _rawBits) + ((f < 0) ? -0.5f : 0.5f))) {
// 	return;
// }

Fixed::Fixed(Fixed const &src) : _n(src._n) {
	*this = src;
	return;
}

Fixed::~Fixed(void) {
	return;
}

/* MEMBER FUNCTIONS (METHODS) */

int Fixed::getRawBits(void) const {
	return this->_n;
}

void Fixed::setRawBits(int const raw) {
	this->_n = raw;
}

int Fixed::toInt(void) const {
	return this->_n >> _rawBits;
}

float Fixed::toFloat(void) const {
	return static_cast<float>(this->getRawBits()) / (1 << _rawBits);
}

std::ostream &operator<<(std::ostream &o, Fixed const &i) {
	o << i.toFloat();
	return o;
}

Fixed &Fixed::operator=(Fixed const &rhs) {
	this->_n = rhs.getRawBits();
	return *this;
}


/* ARITHMETIC OPERATORS */

Fixed Fixed::operator+(Fixed const &rhs) const {
	return Fixed(this->toFloat() + rhs.toFloat());
	// return Fixed(this->toFloat() + rhs._n);
}

Fixed Fixed::operator-(Fixed const &rhs) const {
	return Fixed(this->toFloat() - rhs.toFloat());
}

Fixed Fixed::operator*(Fixed const &rhs) const {
	return Fixed(this->toFloat() * rhs.toFloat());
}

Fixed Fixed::operator/(Fixed const &rhs) const {
	if (rhs.getRawBits() != 0)
		return Fixed(this->toFloat() / rhs.toFloat());
	std::cout << _BOLD _PINK "\tI don't divide by 0, sorry." _END << std::endl;
	return this->toFloat();
}


/* COMPARISON OPERATORS */

bool	Fixed::operator==(Fixed const &rhs) const {
	return (this->toFloat() == rhs.toFloat());
}

bool	Fixed::operator!=(Fixed const &rhs) const {
	return (this->toFloat() != rhs.toFloat());
}

bool	Fixed::operator<(Fixed const &rhs) const {
	return (this->toFloat() < rhs.toFloat());
}

bool	Fixed::operator<=(Fixed const &rhs) const {
	return (this->toFloat() <= rhs.toFloat());
}

bool	Fixed::operator>(Fixed const &rhs) const {
	return (this->toFloat() > rhs.toFloat());
}

bool	Fixed::operator>=(Fixed const &rhs) const {
	return (this->toFloat() >= rhs.toFloat());
}


/* INCREMENT-DECREMENT OPERATORS */

Fixed &Fixed::operator++() {
	++this->_n;
	return *this;
}

Fixed Fixed::operator++(int) {
	Fixed tmp = *this;
	++_n;
	return tmp;
}

Fixed &Fixed::operator--() {
	--this->_n;
	return *this;
}

Fixed Fixed::operator--(int) {
	Fixed tmp = *this;
	--_n;
	return tmp;
}

/* NON-MEMBER FUNCTIONS */

Fixed Fixed::min(Fixed const &x, Fixed const &y) {
	return x < y ? x : y;
}

Fixed Fixed::max(Fixed const &x, Fixed const &y) {
	return (x > y) ? x : y;
}
