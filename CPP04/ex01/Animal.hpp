#pragma once

#include <iostream>

class Animal {

public:

	Animal();
	Animal(Animal const & src);
	Animal(std::string type);
	virtual ~Animal();

	Animal & operator=( Animal const & rhs );

	virtual std::string		getType() const;
	virtual std::string		getIdea(int index) const;

protected:
	virtual void			makeSound() const;
	std::string				_type;

};
