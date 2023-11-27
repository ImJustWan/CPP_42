#include "Ice.hpp"
#include "colors.hpp"

Ice::Ice() {

	this->setType("ice");
	// std::cout << _ITALIC "Ice Constructor called" _END << std::endl;
	return;
}

Ice::Ice(std::string const & type): AMateria(type) {

	// std::cout << _ITALIC "Ice String Parametric Constructor called" _END << std::endl;
	return;
}

Ice::Ice( Ice const & src ) {

	// std::cout << _ITALIC "Ice Copy Constructor called" _END << std::endl;
	this->setType("ice");
	*this = src;
	return;
}

Ice::~Ice(void) {

	// std::cout << _ITALIC "Ice Destructor called" << std::endl;
	return;
}

Ice & Ice::operator=( Ice const & rhs ) {
	
	// std::cout << _ITALIC "Ice Copy Assignement operator called" _END << std::endl;
	if (this != &rhs)
		this->setType(rhs.getType());
	return *this;

}

AMateria* Ice::clone() const {
	return new Ice(*this);
}

void Ice::use(ICharacter& target) {
	std::cout << "🧊🧊🧊 " _CYAN "* shoots an ice bolt at " << target.getName() << " *" _END "\n" << std::endl;
}