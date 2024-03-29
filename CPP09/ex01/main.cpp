#include "RPN.hpp"

int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cout << _SALMON _BOLD "Wrong arguments !" _END << std::endl;
		return 1;
	}
	
	try {
		RPN LaStack;
		LaStack.mathing(av);
	}
	catch(const std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	return 0;
}