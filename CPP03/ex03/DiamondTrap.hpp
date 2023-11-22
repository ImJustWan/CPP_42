#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

#include <iostream>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap {

public:

	DiamondTrap();
	DiamondTrap(std::string name);
	DiamondTrap(DiamondTrap const & src);
	~DiamondTrap();

	DiamondTrap & operator=( DiamondTrap const & rhs );

	void	setStart(void);
	void	whoAmI(void);
	// void	ScavTrap::attack(const std::string& target);
 
};

#endif