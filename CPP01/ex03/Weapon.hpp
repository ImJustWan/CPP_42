#ifndef WEAPON_HPP
# define WEAPON_HPP

#include <iostream>
#include <string>

class Weapon {

	public:
		Weapon( std::string weapon);
		~Weapon();
		void    setType ( std::string newWeapon );
        std::string _weaponName;

	private:

};

#endif