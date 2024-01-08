#pragma once

#include "colors.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <map>
#include <limits.h>


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

		void	handleInput();
		void	createDatabase();
		bool	checkDate(std::string date);
		float	getValueAtDate(std::string date);
		void	priceConversion(std::string date, float value);

	class InaccessibleFile : public std::exception
	{
		public:
			virtual const char * what() const throw() {
				return(_RED _BOLD "❌  Could not access the file\n" _END);
			}
	};

	class InvalidDate : public std::exception
	{
		public:
			virtual const char * what() const throw() {
				return(_SALMON "Invalid date" _END);
			}
	};

	class NegativeNumber : public std::exception
	{
		public:
			virtual const char * what() const throw() {
				return(_SALMON "Not a positive number" _END);
			}
	};

	class TooBigNumber : public std::exception
	{
		public:
			virtual const char * what() const throw() {
				return(_SALMON "Error: too large a number." _END);
			}
	};
};


//Exception
// Error: not a positive number.
// Error: bad input => 2001-42-42
// Error: too large a number