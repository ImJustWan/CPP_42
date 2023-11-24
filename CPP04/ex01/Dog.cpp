#include "Dog.hpp"
#include "colors.hpp"

Dog::Dog() : _type("Dog")  {

	_brain = new Brain("random dog thoughts");
	std::cout << _ITALIC "Dog Constructor called" _END << std::endl;
	return;
}

Dog::Dog(std::string idea) : _type("Dog") {

	_brain = new Brain(idea);
	std::cout << _ITALIC "Dog String Parametric Constructor called" _END << std::endl;
	return;
}

Dog::Dog( Dog const & src ) {

	std::cout << _ITALIC "Dog Copy Constructor called" _END << std::endl;
	*this = src;
	this->_brain = new Brain(*src._brain);
	return;
}


Dog::~Dog(void) {

    delete _brain;
	std::cout << _ITALIC "Dog Destructor called" << std::endl;
    return;
}

Dog & Dog::operator=( Dog const & rhs ) {
	
	std::cout << _ITALIC "Dog Copy Assignement operator called" _END << std::endl;
	if (this != &rhs)
	{
		this->_type = rhs._type;
		this->_brain = rhs._brain;
	}
	return *this;

}

void	Dog::makeSound() const {
	std::cout << _RIVIERA << " *barks* " _END << std::endl;
}

std::string	Dog::getType(void) const {
	return _type;
}

std::string	Dog::getIdea(int index) const {
	return _brain->getIdea(index);
}