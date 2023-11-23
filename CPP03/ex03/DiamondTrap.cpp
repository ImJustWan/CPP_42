#include "DiamondTrap.hpp"
#include "colors.hpp"

DiamondTrap::DiamondTrap() : ClapTrap("Random_clap_name")  {

	std::cout << _ITALIC "DiamondTrap Constructor called" _END << std::endl;
	return;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name") {

	std::cout << _ITALIC "DiamondTrap String Parametric Constructor called (" << name << ")" _END << std::endl;
	setStart(name);
	return;
}

DiamondTrap::DiamondTrap( DiamondTrap const & src ) : ClapTrap(src._name) {

	std::cout << _ITALIC "Copy Constructor called" _END << std::endl;
	setStart(src._name);
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
	setStart(n._name);
	return *this;

}

void	DiamondTrap::setStart(std::string name) {

	_name = name;
	_hitPts = FragTrap::_hitPts;
	_nrgPts = ScavTrap::_nrgPts;
	_atkDmg = FragTrap::_atkDmg;

}

void	DiamondTrap::attack(const std::string& target) {
	ScavTrap::attack(target);
}

void	DiamondTrap::whoAmI(void) {

	// std::cout << "hit : " << _hitPts << std::endl;
	// std::cout << "nrg : " << _nrgPts << std::endl;
	// std::cout << "atk : " << _atkDmg << std::endl; 
	
	std::cout << _BOLD _CYAN _ITALIC << _name << " cries in existential crisis" << std::endl;
	std::cout << ClapTrap::_name << " cries in ClapTrap existential crisis" << _END << std::endl;

}