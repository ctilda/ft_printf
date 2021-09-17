#include "span.hpp"

Span::Span() : _N(0)
{
	
}

Span::Span(unsigned int N) : _N(N)
{

}

Span::Span(const Span &other) : _N(other._N)
{
	this->_set.clear();
	this->_set = other._set;
}

Span & Span::operator=(const Span &other)
{
	this->_N = other._N;
	this->_set.clear();
	this->_set = other._set;

	return *this;
}

void Span::addNumber(const int &num)
{
	if (this->_set.size() >= this->_N)
		throw NoEnoughElementsException();
	this->_set.insert(num);
}

int Span::longestSpan()
{
	if (this->_set.size() < 2)
		throw NoEnoughElementsException();
	return (std::abs(*std::max_element(_set.begin(), _set.end()) - *std::min_element(_set.begin(), _set.end())));
}

int Span::shortestSpan()
{
	if (this->_set.size() < 2)
		throw NoEnoughElementsException();

	std::multiset<int>::iterator index = this->_set.begin();
	std::multiset<int>::iterator next = ++this->_set.begin();

	int min = std::abs(*next++ - *index++);
    int temp = 0;
    while(next != this->_set.end())
    {
        temp = std::abs(*next++ - *index++);
        if (temp < min)
			min = temp;
    }
    return (min);
}


const char * Span::NoEnoughElementsException::what() const throw()
{
	return "SpanException: no enough elements!";
}

const char * Span::NoSpaceException::what() const throw()
{
	return "SpanException: no space for new elements!";
}
