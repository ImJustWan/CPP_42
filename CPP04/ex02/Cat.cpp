#include "Cat.hpp"
#include "colors.hpp"

Cat::Cat(): _type("Cat") {

	_brain = new Brain("random cat thoughts");
	std::cout << _ITALIC "Cat Constructor called" _END << std::endl;
	return;
}

Cat::Cat(std::string idea) {

	_brain = new Brain(idea);
	std::cout << _ITALIC "Cat String Parametric Constructor called" _END << std::endl;
	return;
}

Cat::Cat( Cat const & src ) {

	std::cout << _ITALIC "Cat Copy Constructor called" _END << std::endl;
	*this = src;
	this->_brain = new Brain(*src._brain);

	return;
}

Cat::~Cat(void) {

	delete _brain;
	std::cout << _ITALIC "Cat Destructor called" << std::endl;
	return;
}

Cat & Cat::operator=( Cat const & rhs ) {
	
	std::cout << _ITALIC "Cat Copy Assignement operator called" _END << std::endl;
	if (this != &rhs)
	{
		this->_type = rhs._type;
		this->_brain = rhs._brain;
	}
	return *this;

}

void	Cat::makeSound() const {
	std::cout << _SALMON << " *meows* " _END << std::endl;

}

std::string	Cat::getType(void) const {
	return _type;
}

std::string	Cat::getIdea(int index) const {
	return _brain->getIdea(index);
}

