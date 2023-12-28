#include "Span.hpp"


Span::Span(void) {

	std::cout << _GREY _ITALIC "Span Constructor called" _END << std::endl;
	return;
}

Span::~Span(void) {

	std::cout << _GREY _ITALIC "Span Destructor called" _END << std::endl;
	return;
}

Span::Span(const Span &src){
	(void)src;
};

Span & Span::operator=( Span const & rhs ) {

	std::cout << "Copy Assignement operator called" << std::endl;
	if (this != &rhs)
	{
		this->_maxSize = rhs._maxSize;
		this->_spanVector = rhs._spanVector;
	}
	return *this;

}

Span::Span(unsigned int N) : _maxSize(N) {
}

unsigned int	Span::getMaxSize(void) {
	return this->_maxSize;
}

size_t Span::getCurrSize() {
	return this->_spanVector.size();
}

std::vector<int>::iterator	Span::getBegin() {
	return this->_spanVector.begin();
}

std::vector<int>::iterator	Span::getEnd() {
	return this->_spanVector.end();
}


void	Span::addNumber(int const value)
{
	if (this->_spanVector.size() == this->getMaxSize())
		throw FullSpanException();
	this->_spanVector.push_back(value);
	// Uncomment to display addNumber calls
	// std::cout << _GREY _ITALIC "Succesfully added : " << value << _END << std::endl;
}

// addNumber(vector) uses .insert(X, Y, Z) method, which reallocates storage if needed
// and inserts from Y to Z elements of vector parameter, starting at X 

void	Span::addNumber(std::vector<int> vctr)
{
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
