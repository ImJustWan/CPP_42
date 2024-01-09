#pragma once

#include "colors.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <string.h>
#include <stack>
#include <limits.h>
#include <stdlib.h>


class RPN {
	
	private:
		std::stack<int> _rpnStack;

		RPN(RPN &src);
		RPN &operator=(RPN const & rhs);

	public:

		RPN(void);
		~RPN();

		void	parsing(char **av);

	class SomeException : public std::exception
	{
		public:
			virtual const char * what() const throw() {
				return(_RED _BOLD "❌ Error in parameters\n" _END);
			}
	};
};


//Exception
// Error: not a positive number.
// Error: bad input => 2001-42-42
// Error: too large a number