#pragma once

#include "colors.hpp"

#include <iostream>
#include <algorithm>
#include <cctype>
#include <cstdlib>
#include <vector> 

class Span {	

private:

	Span();

	Span & operator=( Span const & rhs );

	unsigned int		_maxSize;

public:

	std::vector<int>	_spanVector;

	Span(const Span &src);
	Span(unsigned int N);
	~Span();

	void	addNumber(int const value);
	void	addNumber(std::vector<int> vctr);
	void	removeNumber();
	int		shortestSpan();
	int		longestSpan();

	unsigned int				getMaxSize();
	size_t						getCurrSize();
	std::vector<int>::iterator	getBegin();
	std::vector<int>::iterator	getEnd();

};


class FullSpanException : public std::exception {
	public:
		virtual const char * what() const throw() {
			return(_SALMON "\nSpan is full, can't add a number here sorry (‘-‘)ゞ\n" _END);
		}
};

class NoSpanException : public std::exception {
	public:
		virtual const char * what() const throw() {
			return(_SALMON "\nNo span can be found here, sorry (‘-‘)ゞ\n" _END);
		}
};