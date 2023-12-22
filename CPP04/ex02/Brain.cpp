#include "Brain.hpp"
#include "colors.hpp"

Brain::Brain() {

	std::cout << _ITALIC "Brain Constructor called" _END << std::endl;
	return;
}

Brain::Brain(std::string idea) {

	// std::cout << _ITALIC "Brain String Parametric Constructor called" _END << std::endl;
	for (int i = 0; i < 100; i++)
		_ideas[i] = idea;
	return;
}

Brain::Brain( Brain const & src ) {

	std::cout << _ITALIC "Brain Copy Constructor called" _END << std::endl;
	*this = src;
	return;
}

Brain::~Brain(void) {

	std::cout << _ITALIC "Brain Destructor called" << std::endl;
	return;
}

Brain & Brain::operator=( Brain const & rhs ) {
	
	std::cout << _ITALIC "Brain Copy Assignement operator called" _END << std::endl;
	for (int i = 0; i < 100; i++)
		this->_ideas[i] = rhs._ideas[i]; 
	return *this;

}

std::string Brain::getIdea(int index) const
{
	return _ideas[index];
}
