#pragma once

#include <iostream>
#include <string>
#include "colors.hpp"
#include "AMateria.hpp"
#include "ICharacter.hpp"
#include "IMateriaSource.hpp"

class Ice : public AMateria
{
	public:

		Ice();
		Ice(std::string const & type);
		Ice(Ice const & src);
		~Ice();

		Ice		&operator=( Ice const & rhs );
		
		AMateria*			clone() const;
		void				use(ICharacter& target);
};
