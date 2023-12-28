#pragma once
#include "colors.hpp"
#include <algorithm>
#include <iostream>

class NoMatchException : public std::exception {
	public:
		virtual const char * what() const throw() {
			return( _SALMON "No match was found, sorry (‘-‘)ゞ\n" _END);
		}
};

template< typename T >
typename T::iterator	easyfind(T &containr, int value) {

	typename T::iterator	it = find(containr.begin(), containr.end(), value);

	if (it == containr.end())
		throw NoMatchException();
	return it;
}

// typename T::iterator	easyfind(T &containr, int value) {

// 	if (find(containr.begin(), containr.end(), value) == containr.end())
// 		throw NoMatchException();
// 	return find(containr.begin(), containr.end(), value);
// }