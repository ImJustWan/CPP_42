#include "FragTrap.hpp"
#include "colors.hpp"

FragTrap::FragTrap() {

	std::cout << _ITALIC "FragTrap Constructor called" _END << std::endl;
	_hitPts = 100;
	_nrgPts = 50;
	_atkDmg = 20;
	return;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name) {

	std::cout << _ITALIC "FragTrap String Parametric Constructor called (" << name << ")" _END << std::endl;
	_hitPts = 100;
	_nrgPts = 50;
	_atkDmg = 20;
	return;
}

FragTrap::FragTrap( FragTrap const & src ) : ClapTrap(src) {

	std::cout << _ITALIC "Copy Constructor called" _END << std::endl;
	*this = src;
	return;
}

FragTrap::~FragTrap(void) {

    std::cout << _ITALIC "FragTrap Destructor called (" << getName() << ")" _END << std::endl;
    return;
}


FragTrap & FragTrap::operator=( FragTrap const & n ) {
	
	std::cout << _ITALIC "FragTrap Copy Assignement operator called" _END << std::endl;
	_name = n._name;
	_hitPts = n._hitPts;
	_nrgPts = n._nrgPts;
	_atkDmg = n._atkDmg;
	return *this;

}

void	FragTrap::attack(const std::string& target)
{
	if (_nrgPts > 0)
	{
		std::cout << _BOLD _SALMON "\n" << getName() << "(FragTrap) attacks ! 〈ง ᓀ‸ᓂ〉ง " _END << std::endl;
		if (_hitPts == 0)
		{
			std::cout << "FragTrap has no Hit Points left, the attack failed..." << std::endl;
			return;
		}
		std::cout << target << " took an high kick ( #`⌂´)/┌┛" << std::endl;
		takeDamage(_atkDmg);
		std::cout << _ITALIC _GREY "(attack cost) Energy points : " << _nrgPts;
		_nrgPts--;
		std::cout << " ➔ " << _nrgPts << "\n" _END << std::endl;
	}
	else
		std::cout << "\nFragTrap has no Energy points left, they can't attack ε-(´・｀)\n" << std::endl;

}

void    FragTrap::highFivesGuys() {
		std::cout << _BOLD _ITALIC _RIVIERA << getName() << " chose peace, and is now proposing a high five ヽ(○｀･v･)人(･v･´●)ﾉ\n" _END << std::endl;

}
