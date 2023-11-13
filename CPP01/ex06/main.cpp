#include <iostream>
#include <string.h>
#include <string>
#include "Harl.hpp"

int main(int ac, char **av)
{
	Harl	Harlington;

	if (ac == 1)
		Harlington.complain( "gancho" );
	if (ac == 2)
		Harlington.complain( av[1] );
	return 0;
}
