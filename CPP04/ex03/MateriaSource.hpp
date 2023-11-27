#pragma once

#include <iostream>
#include <string>
#include "colors.hpp"
#include "AMateria.hpp"
#include "ICharacter.hpp"
#include "IMateriaSource.hpp"

class AMateria;

class MateriaSource : public IMateriaSource
{
	public:

		MateriaSource();
		MateriaSource(MateriaSource const & src);
		~MateriaSource();

		MateriaSource	&operator=( MateriaSource const & rhs );

		void 			learnMateria(AMateria* m);
		AMateria*		createMateria(std::string const & type);

	private:
		AMateria		*_spellBook[4];
		int 			_nbSpells;

};
