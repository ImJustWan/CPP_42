#include "Fixed.hpp"
#include "colors.hpp"

Fixed::Fixed(void) : _n( 0 ) {

	std::cout << _ITALIC "Default Constructor called" _END << std::endl;
	return;
}

Fixed::Fixed( int const n ) : _n( n << _rawBits) {

	std::cout << _ITALIC "Int Parametric Constructor called" _END << std::endl;
	return;
}

Fixed::Fixed( float const f ):  _n(static_cast<int>(f * (1 << _rawBits))){

	std::cout << _ITALIC "Float Parametric Constructor called" _END << std::endl;
	return;
}

Fixed::Fixed( Fixed const & src ) : _n(src._n) {

	std::cout << _ITALIC "Copy Constructor called" _END << std::endl;
	*this = src;
	return;
}

Fixed::~Fixed(void) {

    std::cout << _ITALIC "Destructor called" _END << std::endl;
    return;
}

int Fixed::getRawBits( void ) const {
	return this->_n;
}

void Fixed::setRawBits( int const raw ){
    this->_n = raw;
}

int		Fixed::toInt( void ) const {
	return (this->_n >> this->_rawBits);
}

float	Fixed::toFloat( void ) const {
	return static_cast<float>(this->getRawBits()) / (1 << this->_rawBits);
}


std::ostream & operator <<( std::ostream & o, Fixed const & i ) {
	o << i.toFloat();
	return o;
}

Fixed & Fixed::operator=( Fixed const & n ) {
	
	std::cout << _ITALIC "Copy Assignement operator called" _END << std::endl;
	this->_n = n.getRawBits();
	return *this;

}