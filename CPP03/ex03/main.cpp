#include "colors.hpp"
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"
#include <iostream>

int main( void )
{
	ClapTrap Jade("Jade");
	Jade.beRepaired(1);

	ScavTrap Capu("Capu");
	Capu.guardGate();

	FragTrap Wan("Wan");
	Wan.highFivesGuys();

	DiamondTrap Celine("Celine");
	Celine.whoAmI();
	return 0;
}