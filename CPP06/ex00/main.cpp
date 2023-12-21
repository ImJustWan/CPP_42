#include "ScalarConverter.hpp"

int main(int ac, char **av)
{
	if (ac != 2 || (av[1] && strlen(av[1]) == 0)) {
		std::cout << "./convert takes one argument, thank you." << std::endl;
		return 1;
	}
	ScalarConverter::convert(av[1]);
	return 0;
}
