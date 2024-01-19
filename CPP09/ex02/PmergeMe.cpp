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

	std::cout << "\nTime to process a range of " << this->_arrVec.size();
	std::cout << " elements with std::vector : " _BOLD _SALMON << time << " us" _END << std::endl;

	
	time = getTime();
	fordJohnson(this->_arrDeq);
	time = getTime() - time;

	std::cout << "\nTime to process a range of " << this->_arrDeq.size();
	std::cout << " elements with std::deque : " _BOLD _SALMON << time << " us" _END << std::endl;

	std::cout << _BOLD _ITALIC _GREY "\nAfter" _END << std::endl;
	std::cout << "this->_arrVec : ";
	isSorted(this->_arrVec);
	std::cout << "this->_arrDeq : ";
	isSorted(this->_arrDeq);
	std::cout << std::endl;
	// print("Print Deq after : ", this->_arrDeq);
}

/*

	Detailed steps :
		
		➤ odd is used to check if the container sent has an odd or even size.
			If odd, last element is saved in _lonely
		
		➤ container is then divided into two smaller containers
			std::swap ensures that for each pair, the larger value goes into main, the other in second
			ogPairing saves each pair to allow us to fetch the matching part later
		
		➤ container main (larger elements of each pair) is then recursively sorted using this same function
		
		➤ using the Jacobsthal numbers (0, 1, 1, 3, 5, 11, etc...) we determine at the element of main for which
			we have to fetch the corresponding part (done in findMatchingOne)
		
		➤ once that number (next) is found in the second container, it is then inserted
			using the binarySearchInsertion function for efficiency.
		
		➤ we then decrement the index of Jacobsthal and repeat the binarySearchInsertion/insertion until previous index
			(At 3, we do 3->2. At 11, we do 11->10->9->8->7->6 etc)
		
		➤ the variable size is used to handle odd-sized containers
			○ If even, the binarySearchInsertion continues until main.size() == ctnr.size() 
				(every element of second has been pushed back into main)
			○ If odd, we stop at ctnr.size() - 1, and then handle the last element saved in lonely
		
*/

template <typename T>
void	PmergeMe::fordJohnson(T &ctnr)
{
	T main;
	T second;
	bool odd;
	int lonely;

	// std::cout << _BOLD _GREY _ITALIC "\nNew recursive !\n" _END << std::endl;
	odd = (ctnr.size() % 2 != 0);
	if (odd == true)
		lonely = ctnr.back();
	if (ctnr.size() > 2)
	{
		std::vector<ogPairs<int> > ogPairing;

		for (size_t i = 0; i < ctnr.size() - 1; i += 2) {
			if (ctnr[i] < ctnr[i + 1])
				std::swap(ctnr[i], ctnr[i + 1]);
			ogPairs<int> pair(ctnr[i], ctnr[i + 1]);
			ogPairing.push_back(pair);
			main.push_back(ctnr[i]);
			second.push_back(ctnr[i + 1]);
			// std::cout << "ogPair[" << i / 2 << "] : [ " << ctnr[i] << " : " << ctnr[i + 1] << " ]" << std::endl; 
		}

		for (size_t i = 0; i < main.size() - 1; i += 2)
			if (main[i] > main[i + 1])
				std::swap(main[i], main[i + 1]);

		fordJohnson(main);

		int size = ctnr.size();
		if (odd == true)
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
					binarySearchInsertion(main, next);
				jcb--;
			}
			oldJcb = JacobsthalNumber(index);
			index++;
		}

		if (odd == true)
			binarySearchInsertion(main, lonely);
		ctnr = main;
	}
}

/*

	Detailed steps:

	➤ The function performs a binary search within the sorted container 'main' to find the lower_bound of the 'value'.
	
	➤ start and end of the container
	
	➤ in each iteration : mid marks the half between start and end

	➤ Comparison between mid and the value we're looking for
		○ if mid < value
			- start = mid + 1
			-> we're now looking in the upper half
		○ else
			- end = mid
			-> we're now looking in the lower half
	
	➤ once start reached end, we've determined the position to insert value

*/


template <typename T>
void	PmergeMe::binarySearchInsertion(T& main, int value)
{
	typename T::iterator start = main.begin();
	typename T::iterator end = main.end();
	typename T::iterator mid;
	
	while (start != end)
	{
		mid = start + (std::distance(start, end) / 2);
		if (*mid < value)
			start = mid + 1;
		else
			end = mid;
	}
	main.insert(start, value);
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
