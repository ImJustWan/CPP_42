#pragma once

#include "colors.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <algorithm>
#include <stdlib.h>
#include <string>
#include <deque>
#include <list>
#include <vector>
#include <sys/time.h>

template <typename T>
struct ogPairs {
	unsigned int	_main;
	unsigned int	_second;
	bool			_inserted;

	ogPairs(int main, int second) : _main(main), _second(second), _inserted(false){}
};

class PmergeMe {
	
	private:

		std::deque<int>		_arrDeq;
		std::list<int>		_arrList;
		std::vector<int>	_arrVec;

		PmergeMe(PmergeMe &src);
		PmergeMe &operator=(PmergeMe const & rhs);

		template <typename T>
		void			print(std::string str, T &ctnr);
		template <typename T>
		void			isSorted(T &ctnr);

		template <typename T>
		void			fordJohnson(T &container);
		template <typename T>
		void			binarySearchInsertion(T& main, int element);
		template <typename T>
		int				findMatchingOne(unsigned int value, std::vector<ogPairs<T> >& ogPairing);
		
		unsigned int	JacobsthalNumber(int n);


	public:

		PmergeMe(void);
		~PmergeMe();

		void		parsing(int ac, char **av);
		void		algorithming();


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
