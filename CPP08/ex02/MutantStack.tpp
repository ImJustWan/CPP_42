#include "MutantStack.hpp"

template<typename T>
MutantStack<T>::MutantStack() {

}

template<typename T>
MutantStack<T>::MutantStack(MutantStack const & src) {
	(void)src;
}

template<typename T>
MutantStack<T>::~MutantStack() {
}

template<typename T>
MutantStack<T> & MutantStack<T>::operator=( MutantStack <T> const & n ) {
	if (this != &n) {
		this = std::stack<T>::operator=;
	}
	return *this;
}

// this->c accesses the underlying container, to go around stack not having iterators

template<typename T>
typename MutantStack<T>::iterator MutantStack<T>::getBegin() {
	return this->c.begin();
}

template<typename T>
typename MutantStack<T>::iterator MutantStack<T>::getEnd() {
	return this->c.end();

}
