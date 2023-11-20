#include <iostream>
#include <string.h>
#include <string>
#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"

int main()
{
	{
		Weapon club = Weapon("a wrench");
		HumanA mustard("Colonel Mustard", club);
		mustard.attack();
		club.setType("a candlestick");
		mustard.attack();
	}
	{
		Weapon club = Weapon("a revolver");
		HumanB rose("Mademoiselle Rose");
		rose.attack();
		rose.setWeapon(club);
		club.setType("a dagger");
		rose.attack();
	}
	return 0;
}

// int main()
// {
// 	{
// 		Weapon club = Weapon("crude spiked club");
// 		HumanA bob("Bob", club);
// 		bob.attack();
// 		club.setType("some other type of club");
// 		bob.attack();
// 	}
// 	{
// 		Weapon club = Weapon("crude spiked club");
// 		HumanB jim("Jim");
// 		jim.attack();
// 		jim.setWeapon(club);
// 		club.setType("some other type of club");
// 		jim.attack();
// 	}
// 	return 0;
// }
