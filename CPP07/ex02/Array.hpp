#pragma once

#include "colors.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

template<typename T>
class Array {
	public:
		Array() : _size(0), arr(NULL) {}
		Array(unsigned int n) : _size(n), arr(new T[n]) {}

		Array(Array const & src) : _size(src._size), arr(new int[src._size]) {
			for (unsigned int i = 0; i < _size; i++)
				this->arr[i] = src.arr[i];
		}

		~Array() {
			delete[] arr;
		}

		Array &operator=( Array const & n ) {
			if (this != &n) {
				delete[] this->arr;
				this->_size = n._size;
				this->arr = new int[this->_size];
				for (unsigned int i = 0; i < this->_size; i++)
					this->arr[i] = n.arr[i];
			}
			return *this;
		}

		T &operator[](unsigned int index) {
			if (index >= _size) {
				throw std::out_of_range("Index out of range");
			}
			return arr[index];
		}

	private:
		unsigned int	_size;
		T				*arr;
		// cannot use T arr[] because compiler needs to know
		// the _size of the array if it is declared that way

};
