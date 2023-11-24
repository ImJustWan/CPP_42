#pragma once

#include <iostream>
#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal {

public:

	Dog();
	Dog(Dog const & src);
	Dog(std::string type);
	~Dog();

	Dog 				&operator=( Dog const & rhs );

	std::string			getType(void) const;
	std::string			getIdea(int index) const;

private:
	void			makeSound() const;
	Brain			*_brain;
	std::string		_type;
};
