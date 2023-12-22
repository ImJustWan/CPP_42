#include "Dog.hpp"
#include "colors.hpp"

Dog::Dog() : _type("Dog")  {

	std::cout << _ITALIC "Dog Constructor called" _END << std::endl;
	return;
}

Dog::Dog(std::string type) : _type(type) {

	std::cout << _ITALIC "Dog String Parametric Constructor called" _END << std::endl;
	return;
}

Dog::Dog( Dog const & src ) {

	std::cout << _ITALIC "Dog Copy Constructor called" _END << std::endl;
	*this = src;
	return;
}

Dog::~Dog(void) {

	std::cout << _ITALIC "Dog Destructor called" _END << std::endl;
	return;
}

Dog & Dog::operator=( Dog const & rhs ) {
	
	std::cout << _ITALIC "Dog Copy Assignement operator called" _END << std::endl;
	if (this != &rhs)
		this->_type = rhs._type;
	return *this;

}

void	Dog::makeSound() const {
	std::cout << _RIVIERA << " *barks* " _END << std::endl;
}

std::string	Dog::getType(void) const {
	return _type;
}
