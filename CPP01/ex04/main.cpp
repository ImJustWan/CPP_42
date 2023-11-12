#include <iostream>
#include <string.h>
#include <string>
#include "Stringz.hpp"

int main(int ac, char **av) {

	if (ac != 4 || strlen(av[1]) == 0 || strlen(av[2]) == 0)
		std::cout << "Wrong arguments ! At least choose a filename and a string to be replaced in that file :]" << std::endl;
	else
		replaceStrings(av[1], av[2], av[3]);
	return 0;
}