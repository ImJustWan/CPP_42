#include "DiamondTrap.hpp"
#include "colors.hpp"

DiamondTrap::DiamondTrap() : ClapTrap(), ScavTrap(), FragTrap()  {

	std::cout << _ITALIC "DiamondTrap Constructor called" _END << std::endl;
	return;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name), ScavTrap(name), FragTrap(name) {

	std::cout << _ITALIC "DiamondTrap String Parametric Constructor called (" << name << ")" _END << std::endl;
	setStart();
	return;
}

DiamondTrap::DiamondTrap( DiamondTrap const & src ) : ClapTrap(src), ScavTrap(src), FragTrap(src) {

	std::cout << _ITALIC "Copy Constructor called" _END << std::endl;
	setStart();
	*this = src;
	return;
}

DiamondTrap::~DiamondTrap(void) {

    std::cout << _ITALIC "DiamondTrap Destructor called (" << getName() << ")" _END << std::endl;
    return;
}

DiamondTrap & DiamondTrap::operator=( DiamondTrap const & n ) {
	
	std::cout << _ITALIC "DiamondTrap Copy Assignement operator called" _END << std::endl;
	ClapTrap::operator=(n);
	setStart();
	return *this;

}

void	DiamondTrap::setStart(void) {

	_hitPts = FragTrap::_hitPts;
	_nrgPts = ScavTrap::_nrgPts;
	_atkDmg = FragTrap::_atkDmg;
}

void	DiamondTrap::whoAmI(void) {

	std::cout << _BOLD _CYAN _ITALIC "Cries in existential crisis" _END << std::endl;
}