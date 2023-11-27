#include "Animal.hpp"
#include "colors.hpp"

Animal::Animal() : _type("Random Animal") {

	std::cout << _ITALIC "Animal Constructor called" _END << std::endl;
	return;
}

Animal::Animal(std::string type) : _type(type) {

	std::cout << _ITALIC "Animal String Parametric Constructor called" _END << std::endl;
	return;
}

Animal::Animal( Animal const & src ) {

	std::cout << _ITALIC "Animal Copy Constructor called" _END << std::endl;
	*this = src;
	return;
}

Animal::~Animal(void) {

    std::cout << _ITALIC "Animal Destructor called" _END << std::endl;
    return;
}

Animal & Animal::operator=( Animal const & rhs ) {
	
	std::cout << _ITALIC "Animal Copy Assignement operator called" _END << std::endl;
	if (this != &rhs)
		this->_type = rhs._type;
	return *this;

}

void	Animal::makeSound() const {
	std::cout << _FOREST_GREEN << " *undefined noises* " _END << std::endl;
}

std::string	Animal::getType(void) const {
	return this->_type;
}

std::string	Animal::getIdea(int index) const {
	(void)index;
	return ("");
}

