#include <iostream>
#include "Sample.class.hpp"

Sample::Sample(void) : _foo( 0 ) {

	std::cout << "Constructor called" << std::endl;
	return;
}

Sample::Sample( int const n ) : _foo( n ) {

	std::cout << "Parametric Constructor called" << std::endl;
	return;
}

Sample::Sample( Sample const & src ) {

	std::cout << "Copy Constructor called" << std::endl;
	*this = src;
	return;
}

Sample::~Sample(void) {

    std::cout << "Destructor called" << std::endl;
    return;
}

int Sample::getFoo( void ) const {
	return this->_foo;
}

std::ostream & operator <<( std::ostream & o, Sample const & i ) {
	o << "The value of _foo is : " << i.getFoo();
	return o;
}

Sample & Sample::operator=( Sample const & rhs ) {
	std::cout << "Assignement operator called" << std::endl;

	this->_foo = rhs.getFoo();
	return *this;

}