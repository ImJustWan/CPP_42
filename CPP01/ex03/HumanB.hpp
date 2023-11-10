#ifndef HUMANB_HPP
# define HUMANB_HPP

#include <iostream>
#include <string>
#include "Weapon.hpp"

class HumanB {

	public:
		HumanB( std::string name );
		~HumanB();
		void    attack();
		void    setWeapon ( Weapon newWeapon );

	private:
		std::string _name;

};

#endif