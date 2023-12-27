#pragma once

#include "colors.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>


template<typename T>
class Array {
	public:
		Array();
		Array(unsigned int n);
		Array(Array const & src);
		~Array();

		Array &operator=( Array const & n );

		T &operator[](unsigned int index);

	private:
		unsigned int	_size;
		T				*arr;
		// cannot use T arr[] because compiler needs to know
		// the _size of the array if it is declared that way

};

#include "Array.tpp"