#include <iostream>
#include <string.h>
#include <string>
#include <stdlib.h>
#include <unistd.h>
#include "Zombie.hpp"

int main(int ac, char **av) {

	// else

	if (ac != 3 || strlen(av[1]) == 0 || strlen(av[2]) == 0)
	{
		std::cout << "Choose a name for your army 🧟 !" << std::endl;
		return 0;
	}
	Zombie* horde = zombieHorde( atoi(av[1]) , av[2] );

	delete [] horde;
	return 0;
}