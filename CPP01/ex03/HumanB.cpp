#include "HumanB.hpp"

HumanB::HumanB( std::string name ) : _name( name) {

	std::cout << "Constructor called" << std::endl;
	return;
}

HumanB::~HumanB( void ) {

	std::cout << "Destructor called" << std::endl;
	return;
}

void	HumanB::attack( void ) {

	std::cout << this->_name << " is attacking !" << std::endl;

}

void    HumanB::setWeapon ( Weapon newWeapon ) {

    std::cout << "HumanB's new weapon is " << newWeapon._weaponName << std::endl;
	return;
}
