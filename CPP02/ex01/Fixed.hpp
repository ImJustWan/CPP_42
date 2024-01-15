#pragma once

#include <iostream>

class Fixed {

public:

	Fixed(void);
	Fixed(int const n);
	Fixed(float const f);
	Fixed(Fixed const & src);
	~Fixed(void);

	Fixed & operator=( Fixed const & rhs );

	int		getRawBits( void ) const;
	void	setRawBits( int const raw );
	int		toInt( void ) const;
	float	toFloat( void ) const;

private:
	int					_n;
	static const int	_rawBits = 8;

};

std::ostream & operator<<( std::ostream & o, Fixed const & rhs );
