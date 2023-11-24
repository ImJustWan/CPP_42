#pragma once

#include <iostream>
#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal {

public:

	Cat();
	Cat(Cat const & src);
	Cat(std::string ideas);
	~Cat();

	Cat				&operator=( Cat const & rhs );

	std::string		getType(void) const;
	std::string		getIdea(int index) const;

private:
	void			makeSound() const;
	std::string		_type;
	Brain			*_brain;

};
