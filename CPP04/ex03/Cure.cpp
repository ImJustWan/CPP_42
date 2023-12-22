#include "AMateria.hpp"
#include "Cure.hpp"
#include "colors.hpp"


Cure::Cure() {

	this->setType("cure");
	// std::cout << _ITALIC "Cure Constructor called" _END << std::endl;
	return;
}

Cure::Cure(std::string const & type): AMateria(type) {

	// std::cout << _ITALIC "Cure String Parametric Constructor called" _END << std::endl;
	return;
}

Cure::Cure( Cure const & src ) {

	// std::cout << _ITALIC "Cure Copy Constructor called" _END << std::endl;
	this->setType("cure");
	*this = src;
	return;
}

Cure::~Cure(void) {

	// std::cout << _ITALIC "Cure Destructor called" << std::endl;
	return;
}

Cure & Cure::operator=( Cure const & rhs ) {
	
	// std::cout << _ITALIC "Cure Copy Assignement operator called" _END << std::endl;
	if (this != &rhs)
		this->setType(rhs.getType());
	return *this;

}

AMateria* Cure::clone() const {
	return new Cure(*this);
}

void Cure::use(ICharacter& target)
{
	std::cout << "🧪🧪🧪 " _FOREST_GREEN "* heals " << target.getName() << "'s wounds *" _END "\n" << std::endl;
}