#pragma once

#include <iostream>
#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap {

public:

	ScavTrap();
	ScavTrap(std::string name);
	ScavTrap(ScavTrap const & src);
	~ScavTrap();

	ScavTrap & operator=( ScavTrap const & rhs );

	void	attack(const std::string& target);
	void    guardGate();

protected:
	int	_nrgPts;
};
