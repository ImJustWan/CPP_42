#include "Zombie.hpp"

void Zombie::randomChump( std::string name ) {

	Zombie	newOne( name );

	newOne.announce() ;
	return;
}