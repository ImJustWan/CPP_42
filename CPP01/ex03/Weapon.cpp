#include "Weapon.hpp"
#include "colors.hpp"

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

	std::cout << _ITALIC "Weapon of choice is now " << newWeapon << "." _END << std::endl;
	this->_weaponType = newWeapon;
	return;
}
