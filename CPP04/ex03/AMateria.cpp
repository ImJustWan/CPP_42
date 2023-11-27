#include "AMateria.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "colors.hpp"

AMateria::AMateria() {

	// std::cout << _ITALIC "AMateria Constructor called" _END << std::endl;
	return;
}


AMateria::AMateria(std::string const & type) : _type(type) {
	// std::cout << _ITALIC "Cure String Parametric Constructor called" _END << std::endl;
	return;
}

AMateria::AMateria( AMateria const & src ) {

	// std::cout << _ITALIC "AMateria Copy Constructor called" _END << std::endl;
	*this = src;
	return;
}

AMateria::~AMateria(void) {

	// std::cout << _ITALIC "AMateria Destructor called" << std::endl;
	return;
}

AMateria & AMateria::operator=( AMateria const & rhs ) {
	
	// std::cout << _ITALIC "AMateria Copy Assignement operator called" _END << std::endl;
	if (this != &rhs)
		this->_type = rhs._type;
	return *this;

}

std::string const & AMateria::getType() const {
	return this->_type;
}

void	AMateria::setType(std::string type) {
	this->_type = type;
}
