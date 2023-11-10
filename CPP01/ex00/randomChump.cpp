#include "Zombie.hpp"

void Zombie::randomChump( std::string name ) {

	Zombie*	newOne = newZombie(name);

	newOne->announce() ;
	delete newOne;
	return;
}