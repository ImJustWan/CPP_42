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

	pop_pop_

	if (this->_rpnStack.size() != 1)
		throw RPN::SomeException();
	std::cout << "Result : " << this->_rpnStack.top() << std::endl;
}
