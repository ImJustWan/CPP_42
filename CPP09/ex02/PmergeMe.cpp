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

void	PmergeMe::parsing(char **av)
{
	std::string			str;
	double				tmp;
	
	for (int i = 1; av[i]; i++)
	{
		tmp = atoi(av[i]);
		if (tmp <=	 0 || tmp > 2147483647)
			throw PmergeMe::ParsingError();
		if (std::find(this->_arrVec.begin(),this->_arrVec.end(), tmp) != this->_arrVec.end())
			throw PmergeMe::DuplicateError();
		this->_arrVec.push_back(tmp);
		this->_arrDeq.push_back(tmp);
		// Uncomment for vizualisation
		// std::cout << "Current input : " << str.at(0) << std::endl;
	}
	this->odd = (this->_arrVec.size() % 2 != 0);

	std::cout << "\nBefore : " << std::endl;

	for (size_t i = 0; i < this->_arrVec.size(); i++)
		std::cout << " " << this->_arrVec[i];

	std::cout << "Vec : " << std::endl;
	fordJohnson(this->_arrVec);
	// std::cout << "Deq : " << std::endl;
	// fordJohnson(this->_arrDeq);
	// std::cout << "odd ? " << this->odd << std::endl;
	// std::cout << "Size of vector : " << this->_arrVec.size() << std::endl;
	// std::cout << "Size of deque : " << this->_arrDeq.size() << std::endl;

	std::cout << "\nAfter : " << std::endl;

	for (size_t i = 0; i < this->_arrVec.size(); i++)
		std::cout << " " << this->_arrVec[i];

}

template <typename T>
void	PmergeMe::fordJohnson(T &ctnr)
{
	// std::cout << "recursiving" << std::endl;
	for (size_t i = 0; i < ctnr.size() - 1; i += 2) {
		if (ctnr[i] > ctnr[i + 1])
		{
			std::swap(ctnr[i], ctnr[i + 1]);
		}
	}
	if (ctnr.size() == 1)
	{
		return;
	}
	T	main;
	T	second;
	if (ctnr.size() > 2)
	{
		for (size_t i = 0; i < ctnr.size() - 1; i += 2) {
			main.push_back(ctnr[i]);
		}
		for (size_t i = 1; i < ctnr.size(); i += 2) {
			second.push_back(ctnr[i]);
		}
		fordJohnson(main);
	}


	// std::cout << "\nMain : " << std::endl;

	// for (size_t i = 0; i < this->_arrVec.size(); i++)
	// 	std::cout << " " << this->_arrVec[i];

}

int		JacobsthalNumber(int n)
{
	if (n == 0)
		return 0;
	if (n == 1)
		return 1;
	return JacobsthalNumber(n - 1) + 2 * JacobsthalNumber(n - 2);
}
