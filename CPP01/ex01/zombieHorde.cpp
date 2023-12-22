#include "Zombie.hpp"

void	Zombie::setName( std::string name ) {

	this->_name = name;
	this->announce();
	return;
}

Zombie* zombieHorde( int N, std::string name ) {

	Zombie*	zombiez = new Zombie[N];

	for (int i = 0; i < N; i++) {
		zombiez[i].setName( name );
	}

	return zombiez;
}