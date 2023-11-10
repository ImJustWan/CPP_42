#include "Weapon.hpp"

Weapon::Weapon( std::string weapon ) : _weaponName( weapon ) {

	std::cout << "Constructor called" << std::endl;
	return;
}

Weapon::~Weapon( void ) {

	std::cout << "Destructor called" << std::endl;
	return;
}

void    Weapon::setType ( std::string newWeapon ) {

	std::cout << "Weapon's type is " << newWeapon << std::endl;
	return;
}
