#include "ICharacter.hpp"
#include "colors.hpp"

ICharacter::ICharacter() {

	// std::cout << _ITALIC "ICharacter Constructor called" _END << std::endl;
	return;
}

ICharacter::ICharacter( ICharacter const & src ) {

	// std::cout << _ITALIC "ICharacter Copy Constructor called" _END << std::endl;
	*this = src;
	return;
}

ICharacter::~ICharacter(void) {

	// std::cout << _ITALIC "ICharacter Destructor called" << std::endl;
	return;
}

