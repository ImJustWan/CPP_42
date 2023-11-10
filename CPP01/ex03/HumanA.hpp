#ifndef HUMANA_HPP
# define HUMANA_HPP

#include <iostream>
#include <string>
#include "Weapon.hpp"

class HumanA {

	public:
		HumanA( std::string name, Weapon weaponName );
		~HumanA();
		void    attack();
		std::string _name;
		Weapon	weapon;

	private:
};

#endif