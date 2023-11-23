#include "colors.hpp"
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int main( void )
{
	ClapTrap Jade("Jade");
	Jade.attack("Jean-Loup");
	Jade.beRepaired(1);

	std::cout << "------------------------";
	std::cout << "------------------------\n" << std::endl;

	ScavTrap Capu("Capu");
	Capu.attack("Marie");
	Capu.guardGate();
	
	std::cout << "------------------------";
	std::cout << "------------------------\n" << std::endl;

	FragTrap Wan("Wan");
	Wan.attack("Pjay");
	Wan.highFivesGuys();
	
	std::cout << "------------------------";
	std::cout << "------------------------\n" << std::endl;

	DiamondTrap Celine("Celine");
	Celine.attack("Someone else");
	Celine.guardGate();
	Celine.highFivesGuys();
	Celine.whoAmI();

	return 0;
}