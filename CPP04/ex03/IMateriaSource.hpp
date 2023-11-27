#pragma once

#include <iostream>
#include <string>
#include "colors.hpp"
#include "AMateria.hpp"
#include "ICharacter.hpp"

class AMateria;

class IMateriaSource
{
	public:
		IMateriaSource();
		IMateriaSource(IMateriaSource const & src);
		virtual ~IMateriaSource();
		virtual void learnMateria(AMateria*) = 0;
		virtual AMateria* createMateria(std::string const & type) = 0;
};
