#pragma once

#include <iostream>
#include <math.h>

class Fixed {
public:
	Fixed(void);                // canon
	Fixed(int const n);
	Fixed(float const f);
	Fixed(Fixed const &src);	// canon
	~Fixed(void);				// canon

	Fixed   &operator=(Fixed const &rhs);
	Fixed   operator+(Fixed const &rhs) const;
	Fixed   operator-(Fixed const &rhs) const;
	Fixed   operator*(Fixed const &rhs) const;
	Fixed   operator/(Fixed const &rhs) const;

	bool    operator==(Fixed const &rhs) const;
	bool    operator!=(Fixed const &rhs) const;
	bool    operator<(Fixed const &rhs) const;
	bool    operator<=(Fixed const &rhs) const;
	bool    operator>(Fixed const &rhs) const;
	bool    operator>=(Fixed const &rhs) const;

	Fixed   &operator++();       // pre increment
	Fixed   operator++(int);     // post increment
	Fixed   &operator--();       // pre increment
	Fixed   operator--(int);     // post increment

	int     toInt(void) const;
	float   toFloat(void) const;
	int     getRawBits(void) const;
	void    setRawBits(int const raw);

	static Fixed max(Fixed const &x, Fixed const &y);
	static Fixed min(Fixed const &x, Fixed const &y);

private:
	int _n;
	static const int _rawBits = 8;
};
std::ostream &operator<<(std::ostream &o, Fixed const &i);
