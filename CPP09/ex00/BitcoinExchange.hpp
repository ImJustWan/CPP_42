#pragma once

#include "colors.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <map>

class BitcoinExchange {
	
	private:
		std::map<std::string, float>	_btcRates; //csv
		std::string						_infileName; //input.txt

		BitcoinExchange(void);
		BitcoinExchange(BitcoinExchange &src);
		BitcoinExchange &operator=(BitcoinExchange const & rhs);

	public:

		BitcoinExchange(char *inputName);
		~BitcoinExchange();

		void	priceConversion();

	class InaccessibleFile : public std::exception
	{
		public:
			virtual const char * what() const throw() {
				return(_RED _BOLD "❌  Could not access the file\n" _END);
			}
	};
};


//Exception
// Error: not a positive number.
// Error: bad input => 2001-42-42
// Error: too large a number