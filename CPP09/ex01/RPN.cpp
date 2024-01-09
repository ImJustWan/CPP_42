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


bool	RPN::parsing()