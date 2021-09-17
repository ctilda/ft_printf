#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <set>
#include <algorithm>

class Span
{
public:
	Span();
	Span(unsigned int N);
	Span(const Span &other);
	Span & operator=(Span const &other);

	void addNumber (const int &num);
	int shortestSpan();
	int longestSpan();

	class NoSpaceException : public std::exception
	{
		public:
			const char * what() const throw();
	};
	class NoEnoughElementsException : public std::exception
	{
		public:
			const char * what() const throw();
	};
private:
    unsigned int _N;
    std::multiset<int> _set;
};

#endif
