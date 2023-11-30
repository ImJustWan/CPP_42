#pragma once

#include <iostream>
#include <string>

class Zombie {

	public:
		Zombie();
		~Zombie();

		void	announce( void ) const;
		void    setName( std::string name );

	private:
		std::string _name;

};

Zombie* zombieHorde( int N, std::string name );
