#include "Zombie.hpp"

Zombie::Zombie( void ) {

	std::cout << "Constructor called" << std::endl;
	return;
}

Zombie::~Zombie( void ) {

	std::cout << "Destructor called" << std::endl;
	return;
}

void	Zombie::announce( void ) const {

	std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;

}
