#include "wrongAnimal.hpp"
#include "colors.hpp"

wrongAnimal::wrongAnimal() : _type("wrongAnimal") {

	std::cout << _ITALIC "\nwrongAnimal Constructor called" _END << std::endl;
	return;
}

wrongAnimal::wrongAnimal(std::string type) : _type(type) {

	std::cout << _ITALIC "wrongAnimal String Parametric Constructor called" _END << std::endl;
	return;
}

wrongAnimal::wrongAnimal( wrongAnimal const & src ) {

	std::cout << _ITALIC "wrongAnimal Copy Constructor called" _END << std::endl;
	*this = src;
	return;
}

wrongAnimal::~wrongAnimal(void) {

    std::cout << _ITALIC "wrongAnimal Destructor called" _END << std::endl;
    return;
}

wrongAnimal & wrongAnimal::operator=( wrongAnimal const & rhs ) {
	
	std::cout << _ITALIC "wrongAnimal Copy Assignement operator called" _END << std::endl;
	if (this != &rhs)
		this->_type = rhs._type;
	return *this;

}

void	wrongAnimal::makeSound() const {
	std::cout << _FOREST_GREEN << " *undefined noises* " _END << std::endl;
}

std::string	wrongAnimal::getType(void) const {
	return _type;
}
