#include "ScalarConverter.hpp"
#include <stdlib.h>
#include <string.h>

int ScalarConverter::_type = _INV;

ScalarConverter::ScalarConverter( void ) {

	std::cout << "Constructor called" << std::endl;
	return;
}

ScalarConverter::~ScalarConverter( void ) {

	std::cout << "Destructor called" << std::endl;
	return;
}


void	ScalarConverter::print_char(std::string brut)
{
	std::cout << "char	:	"	<< brut.at(0) << std::endl;
	std::cout << "int	:	"	<< "impossible" << std::endl;
	std::cout << "float	:	"	<< "impossible" << std::endl;
	std::cout << "double  :	"	<< "impossible" << std::endl;
}

void	ScalarConverter::print_int(std::string brut)
{
	(void)brut;
	std::cout << "char	:	"	<< "impossible" << std::endl;
	std::cout << "int	:	"	<< "INT " << std::endl;
	std::cout << "float	:	"	<< "impossible" << std::endl;
	std::cout << "double  :	"	<< "impossible" << std::endl;
}

void	ScalarConverter::print_float(std::string brut)
{
	(void)brut;
	std::cout << "char	:	"	<< "impossible" << std::endl;
	std::cout << "int	:	"	<< "impossible" << std::endl;
	std::cout << "float	:	"	<< "FLOAT" << std::endl;
	std::cout << "double  :	"	<< "impossible" << std::endl;
}

void	ScalarConverter::print_double(std::string brut)
{
	(void)brut;
	std::cout << "char	:	"	<< "impossible" << std::endl;
	std::cout << "int	:	"	<< "impossible" << std::endl;
	std::cout << "float	:	"	<< "impossible" << std::endl;
	std::cout << "double  :	"	<< "DOUBLE" << std::endl;
}

void	ScalarConverter::print_nan(std::string brut)
{
	(void)brut;
	std::cout << "char	:	"	<< "impossible" << std::endl;
	std::cout << "int	:	"	<< "impossible" << std::endl;
	std::cout << "float	:	"	<< "impossible" << std::endl;
	std::cout << "double  :	"	<< "nan" << std::endl;
}

void	ScalarConverter::print_inf(std::string brut)
{
	(void)brut;
	std::cout << "char	:	"	<< "impossible" << std::endl;
	std::cout << "int	:	"	<< "impossible" << std::endl;
	std::cout << "float	:	"	<< "inff" << std::endl;
	std::cout << "double  :	"	<< "inf" << std::endl;
}


int	ScalarConverter::numberz(std::string brut)
{
	int		i = 0;
	int		len = brut.length();
	bool	decim = false;

	if (brut.at(0) == '+' || brut.at(0) == '-')
		i++;
	while (i < len)
	{
		if (brut.at(i) == 'f' && std::isdigit(brut.at(i - 1))
			&& ((i + 1) == len)) {
			ScalarConverter::_type = _FLOAT;
			return 0 ;
		}
		else if (brut.at(i) == '.') {
			if (decim == false)
				decim = true;
			else
				return 1;
		}
		else if (!std::isdigit(brut.at(i)))
			return 1;
		i++;
	}
	if (decim == true)
		ScalarConverter::_type = _DOUBLE;
	else
		ScalarConverter::_type = _INT;
	return 0;
}


void	ScalarConverter::setType(std::string const brut) {
	
	if (brut.length() == 1 && std::isalpha(brut.at(0)) != 0)
		ScalarConverter::_type = _CHAR;
	else if (brut == "nan")
		ScalarConverter::_type = _NAN;
	else if (brut == "+inf" || brut == "+inff"
		|| brut == "-inf" || brut == "-inff")
		ScalarConverter::_type = _INF;
	else if (ScalarConverter::numberz(brut))
		throw FailedConversion();
}

void	ScalarConverter::convert(std::string const brut) {

	try {
		ScalarConverter::setType(brut);
	}
	catch(const ScalarConverter::FailedConversion &e) {
		std::cout << e.what();
		return ;
	}
	switch (ScalarConverter::_type)
	{
		case _CHAR:
			ScalarConverter::print_char(brut);
			break;
		case _INT:
			ScalarConverter::print_int(brut);
			break;
		case _FLOAT:
			ScalarConverter::print_float(brut);
			break;
		case _DOUBLE:
			ScalarConverter::print_double(brut);
			break;
		case _NAN:
			ScalarConverter::print_nan(brut);
			break;
		case _INF:
			ScalarConverter::print_inf(brut);
			break;
		default:
			std::cout << "AIRSICK LOWLANDERS ╮(￣～￣)╭" << std::endl;
	}
	std::cout << "TYPE : " << ScalarConverter::_type << std::endl;
}

