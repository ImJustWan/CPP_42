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

template <typename T>
void	PmergeMe::print(std::string str, T &ctnr)
{
	std::cout << _BOLD _RIVIERA "\n" << str << _END << std::endl;
	for (size_t i = 0; i < ctnr.size(); i++)
	{
		std::cout << ctnr[i];
		if (i != ctnr.size() - 1)
			std::cout << " ";
	}
	std::cout << std::endl;
}

template <typename T>
void	PmergeMe::isSorted(T &ctnr)
{
	for (size_t i = 0; i < ctnr.size() - 1; i++)
	{
		if (ctnr[i] > ctnr[i+1])
		{
			std::cout << _RED _BOLD "THIS IS NOT SORTED" _END << std::endl;
			return ;
		}
	}
	std::cout << std::endl;
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

	
	std::cout << "\nStart Vec size : " << this->_arrVec.size();
	print("Print Vec before : ", this->_arrVec);
	isSorted(this->_arrVec);

	fordJohnson(this->_arrVec);

	std::cout << "\nStart Deq size : " << this->_arrDeq.size();
	print("Print Deq before : ", this->_arrDeq);
	fordJohnson(this->_arrDeq);
	// std::cout << "odd ? " << this->odd << std::endl;
	// std::cout << "Size of vector : " << this->_arrVec.size() << std::endl;
	// std::cout << "Size of deque : " << this->_arrDeq.size() << std::endl;

	isSorted(this->_arrVec);
	isSorted(this->_arrDeq);
	std::cout << "\n\nFinal Vec size : " << this->_arrVec.size();
	print("Print Vec after : ", this->_arrVec);

	std::cout << "\n\nFinal Deq size : " << this->_arrDeq.size();
	print("Print Deq after : ", this->_arrDeq);

}

template <typename T>
void	PmergeMe::fordJohnson(T &ctnr)
{
	T main;
	T second;
	bool _odd;
	int lonely;

	_odd = (ctnr.size() % 2 != 0);
	if (_odd == true)
		lonely = ctnr.back();
	if (ctnr.size() > 2)
	{
		for (size_t i = 0; i < ctnr.size() - 1; i += 2) {
			if (ctnr[i] > ctnr[i + 1])
				std::swap(ctnr[i], ctnr[i + 1]);
			main.push_back(ctnr[i]);
			second.push_back(ctnr[i + 1]);
		}

		for (size_t i = 0; i < main.size() - 1; i += 2)
			if (main[i] > main[i + 1])
				std::swap(main[i], main[i + 1]);
		fordJohnson(main);

		// NEXT IMPROVEMENT
		// Instead of inserting linearly from second
		// Insert next THE ELEMENT THAT WAS PAIRED 
		// with the (Jacobstahl index) of main
		for (unsigned int i = 0; i < second.size(); i++)
			binarySearch(main, second[i]);
		
		if (_odd == true)
			binarySearch(main, lonely);
		ctnr = main;
	}
}


template <typename T>
void	PmergeMe::binarySearch(T& main, int value)
{
	// Find lower_bound of value within main

	typename T::iterator it = main.begin();
	typename T::iterator end = main.end();
	typename T::iterator mid;
	
	while (it != end)
	{
		mid = it + (std::distance(it, end) / 2);
		if (*mid < value)
			it = mid + 1;
		else
			end = mid;
	}
	main.insert(it, value);
}

unsigned int	PmergeMe::JacobsthalNumber(int n)
{
	if (n == 0)
		return 0;
	if (n == 1)
		return 1;
	return JacobsthalNumber(n - 1) + 2 * JacobsthalNumber(n - 2);
}

// template <typename T>
// T	PmergeMe::pairedPairsPairing(T &ctnr)
// {
// 	T	main;
// 	// T	second;
// 	if (ctnr.size() <= 1)
// 		return ctnr;
// 	for (size_t i = 0; i < ctnr.size() - 1; i += 2)
// 		if (ctnr[i] < ctnr[i + 1])
// 			std::swap(ctnr[i], ctnr[i + 1]);
// 	this->odd = (this->_arrVec.size() % 2 != 0);
// 	if (odd == true)
// 		this->_lonely = this->_arrVec.back();
// 	else
// 		this->_lonely = 0;

// 	int j = 0;
// 	for (size_t i = 0; i < ctnr.size() / 2; i++) {
// 		this->_ogVecPairs[i].ogIndex = i;
// 		this->_ogVecPairs[i].main = ctnr[j];
// 		this->_ogVecPairs[i].second = ctnr[j + 1];
// 		main.push_back(ctnr[j]);
// 		j += 2;
// 	}

// 	std::cout << "\n" << std::endl;
// 	for (size_t i = 0; i < ctnr.size() / 2; i++)
// 	{
// 		std::cout << "Pair[" << i << "] : main [" << this->_ogVecPairs[i].main;
// 		std::cout << "] && second [" << this->_ogVecPairs[i].second << "]" << std::endl;
// 	}
// 	return main;
// }
