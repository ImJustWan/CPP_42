#include <iostream>
#include <string.h>
#include <string>
#include "Zombie.hpp"

int main(int ac, char **av) {

	if (ac != 2 || strlen(av[1]) == 0)
		std::cout << "Choose a name for your Zombie pet !" << std::endl;
	else
		Zombie::randomChump( av[1] );
	return 0;
}