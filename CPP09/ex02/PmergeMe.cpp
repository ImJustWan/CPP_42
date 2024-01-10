#include "PmergeMe.hpp"
#include "colors.hpp"

PmergeMe::PmergeMe() {
	return;
}

PmergeMe::PmergeMe(PmergeMe &src) {
	(void)src;
}

PmergeMe::~PmergeMe() {
	return ;
}

PmergeMe &PmergeMe::operator=(PmergeMe const &rhs) {
	(void)rhs;
	return *this;
}
