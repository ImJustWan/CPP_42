#include "Weapon.hpp"

Weapon::Weapon( std::string weapon ) : _weaponType( weapon ) {

	// std::cout << "Constructor called" << std::endl;
	return;
}

Weapon::~Weapon( void ) {

	// std::cout << "Destructor called" << std::endl;
	return;
}

const std::string&	Weapon::getType ( void ) const {

	return _weaponType;
}

void    Weapon::setType ( std::string newWeapon ) {

	this->_weaponType = newWeapon;
	// std::cout << "Weapon's type is " << newWeapon << std::endl;
	return;
}
