#include "HumanA.hpp"

HumanA::HumanA( std::string name, const Weapon& weaponName ) : _name( name ), _weapon( weaponName ) {

	// std::cout << "Constructor called" << std::endl;
	return;
}

HumanA::~HumanA( void ) {

	// std::cout << "Destructor called" << std::endl;
	return;
}

void	HumanA::attack( void ) {

	std::cout << this->_name << " is attacking with " << this->_weapon._weaponName << std::endl;
	return;
}

