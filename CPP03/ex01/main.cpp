#include "colors.hpp"
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include <iostream>

int main( void )
{
	// ClapTrap Jade("Jade");

	// Jade.attack("Random dummy");
	// Jade.setNrgPoints(1);
	// Jade.beRepaired(1);
	// Jade.attack("Yet another dummy");
	// Jade.setNrgPoints(5);
	// Jade.setAtkDmg(8);
	// Jade.attack("Another dummy ?!");

	ScavTrap Wan("Wan");
	Wan.attack("Capitalism");
	Wan.setNrgPoints(3);
	Wan.setAtkDmg(50);
	Wan.beRepaired(3);
	Wan.guardGate();

	return 0;
}