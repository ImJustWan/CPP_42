#pragma once

#include <iostream>
#include <string>
#include "colors.hpp"
#include "AMateria.hpp"
#include "ICharacter.hpp"
#include "IMateriaSource.hpp"

class Cure : public AMateria
{
	public:

		Cure();
		Cure(std::string const & type);
		Cure(Cure const & src);
		~Cure();

		Cure		&operator=( Cure const & rhs );

		AMateria*			clone() const;
		void				use(ICharacter& target);
};
