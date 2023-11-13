#ifndef WEAPON_HPP
# define WEAPON_HPP

#include <iostream>
#include <string>

class Weapon {

	public:
		Weapon( std::string weapon);
		~Weapon();
		void   				setType ( std::string newWeapon );
		const std::string&	getType ( void ) const;
        std::string			_weaponType;

	private:

};

#endif