	#include "ScalarConverter.hpp"

	int ScalarConverter::_type = _INV;
	bool ScalarConverter::_neg = false;

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
		char toChar = brut.at(0);

		std::cout << "char	:	"	<< toChar << std::endl;
		std::cout << "int	:	"	<< static_cast<int>(toChar) << std::endl;
		std::cout << "float	:	"	<< static_cast<float>(toChar) << ".0f" << std::endl;
		std::cout << "double  :	"	<< static_cast<double>(toChar) << ".0" << std::endl;
	}

	void	ScalarConverter::print_int(std::string brut)
	{
		long toInt = std::atol(brut.c_str());

		if (std::isprint(toInt) != 0)
			std::cout << "char	:	"	<< static_cast<char>(toInt) << std::endl;
		else
			std::cout << "char	:	"	<< "Non printable" << std::endl;
		if (brut.length() > 11 || toInt < std::numeric_limits<int>::min()
			|| toInt > std::numeric_limits<int>::max())
			std::cout << "int	:	"	<< "Int overflow" << std::endl;
		else
			std::cout << "int	:	"	<< static_cast<int>(toInt) << std::endl;
		std::cout << "float	:	"	<< static_cast<float>(toInt) << ".0f" << std::endl;
		std::cout << "double  :	"	<< static_cast<double>(toInt) << ".0" << std::endl;
	}	

	void	ScalarConverter::print_float(std::string brut)
	{
		float toFloat = static_cast<float>(std::atof(brut.c_str()));

		// char : non ASCII / non printable / OK
		if (toFloat < 0 || toFloat > 126)
			std::cout << "char	:	"	<< "Impossible" << std::endl;
		else if (std::isprint(toFloat) == 0)
			std::cout << "char	:	"	<< "Non printable" << std::endl;
		else
			std::cout << "char	:	"	<< static_cast<char>(toFloat) << std::endl;
		
		// int : int overflow / OK
		if (toFloat < std::numeric_limits<int>::min()
			|| toFloat > std::numeric_limits<int>::max())
			std::cout << "int	:	"	<< "Int Overflow" << std::endl;
		else
			std::cout << "int	:	"	<< static_cast<int>(toFloat) << std::endl;
		
		// float : float overflow is handled by  static_cast<float>(toDouble)
		if (toFloat == static_cast<int>(toFloat))
			std::cout << "float	:	"	<< toFloat << ".0f" << std::endl;
		else
			std::cout << "float	:	"	<< toFloat << "f" << std::endl;
		
		// double : double overflow is handled by atof 
		std::cout << "double  :	"	<< static_cast<double>(toFloat);
		std::cout << (brut.find_first_of(".") == std::string::npos?".0":"") << std::endl;

	}

	void	ScalarConverter::print_double(std::string brut)
	{
		double toDouble = std::atof(brut.c_str());

		// char : non ASCII / non printable / OK
		if (toDouble < 0 || toDouble > 126)
			std::cout << "char	:	"	<< "Impossible" << std::endl;
		else if (std::isprint(toDouble) == 0)
			std::cout << "char	:	"	<< "Non printable" << std::endl;
		else
			std::cout << "char	:	"	<< static_cast<char>(toDouble) << std::endl;
		
		// int : int overflow / OK
		if (toDouble < std::numeric_limits<int>::min()
			|| toDouble > std::numeric_limits<int>::max())
			std::cout << "int	:	"	<< "Int Overflow" << std::endl;
		else
			std::cout << "int	:	"	<< static_cast<int>(toDouble) << std::endl;
		
		// float : float overflow is handled by  static_cast<float>(toDouble) ; non decimal / OK
		if (brut.at(brut.length()-1) == '0' && brut.at(brut.length()-2) == '.')
			std::cout << "float	:	"	<< static_cast<float>(toDouble) << ".0f" << std::endl;
		else
			std::cout << "float	:	"	<< static_cast<float>(toDouble) << "f" << std::endl;
		
		// double : double overflow is handled by atof ; non decimal / OK
		std::cout << "double  :	"	<< toDouble;
		std::cout << (brut.find_first_of(".") == std::string::npos?".0":"") << std::endl;
	}

	void	ScalarConverter::print_nan(std::string brut)
	{
		(void)brut;
		std::cout << "char	:	"	<< "impossible" << std::endl;
		std::cout << "int	:	"	<< "impossible" << std::endl;
		std::cout << "float	:	"	<< "nanf" << std::endl;
		std::cout << "double  :	"	<< "nan" << std::endl;
	}

	void	ScalarConverter::print_inf(std::string brut)
	{
		(void)brut;
		std::cout << "char	:	"	<< "impossible" << std::endl;
		std::cout << "int	:	"	<< "impossible" << std::endl;
		if (ScalarConverter::_neg == true) {
			std::cout << "float	:	"	<< "-inff" << std::endl;
			std::cout << "double  :	"	<< "-inf" << std::endl;
			return ;
		}
		std::cout << "float	:	"	<< "inff" << std::endl;
		std::cout << "double  :	"	<< "inf" << std::endl;
	}

	int	ScalarConverter::numberz(std::string brut)
	{
		int		i = 0;
		int		len = brut.length();
		bool	decim = false;

		if (brut.at(0) == '-')
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
		
		if (brut.at(0) == '-')
			ScalarConverter::_neg = true;
		if (brut.length() == 1 && std::isalpha(brut.at(0)) != 0)
			ScalarConverter::_type = _CHAR;
		else if (brut == "nan" || brut == "nanf")
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
		catch(const ScalarConverter::NonPrintable &e) {
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
	}

