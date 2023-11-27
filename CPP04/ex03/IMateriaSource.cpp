#include "IMateriaSource.hpp"
#include "colors.hpp"

IMateriaSource::IMateriaSource() {

	// std::cout << _ITALIC "IMateriaSource Constructor called" _END << std::endl;
	return;
}

IMateriaSource::IMateriaSource( IMateriaSource const & src ) {

	// std::cout << _ITALIC "IMateriaSource Copy Constructor called" _END << std::endl;
	*this = src;
	return;
}

IMateriaSource::~IMateriaSource(void) {

	// std::cout << _ITALIC "IMateriaSource Destructor called" << std::endl;
	return;
}
