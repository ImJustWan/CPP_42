#include "Cat.hpp"
#include "colors.hpp"

Cat::Cat(): _type("Cat") {

	std::cout << _ITALIC "Cat Constructor called" _END << std::endl;
	return;
}

Cat::Cat(std::string type) : _type(type) {

	std::cout << _ITALIC "Cat String Parametric Constructor called" _END << std::endl;
	return;
}

Cat::Cat( Cat const & src ) {

	std::cout << _ITALIC "Cat Copy Constructor called" _END << std::endl;
	*this = src;
	return;
}

Cat::~Cat(void) {

	std::cout << _ITALIC "Cat Destructor called" _END << std::endl;
	return;
}

Cat & Cat::operator=( Cat const & rhs ) {
	
	std::cout << _ITALIC "Cat Copy Assignement operator called" _END << std::endl;
	if (this != &rhs)
		this->_type = rhs._type;
	return *this;

}

void	Cat::makeSound() const {
	std::cout << _SALMON << " *meows* " _END << std::endl;

}

std::string	Cat::getType(void) const {
	return _type;
}

