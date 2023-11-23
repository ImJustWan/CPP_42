#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include <iostream>
#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {

public:

	ScavTrap();
	ScavTrap(std::string name);
	ScavTrap(ScavTrap const & src);
	~ScavTrap();

	ScavTrap & operator=( ScavTrap const & rhs );

	void	attack(const std::string& target);
    void    guardGate();
	void	setStart(std::string name);

};

#endif