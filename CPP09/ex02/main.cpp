#include "PmergeMe.hpp"

int main(int ac, char **av)
{
	(void)ac;
	try {
		PmergeMe LaStack;
		LaStack.parsing(ac, av);
		LaStack.algorithming();
	}
	catch(const std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	return 0;
}