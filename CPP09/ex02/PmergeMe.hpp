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


class ogPairs {
	public:
	int				ogIndex;
	unsigned int	main;
	unsigned int	second;
};

class PmergeMe {
	
	private:

		std::deque<int>		_arrDeq;
		std::vector<int>	_arrVec;
		bool				odd;
		int					_lonely;

		ogPairs				*_ogPairs;

		PmergeMe(PmergeMe &src);
		PmergeMe &operator=(PmergeMe const & rhs);

		template <typename T>
		void	pairedPairsPairing(T &ctnr);
		template <typename T>
		void	binarySearch(T& main, int element, int index);
		unsigned int	JacobsthalNumber(int n);

	public:

		PmergeMe(void);
		~PmergeMe();

		void		parsing(char **av);
		template <typename T>
		void			fordJohnson(T &container);
		
		template <typename T>
		class lilpair {
			T main;
			T second;	
		};


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
