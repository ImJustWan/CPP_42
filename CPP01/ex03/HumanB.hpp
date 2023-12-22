#pragma once

#include <iostream>
#include <string>
#include "Weapon.hpp"

class HumanB {

	public:
		HumanB( std::string name );
		~HumanB();
		void	setWeapon ( const Weapon& weaponRef );
		void	attack();

	private:
		std::string		_name;
		const Weapon*	_weapon;

};
