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

		template <typename T>
		void	fordJohnson(T &container);
		int		JacobsthalNumber(int n);
		template <typename T>
		void	binarySearch(T& main, int element);

	public:

		PmergeMe(void);
		~PmergeMe();

		void		parsing(char **av);


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
