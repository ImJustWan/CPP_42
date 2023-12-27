#include "Array.hpp"

template<typename T>
Array<T>::Array() : _size(0), arr(NULL) {

}

template<typename T>
Array<T>::Array(unsigned int n) : _size(n), arr(new T[n]) {

}

template<typename T>
Array<T>::Array(Array const & src) : _size(src._size), arr(new int[src._size]) {
	for (unsigned int i = 0; i < _size; i++)
		this->arr[i] = src.arr[i];
}

template<typename T>
Array<T>::~Array() {
	delete[] arr;
}

template<typename T>
Array<T> & Array<T>::operator=( Array <T> const & n ) {
	if (this != &n) {
		delete[] this->arr;
		this->_size = n._size;
		this->arr = new T[this->_size];
		for (size_t i = 0; i < this->_size; i++)
			this->arr[i] = n.arr[i];
	}
	return *this;
}

template<typename T>
T & Array<T>::operator[](unsigned int index) {
	if (index >= _size) {
		throw std::out_of_range("Index out of range");
	}
	return arr[index];
}