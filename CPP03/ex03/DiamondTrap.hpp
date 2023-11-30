#pragma once

#include <iostream>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap : public virtual ScavTrap, public virtual FragTrap {

public:

	DiamondTrap();
	DiamondTrap(std::string name);
	DiamondTrap(DiamondTrap const & src);
	~DiamondTrap();

	DiamondTrap & operator=( DiamondTrap const & rhs );

	void	setStart(std::string name);
	void	whoAmI(void);
	void	attack(const std::string& target);

private:
	std::string	_name;

};
