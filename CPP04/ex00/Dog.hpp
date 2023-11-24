#pragma once

#include <iostream>
#include "Animal.hpp"

class Dog : public Animal {

public:

	Dog();
	Dog(Dog const & src);
	Dog(std::string type);
	~Dog();

	Dog 					&operator=( Dog const & rhs );

	std::string		getType(void) const;

private:
	void			makeSound() const;
	std::string		_type;
};
