#include "HumanA.hpp"

HumanA::HumanA( std::string name, Weapon weaponName ) : _name( name ), weapon( weaponName ) {

	std::cout << "Constructor called" << std::endl;
	return;
}

HumanA::~HumanA( void ) {

	std::cout << "Destructor called" << std::endl;
	return;
}

void	HumanA::attack( void ) {

	std::cout << this->_name << " is attacking !" << std::endl;
	return;
}

