#include "colors.hpp"
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include <iostream>

int main( void )
{
	ClapTrap Jade("Jade");

	Jade.attack("Random dummy");
	Jade.setNrgPoints(1);
	Jade.beRepaired(1);

	FragTrap Wan("Wan");
	Wan.attack("Capitalism");
	// Wan.setNrgPoints(3);
	// Wan.setAtkDmg(50);
	Wan.beRepaired(3);
	Wan.highFivesGuys();

	return 0;
}