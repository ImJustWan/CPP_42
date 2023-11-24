#pragma once

#include <iostream>
#include "Animal.hpp"
class Brain {

public:

	Brain();
	Brain(Brain const & src);
	Brain(std::string idea);
	virtual ~Brain();

	Brain & operator=( Brain const & rhs );
	std::string	getIdea(int index) const;

private:
	std::string _ideas[100];

};
