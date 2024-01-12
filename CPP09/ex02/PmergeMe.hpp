#pragma once

#include "colors.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <stdlib.h>
#include <string>
#include <deque>
#include <vector>



class PmergeMe {
	
	private:

		std::deque<int>		_arrDeq;
		std::vector<int>	_arrVec;
		bool				odd;

		PmergeMe(PmergeMe &src);
		PmergeMe &operator=(PmergeMe const & rhs);

	public:

		PmergeMe(void);
		~PmergeMe();

		void		parsing(char **av);
		template <typename T>
		void		pairSorting(T &container);

	class ParsingError : public std::exception
	{
		public:
			virtual const char * what() const throw() {
				return(_RED "❌ Input error" _END);
			}
	};
	class DuplicateError : public std::exception
	{
		public:
			virtual const char * what() const throw() {
				return(_RED "❌ Duplicate error" _END);
			}
	};
};
