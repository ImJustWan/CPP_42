#pragma once

#include <iostream>
#include <string>
#include "colors.hpp"
#include "ICharacter.hpp"
#include "IMateriaSource.hpp"

class ICharacter;

class AMateria
{
	private:
		std::string		_type;

	public:
		AMateria();
		AMateria(AMateria const & src);
		AMateria(std::string const & type);
		virtual ~AMateria();

		AMateria	&operator=( AMateria const & rhs );

		std::string const 		&getType() const; //Returns the materia type
		void						setType (std::string const type);

		virtual AMateria*	clone() const = 0;
		virtual void 		use(ICharacter& target) = 0;
};	