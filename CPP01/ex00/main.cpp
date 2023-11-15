#include <iostream>
#include <string.h>
#include <string>
#include "Zombie.hpp"

int main(int ac, char **av) {

	Zombie *ZombiePtr;

	if (ac != 2 || strlen(av[1]) == 0)
		std::cout << "Choose a name for your Zombie pet !" << std::endl;
	else
	{
		Zombie::randomChump("RandomChump");
		ZombiePtr = Zombie::newZombie(av[1]);
		ZombiePtr->announce();
		delete ZombiePtr;
	}
	return 0;
}