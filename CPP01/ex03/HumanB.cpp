#include "HumanB.hpp"

HumanB::HumanB( std::string name ) : _name( name ), _weapon( NULL ){

	// std::cout << "Constructor called" << std::endl;
	return;
}

HumanB::~HumanB( void ) {

	// std::cout << "Destructor called" << std::endl;
	return;
}

void    HumanB::setWeapon ( const Weapon& weaponRef ) {

	this->_weapon = &weaponRef;
    // std::cout << "HumanB's weapon is " << weaponRef._weaponType << std::endl;
	return;
}

void	HumanB::attack( void ) {

	if ( this->_weapon != NULL )
		std::cout << this->_name << " is attacking with " << this->_weapon->_weaponType << std::endl;

}
