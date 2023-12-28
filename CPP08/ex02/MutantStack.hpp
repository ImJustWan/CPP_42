#pragma once

#include "colors.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <stack>
#include <list>


template<typename T>
class MutantStack : public std::stack<T> {
	public:
		MutantStack();
		MutantStack(MutantStack const & src);
		~MutantStack();
		MutantStack &operator=( MutantStack const & n );

		typedef typename std::deque<T>::iterator	iterator;

		iterator			getBegin();
		iterator			getEnd();

};

#include "MutantStack.tpp"