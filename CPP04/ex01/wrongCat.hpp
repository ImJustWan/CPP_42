#pragma once

#include <iostream>
#include "wrongAnimal.hpp"

class wrongCat : public wrongAnimal {

public:

	wrongCat();
	wrongCat(wrongCat const & src);
	wrongCat(std::string type);
	~wrongCat();

	wrongCat 		&operator=( wrongCat const & rhs );

	std::string		getType(void) const;
	void			makeSound() const;

private:
	std::string		_type;
};
