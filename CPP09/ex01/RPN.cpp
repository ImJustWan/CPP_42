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

int	RPN::operating(char ope, int fst, int snd)
{
	if (ope == '-')
		return fst - snd;
	if (ope == '*')
		return fst * snd;
	if (ope == '/')
		return fst / snd;
	return fst + snd;
}

void	RPN::mathing(char **av) {

	std::string			operators = "+-*/";
	std::string			str;
	std::stringstream	buf(av[1]);
	int	top;
	
	while (buf >> str)
	{
		if (str.length() != 1)
			throw RPN::SomeException();
		if (std::isdigit(str.at(0)))
			this->_rpnStack.push(str.at(0) - '0');
		else if (operators.find(str.at(0)) != std::string::npos \
			&& this->_rpnStack.size() >= 2)
		{
			if (this->_rpnStack.size() < 2)
				throw RPN::SomeException();
			top = this->_rpnStack.top();
			this->_rpnStack.pop();
			top = operating(str.at(0), this->_rpnStack.top(), top);
			this->_rpnStack.pop();
			this->_rpnStack.push(top);
		}
		else
			throw RPN::SomeException();
		// Uncomment for vizualisation
		// std::cout << "Current input : " << str.at(0) << std::endl;
	}

	if (this->_rpnStack.size() != 1)
		throw RPN::SomeException();
	std::cout << "Result : " << this->_rpnStack.top() << std::endl;
}
