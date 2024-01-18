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

unsigned long long int getTime()
{
	struct timeval tv;
	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000000 + tv.tv_usec);
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
	std::cout << "\n" << std::endl;
}

template <typename T>
void	PmergeMe::isSorted(T &ctnr)
{
	for (size_t i = 0; i < ctnr.size() - 1; i++)
	{
		if (ctnr[i] > ctnr[i+1])
		{
			std::cout << _RED _BOLD "NOT SORTED ❌" _END << std::endl;
			return ;
		}
	}
	std::cout<< _EMMERALD _BOLD "SORTED ✅" _END << std::endl;
}

void	PmergeMe::parsing(int ac, char **av)
{
	std::string			str;
	double				tmp;
	
	if (ac == 1)
		throw PmergeMe::ParsingError();
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
		// std::cout << "Current input : " << tmp << std::endl;
	}
}

void	PmergeMe::algorithming()
{
	unsigned long long int time;
	
	print("Before : ", this->_arrVec);
	std::cout << "this->_arrVec : ";
	isSorted(this->_arrVec);

	time = getTime();
	fordJohnson(this->_arrVec);
	time = getTime() - time;
	
	print("\nAfter : ", this->_arrVec);

	std::cout << "\nTime to process a range of " << this->_arrVec.size() << " elements with std::vector : " _BOLD _SALMON;
	std::cout << time << " us" _END << std::endl;

	
	time = getTime();
	fordJohnson(this->_arrDeq);
	time = getTime() - time;

	std::cout << "Time to process a range of " << this->_arrDeq.size() << " elements with std::deque : " _BOLD _SALMON;
	std::cout << time << " us\n" _END << std::endl;


	std::cout << _BOLD _ITALIC _GREY "\nAfter" _END << std::endl;
	std::cout << "this->_arrVec : ";
	isSorted(this->_arrVec);
	std::cout << "this->_arrDeq : ";
	isSorted(this->_arrDeq);
	std::cout << std::endl;
	// print("Print Deq after : ", this->_arrDeq);
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
		std::vector<ogPairs<int> > ogPairing;

		for (size_t i = 0; i < ctnr.size() - 1; i += 2) {
			if (ctnr[i] > ctnr[i + 1])
				std::swap(ctnr[i], ctnr[i + 1]);
			ogPairs<int> pair(ctnr[i], ctnr[i + 1]);
			ogPairing.push_back(pair);
			main.push_back(ctnr[i]);
			second.push_back(ctnr[i + 1]);
		}

		for (size_t i = 0; i < main.size() - 1; i += 2)
			if (main[i] > main[i + 1])
				std::swap(main[i], main[i + 1]);

		fordJohnson(main);

		int size = ctnr.size();
		if (_odd == true)
			size--;

		int index = 0;
		int oldJcb = 0;
		while ((int)main.size() != size)
		{
			int next = 0;
			int jcb = JacobsthalNumber(index);
			if (jcb > (int)main.size())
				jcb = main.size();
			while (jcb != oldJcb && jcb >= 0)
			{
				if (jcb < (int)main.size())
					next = findMatchingOne(main[jcb], ogPairing);
				if (next != 0)
					binarySearch(main, next);
				jcb--;
			}
			oldJcb = JacobsthalNumber(index);
			index++;
		}

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

template <typename T>
int	PmergeMe::findMatchingOne(unsigned int value, std::vector<ogPairs<T> >& ogPairing)
{
	
	if (ogPairing.empty())
		return 0;

	for (size_t i = 0; i < ogPairing.size(); i++)
	{
		
		if (ogPairing[i]._main == value && ogPairing[i]._inserted == false)
		{
			ogPairing[i]._inserted = true;
			return ogPairing[i]._second;
		}
	}
	return 0;
}
