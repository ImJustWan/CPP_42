#ifndef HUMANA_HPP
# define HUMANA_HPP

#include <iostream>
#include <string>
#include "Weapon.hpp"

class HumanA {

	public:
		HumanA( std::string name, const Weapon& weaponName );
		~HumanA();
		void    attack();

	private:
		std::string 	_name;
		const Weapon&	_weapon;
};

#endif