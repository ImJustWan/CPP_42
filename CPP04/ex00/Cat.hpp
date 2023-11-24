#pragma once

#include <iostream>
#include "Animal.hpp"

class Cat : public Animal {

public:

	Cat();
	Cat(Cat const & src);
	Cat(std::string type);
	~Cat();

	Cat 		&operator=( Cat const & rhs );

	virtual std::string		getType(void) const;

private:
	virtual void	makeSound() const;
	std::string		_type;
};
