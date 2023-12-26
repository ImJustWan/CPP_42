#include "Span.hpp"

Span::~Span(void) {

	std::cout << _GREY _ITALIC "Span Destructor called" _END << std::endl;
	return;
}


Span::Span(unsigned int N) : _maxSize(N) {
}

unsigned int	Span::getMaxSize(void) {
	return this->_maxSize;
}

void	Span::addNumber(int const value)
{
	if (this->_spanVector.size() == this->getMaxSize())
		throw FullSpanException();
	this->_spanVector.push_back(value);
	std::cout << _GREY _ITALIC "Succesfully added : " << value << _END << std::endl;
}

void	Span::addNumber(std::vector<int> vctr)
{
	std::cout << _RIVIERA _ITALIC "\nInserting current instance's vector into parameter's vector.\n" _END << std::endl;
	if (this->_spanVector.size() + vctr.size() >= this->_maxSize)
		throw FullSpanException();
	this->_spanVector.insert(this->_spanVector.end(), vctr.begin(), vctr.end());
}

void	Span::removeNumber()
{
	if (this->_spanVector.size() == 0)
		return ;
	this->_spanVector.pop_back();
}

int	Span::shortestSpan()
{
	// std::cout << "SIZE : " << this->_spanVector.size() << std::endl;
	if (this->_spanVector.size() < 2)
		throw NoSpanException();

	std::vector<int>::iterator	it = this->_spanVector.begin();

	unsigned int shortest = abs(*it - *(it + 1));
	unsigned int tmp = shortest;

	for (it += 1; it != this->_spanVector.end() - 1; ++it) {
		tmp = abs(*it - *(it + 1));
		if (tmp < shortest)
			shortest = tmp;
	}
	return shortest;
}

int	Span::longestSpan()
{
	if (this->_spanVector.size() < 2)
		throw NoSpanException();

	sort(_spanVector.begin(), _spanVector.end());
	return _spanVector.back() - _spanVector.front();
}
