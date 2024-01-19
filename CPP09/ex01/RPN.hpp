#pragma once

#include "colors.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <string.h>
#include <stack>
#include <limits.h>
#include <algorithm>
#include <stdlib.h>
#include <stdio.h>

class RPN {
	
	private:
		std::stack<int> _rpnStack;

		RPN(RPN &src);
		RPN &operator=(RPN const & rhs);

		int		operating(char ope, int fst, int snd);

	public:

		RPN(void);
		~RPN();

		void	mathing(char **av);

	class SomeException : public std::exception
	{
		public:
			virtual const char * what() const throw() {
				return(_RED "❌ Error in parameters" _END);
			}
	};
	class DivisionByZero : public std::exception
	{
		public:
			virtual const char * what() const throw() {
				return(_RED "❌ Division by zero" _END);
			}
	};
};
