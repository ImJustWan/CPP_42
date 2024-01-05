#include "BitcoinExchange.hpp"

int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cout << _SALMON _BOLD "Wrong arguments !" _END << std::endl;
		std::cout << "Usage: ./btc input.txt" << std::endl;
		return 1;
	}
	try {
		BitcoinExchange test(av[1]);
		test.createDatabase();
		test.priceConversion();
	}
	catch(const BitcoinExchange::InaccessibleFile e) {
		std::cout << e.what() << std::endl;
	}
	return 0;
}