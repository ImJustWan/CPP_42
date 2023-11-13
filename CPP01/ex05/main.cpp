#include <iostream>
#include <string.h>
#include <string>
#include "Harl.hpp"

void	test(Harl Harlington)
{
	std::cout << "\n➤ Just trying some silly stuff !\n" << std::endl;
	Harlington.complain("DEBUG");
	std::cout << "➤ Ok but can you at least help me with that mess ?\n" << std::endl;
	Harlington.complain("INFO");
	std::cout << "➤ You're crossing the line. Do you wanna fight ?!\n" << std::endl;
	Harlington.complain("WARNING");
	std::cout << "➤ That's enough, I'm shutting you off NOW\n" << std::endl;
	Harlington.complain("ERROR");
}

int main(int ac, char **av)
{
	Harl	Harlington;

	if (ac == 1)
		test( Harlington );
	if (ac == 2)
		Harlington.complain( av[1] );
	return 0;
}
