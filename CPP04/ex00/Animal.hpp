#pragma once

#include <iostream>

class Animal {

public:

	Animal();
	Animal(Animal const & src);
	Animal(std::string type);
	virtual ~Animal();

	Animal & operator=( Animal const & rhs );

	virtual void			makeSound() const;
	virtual std::string		getType() const;

protected:
	std::string	_type;

};
