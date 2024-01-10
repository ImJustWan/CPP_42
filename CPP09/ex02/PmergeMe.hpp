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


class PmergeMe {
	
	private:

		PmergeMe(PmergeMe &src);
		PmergeMe &operator=(PmergeMe const & rhs);

		int		operating(char ope, int fst, int snd);

	public:

		PmergeMe(void);
		~PmergeMe();


	class SomeException : public std::exception
	{
		public:
			virtual const char * what() const throw() {
				return(_RED "❌ SomeException" _END);
			}
	};
};
