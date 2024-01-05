#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {
	return;
}



BitcoinExchange::BitcoinExchange(char *inputName)
{
	std::ifstream	inputFile(inputName);
	if (!inputFile.is_open())
		throw BitcoinExchange::InaccessibleFile();
	this->_infileName = inputName;
	inputFile.close();
}

BitcoinExchange::BitcoinExchange(BitcoinExchange &src) {
	(void)src;
}

BitcoinExchange::~BitcoinExchange() {
	return ;
}

BitcoinExchange &BitcoinExchange::operator=(BitcoinExchange const &rhs) {
	(void)rhs;
	return *this;
}

void	BitcoinExchange::createDatabase()
{
	std::ifstream	dataBase("data.csv");
	if (!dataBase.is_open())
		throw BitcoinExchange::InaccessibleFile();
	
	std::string	buf;
	while (std::getline(dataBase, buf)) // reads each line of data.csv
	{
		std::stringstream	streamBuf(buf); // buf into stream for manipulation
		std::string			date;
		float				value;
		// extract string from streamBuf up to ',', stored into date
		// rest of streamBuf = value
		if (std::getline(streamBuf, date, ',') && streamBuf >> value)
			this->_btcRates[date] = value;
	}
	dataBase.close();
}


void	BitcoinExchange::priceConversion()
{
	return ;
}
