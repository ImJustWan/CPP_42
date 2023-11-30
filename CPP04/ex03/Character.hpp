#pragma once

#include <iostream>
#include <string>
#include "colors.hpp"
#include "AMateria.hpp"
#include "ICharacter.hpp"
#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"

class AMateria;
class MateriaSource;

class Character : public ICharacter
{
	public:

		Character();
		Character(std::string const & name);
		Character(Character const & src);
		~Character();

		Character			&operator=( Character const & rhs );

		std::string const &	getName() const;
		void				equip(AMateria* m);
		void				unequip(int idx);
		void				use(int idx, ICharacter& target);

	private:
		std::string			_name;
		AMateria			*_inventory[4];
		int 				_takenSpots;
};
