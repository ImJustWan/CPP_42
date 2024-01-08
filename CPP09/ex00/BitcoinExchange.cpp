#include "BitcoinExchange.hpp"
#include "colors.hpp"

BitcoinExchange::BitcoinExchange() {
	return;
}

BitcoinExchange::BitcoinExchange(char *inputName)
{
	std::ifstream	inputFile(inputName);
	if (!inputFile.is_open())
		throw BitcoinExchange::InaccessibleFile();
	this->_infileName = inputName;

	// inputFile.close();
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
	while (std::getline(dataBase, buf)) // each line of data.csv into buf
	{
		std::stringstream	streamBuf(buf); // buf into stream for manipulation
		std::string			date;
		float				value;
		// extract string from streamBuf up to ',', stored into date
		// rest of streamBuf = value
		if (std::getline(streamBuf, date, ',') && streamBuf >> value) {
			this->_btcRates[date] = value;
		}
	}
	dataBase.close();
}

bool	BitcoinExchange::checkDate(std::string date)
{
	std::istringstream	dateStream(date);
	int					year, month, day;
	char				dash;
	bool				ret = true;

	dateStream >> year >> dash>> month >> dash >> day;
	if (dateStream.fail() || dash != '-')
		ret = false;
	if (year < 2009 || year > 2024 || month < 1 || month > 12 || day < 1 || day > 31)
		ret = false;
	if (year == 2024 && (month != 1 || (month == 1 && day > 20)))
		ret = false;
	if (day == 31 && ((month <= 7 && month % 2 == 0) || (month >= 8 && month % 2 != 0)))
		ret = false;
	if (day > 29 && month == 2)
		ret = false;
	if (year == 2009 && month == 01 && day == 01)
		ret = false;
	if (month == 2 && day == 29)
	{
		if (year % 400 == 0 || (year % 4 == 0 && year != 100))
			ret = true;
		ret = false;
	}
	if (ret == false)
	{
		std::cout << _ITALIC _GREY << "(" << date << ")\t" _END;
		return false;
	}
	return true;
}

float	BitcoinExchange::getValueAtDate(std::string date)
{
	std::map<std::string, float>::iterator it = this->_btcRates.find(date);

	if (it != this->_btcRates.end())
		return this->_btcRates[date];

	it = this->_btcRates.lower_bound(date);
	if (it != this->_btcRates.end())
		return it->second;
	it--;
	return it->second;
}

void	BitcoinExchange::priceConversion(std::string date, float value)
{
	float	rate;

	if (!date.empty() && date[date.length() - 1] == ' ') {
		date.erase(date.length() - 1);
	}

	if (this->checkDate(date) == false)
		throw BitcoinExchange::InvalidDate();
	if (value <= 0)
	{
		std::cout << _ITALIC _GREY << "(" << value << ")\t\t" _END;
		throw BitcoinExchange::NegativeNumber();
	}
	if (value > 1000.0)
	{
		std::cout << _ITALIC _GREY << "(" << value << ")\t" _END;
		throw BitcoinExchange::TooBigNumber();
	}
	rate = this->getValueAtDate(date);
	std::cout << date << "\t⟶\t";
	std::cout << value * this->getValueAtDate(date);
	std::cout << _GREY "\t(" << value << ")" _END << std::endl;

}

void	BitcoinExchange::handleInput()
{
	std::ifstream	inputFile(this->_infileName.c_str());

	std::string	buf;
	while (std::getline(inputFile, buf)) // reads each line of input.txt
	{
		std::stringstream	streamBuf(buf); // buf into stream for manipulation
		std::string			date;
		float				value;

		if (buf.empty()){ std::cout << std::endl; }
		// extract string from streamBuf up to ',', stored into date
		// rest of streamBuf = value
		else if (buf.find(" | ") == std::string::npos) {
			std::cout << _SALMON "Wrong format ! Accepted : is date | value" _END << std::endl; 
		}date | value

2009-05-28 | 1.2
2009-10-14 | 1.2
2011-08-08 | 1.2
2012-12-12 | 1.2
2015-09-07 | 1.2
2018-09-07 | 1.2
2020-11-05 | 1.2
2022-03-29 | 0.1
2024-01-08 | 0.1


2024-03-08 | 0.1
2001-09-11 | 1.1
2017-02-29 | 3.6
2018-14-15 | 3.6
2018-07-42 | 3.6
2025-03-29 | 0.1
2010-01-01 | -0.2
2010-01-01 | -3.14
2010-01-01 | 1000.1
2010-01-01 | 2147483647


		else if (std::getline(streamBuf, date, '|') && streamBuf >> value) {
			try {
				priceConversion(date, value);
			}
			catch(const std::exception &e) {
				std::cout << e.what() << std::endl;
			}
		}
	}
	return ;
}
