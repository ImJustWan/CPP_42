#include "RPN.hpp"
#include "colors.hpp"

RPN::RPN() {
	return;
}

RPN::RPN(RPN &src) {
	(void)src;
}

RPN::~RPN() {
	return ;
}

RPN &RPN::operator=(RPN const &rhs) {
	(void)rhs;
	return *this;
}


void	RPN::parsing(char **av) {

	std::stringstream	buf(av[1]);
	std::string 		str;
	int	num = 0;
	int	ope = 0;
	std::string operators = "+-*/";

	while (!buf.eof())
	{
		buf >> str;
		if (str.length() != 1)
			throw RPN::SomeException();
		if (operators.find(str.at(0)) != std::string::npos)
			ope++;
		else if (std::isdigit(str.at(0)))
			num++;
		else 
			throw RPN::SomeException();
	}
	std::cout << "Num is : " << num << " and ope is : " << ope << std::endl;
}