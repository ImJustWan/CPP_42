#include "ScavTrap.hpp"
#include "colors.hpp"

ScavTrap::ScavTrap() {

	std::cout << _ITALIC "ScavTrap Constructor called" _END << std::endl;
	setStart("");
	return;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {

	std::cout << _ITALIC "ScavTrap String Parametric Constructor called (" << name << ")" _END << std::endl;
	setStart(name);
	return;
}

ScavTrap::ScavTrap( ScavTrap const & src ) : ClapTrap(src) {

	std::cout << _ITALIC "Copy Constructor called" _END << std::endl;
	setStart(src._name);
	*this = src;
	return;
}

ScavTrap::~ScavTrap(void) {

	std::cout << _ITALIC "ScavTrap Destructor called (" << getName() << ")" _END << std::endl;
	return;
}


ScavTrap & ScavTrap::operator=( ScavTrap const & n ) {
	
	std::cout << _ITALIC "ScavTrap Copy Assignement operator called" _END << std::endl;
	_name = n._name;
	_hitPts = n._hitPts;
	_nrgPts = n._nrgPts;
	_atkDmg = n._atkDmg;
	return *this;

}

void	ScavTrap::setStart(std::string name) {

	_name = name;
	_hitPts = 100;
	_nrgPts = 50;
	_atkDmg = 20;

}

void	ScavTrap::attack(const std::string& target)
{
	if (_nrgPts > 0)
	{
		std::cout << _BOLD _SALMON "\n" << getName() << "(ScavTrap) attacks ! 〈ง ᓀ‸ᓂ〉ง " _END << std::endl;
		if (_hitPts == 0)
		{
			std::cout << "ScavTrap has no Hit Points left, the attack failed..." << std::endl;
			return;
		}
		std::cout << target << " took an uppercut (ง◉_◉)ง" << std::endl;
		takeDamage(_atkDmg);
		std::cout << _ITALIC _GREY "(attack cost) Energy points : " << _nrgPts;
		_nrgPts--;
		std::cout << " ➔ " << _nrgPts << "\n" _END << std::endl;
	}
	else
		std::cout << "\nScavTrap has no Energy points left, they can't attack ε-(´・｀)\n" << std::endl;

}

void	ScavTrap::guardGate() {
		std::cout << _BOLD _ITALIC _CYAN << getName() << " was never intended to create violence, they're now in Gate Keeper Mode. (￣^￣)ゞ\n" _END << std::endl;

}
