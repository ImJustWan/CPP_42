#include "wrongCat.hpp"
#include "colors.hpp"

wrongCat::wrongCat(): _type("wrongCat") {

	std::cout << _ITALIC "wrongCat Constructor called" _END << std::endl;
	return;
}

wrongCat::wrongCat(std::string type) : _type(type) {

	std::cout << _ITALIC "wrongCat String Parametric Constructor called" _END << std::endl;
	return;
}

wrongCat::wrongCat( wrongCat const & src ) {

	std::cout << _ITALIC "wrongCat Copy Constructor called" _END << std::endl;
	*this = src;
	return;
}

wrongCat::~wrongCat(void) {

	std::cout << _ITALIC "wrongCat Destructor called" _END << std::endl;
	return;
}

wrongCat & wrongCat::operator=( wrongCat const & rhs ) {
	
	std::cout << _ITALIC "wrongCat Copy Assignement operator called" _END << std::endl;
	if (this != &rhs)
		this->_type = rhs._type;
	return *this;

}

void	wrongCat::makeSound() const {
	std::cout << _SALMON << " *wrongMeows* " _END << std::endl;

}

std::string	wrongCat::getType(void) const {
	return _type;
}

