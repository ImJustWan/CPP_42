#include "Zombie.hpp"

Zombie *Zombie::newZombie( std::string name ) {

	Zombie*	newOnePtr = new Zombie( name );
	return ( newOnePtr );
}
