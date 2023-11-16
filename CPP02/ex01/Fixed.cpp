#include "Fixed.hpp"


Fixed::Fixed(void) : _n( 0 ) {

	std::cout << "Default Constructor called" << std::endl;
	return;
}


Fixed::Fixed( int const n ) : _n( n << _rawBits) {

	std::cout << "BEFORE CONVERSION: " << n << std::endl;

	std::cout << "Int Parametric Constructor called" << std::endl;
	std::cout << "AFTER CONVERSION: " << _n << std::endl;
	return;
}

Fixed::Fixed( float const f ):  _n(static_cast<int>(f * (1 << _rawBits))){

	std::cout << "Float Parametric Constructor called" << std::endl;
	return;
}


Fixed::Fixed( Fixed const & src ) : _n(src._n) {

	std::cout << "Copy Constructor called" << std::endl;
	*this = src;
	return;
}

Fixed::~Fixed(void) {

    std::cout << "Destructor called" << std::endl;
    return;
}

int Fixed::getRawBits( void ) const {

    // std::cout << "getRawBits member function called" << std::endl;
	return this->_n;
}

void Fixed::setRawBits( int const raw ){
    this->_n = raw;
}

int		Fixed::toInt( void ) const {
	if (this->_n >= 0)
		return (this->_n + ( 1 << (_rawBits - 1))) >> _rawBits;
	else
		return (this->_n - ( 1 << (_rawBits - 1))) >> _rawBits;

}

float	Fixed::toFloat( void ) const {
	return static_cast<float>(this->_n) / (1 << _rawBits);
}


std::ostream & operator <<( std::ostream & o, Fixed const & i ) {
	o << i.toFloat();
	return o;
}

Fixed & Fixed::operator=( Fixed const & n ) {
	std::cout << "Copy Assignement operator called" << std::endl;

	this->_n = n.getRawBits();
	return *this;

}