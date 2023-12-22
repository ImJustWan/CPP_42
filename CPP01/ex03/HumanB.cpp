#include "HumanB.hpp"
#include "colors.hpp"

HumanB::HumanB( std::string name ) : _name( name ), _weapon( NULL ){

	// std::cout << "Constructor called" << std::endl;
	return;
}

HumanB::~HumanB( void ) {

	// std::cout << "Destructor called" << std::endl;
	return;
}

void	HumanB::setWeapon ( const Weapon& weaponRef ) {
	this->_weapon = &weaponRef;
}

void	HumanB::attack( void ) {

	if ( this->_weapon != NULL )
		std::cout << _PINK << this->_name << " is attacking with " << this->_weapon->_weaponType << " !" _END << std::endl;
	else
		std::cout << _PINK << this->_name << " is trying to go barehands, fortunately she knows kung fu ノಠ_ಠノ" _END << std::endl;
}
