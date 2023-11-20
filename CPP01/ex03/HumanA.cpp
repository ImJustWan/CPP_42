#include "HumanA.hpp"
#include "colors.hpp"

HumanA::HumanA( std::string name, const Weapon& weaponName ) : _name( name ), _weapon( weaponName ) {

	// std::cout << "Constructor called" << std::endl;
	return;
}

HumanA::~HumanA( void ) {

	// std::cout << "Destructor called" << std::endl;
	return;
}

void	HumanA::attack( void ) {

	std::cout << _YELLOW << this->_name << " is attacking with " << this->_weapon._weaponType << " !" _END << std::endl;
	return;
}
