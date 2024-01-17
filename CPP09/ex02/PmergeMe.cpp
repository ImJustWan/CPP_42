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
	

	std::cout << "\nPrint before : " << std::endl;

	for (size_t i = 0; i < this->_arrVec.size(); i++)
		std::cout << " " << this->_arrVec[i];

	// std::cout << "\n\nVec : " << std::endl;
	fordJohnson(this->_arrVec);
	// if (odd == true)
	// 	binarySearch(this->_arrVec, this->_lonely,);
	// std::cout << "Deq : " << std::endl;
	// fordJohnson(this->_arrDeq);
	// std::cout << "odd ? " << this->odd << std::endl;
	// std::cout << "Size of vector : " << this->_arrVec.size() << std::endl;
	// std::cout << "Size of deque : " << this->_arrDeq.size() << std::endl;

	std::cout << "\nPrint after : " << std::endl;

	for (size_t i = 0; i < this->_arrVec.size(); i++)
		std::cout << " " << this->_arrVec[i];

}

template <typename T>
void	PmergeMe::pairedPairsPairing(T &ctnr)
{
	// T	main;
	// T	second;
	if (ctnr.size() <= 1)
		return;
	for (size_t i = 0; i < ctnr.size() - 1; i += 2)
		if (ctnr[i] < ctnr[i + 1])
			std::swap(ctnr[i], ctnr[i + 1]);
	this->odd = (this->_arrVec.size() % 2 != 0);
	if (odd == true)
		this->_lonely = this->_arrVec.back();
	else
		this->_lonely = 0;
	std::cout << "_lonely :  " << _lonely << std::endl;
	 this->_ogPairs[0].ogIndex = 0;

	int j = 0;
	for (size_t i = 0; i < ctnr.size() / 2; i++) {
		this->_ogPairs[i].ogIndex = i;
		// this->_ogPairs->main = ctnr[j];
		// this->_ogPairs->second = ctnr[j + 1];
		j += 2;
	}
		std::cout << "\nBoucling " << j << " times" << std::endl;
	// std::cout << "\nPrint meanwhile : " << std::endl;
	// for (size_t i = 0; i < (ctnr.size() / 2) - 1 ; i++)
	// {
	// 		std::cout << "Pair[" << i << "] : main [" << this->_ogPairs->main;
	// 		std::cout << "] && second [" << this->_ogPairs->second << "]" << std::endl;
		
	// }
}

template <typename T>
void	PmergeMe::fordJohnson(T &ctnr)
{
	// (void)ctnr;
	pairedPairsPairing(ctnr);
	// std::cout << "recursiving" << std::endl;
	
	// if (ctnr.size() > 2)
	// {
	// 	for (size_t i = 0; i < ctnr.size() - 1; i += 2) {
	// 		main.push_back(ctnr[i]);
	// 		second.push_back(ctnr[i + 1]);
	// 	}
	// 	// std::cout << "\nSIZE OF SECOND : " << second.size() << std::endl;
	// 	// fordJohnson(main);
	// 	// fordJohnson(second);
	// 	unsigned int j = 0;
	// 	for (unsigned int i = 0; i < second.size();)
	// 	{
	// 		unsigned int index = JacobsthalNumber(j);
	// 		// while (i > JacobsthalNumber(j++))
	// 		// 	;
	// 		std::cout << "\nJcbstlnbr : " << i << std::endl;
	// 		std::cout << "second[i] : " << second[i] << std::endl;
			
	// 		if (index < second.size())
	// 			binarySearch(main, second[index], index);
	// 		second.erase(second.begin() + index);
	// 		// main.erase(second[i]);
	// 	}
	// 	// ctnr = main;
	// 	// ctnr.clear();
	// 	// ctnr.insert(ctnr.end(), main.begin(), main.end());
	// 	// ctnr.insert(ctnr.end(), second.begin(), second.end());
	// 	std::cout << "\nSIZE OF ctnr : " << ctnr.size() << std::endl;
	// 	std::cout << "SIZE OF main : " << main.size() << std::endl;
	// 	std::cout << "SIZE OF second : " << second.size() << std::endl;

	// }

	// std::cout << "\nPrint meanwhile : " << std::endl;
	// for (size_t i = 0; i < main.size(); i++)
	// std::cout << " " << main[i];
	// std::cout << std::endl;
	// ctnr = main;

	// std::cout << "\nMain : " << std::endl;

	// for (size_t i = 0; i < this->_arrVec.size(); i++)
	// 	std::cout << " " << this->_arrVec[i];

}


template <typename T>
void	PmergeMe::binarySearch(T& main, int value, int index)
{
	unsigned int mid;
	unsigned int min = 0;
	unsigned int max = main.size() - 1;

	(void)index;
	std::cout << "\nValue is : " << value << std::endl;

	while (min < max)
	{
		mid = min + (max - min) / 2;
		if (main[mid] < value)
			min = mid +1;
		else
			max = mid;
	}
	main.insert(main.begin() + min, value);
	return;
}

unsigned int	PmergeMe::JacobsthalNumber(int n)
{
	if (n == 0)
		return 0;
	if (n == 1)
		return 1;
	return JacobsthalNumber(n - 1) + 2 * JacobsthalNumber(n - 2);
}
