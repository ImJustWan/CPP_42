#pragma once

#include <iostream>

class wrongAnimal {

public:

	wrongAnimal();
	wrongAnimal(wrongAnimal const & src);
	wrongAnimal(std::string type);
	virtual ~wrongAnimal();

	wrongAnimal & operator=( wrongAnimal const & rhs );

	void			makeSound() const;
	std::string		getType() const;

protected:
	std::string	_type;

};