#pragma once

#include <iostream>

class Fixed {

public:

	Fixed(void);
	Fixed(Fixed const & src);
	~Fixed(void);

	Fixed & operator=( Fixed const & rhs );

	int		getRawBits( void ) const;
	void	setRawBits( int const raw );

private:
	int					_n;
	static const int	_rawBits = 8;

};
