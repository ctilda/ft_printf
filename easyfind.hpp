#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>


class	easyFindException : public std::exception
{
	const char * what() const throw()
	{
		return("EasyfindException: not found!");
	};
};

class	easyEmptyException : public std::exception
{
	const char * what() const throw()
	{
		return("EasyfindException: array is empty!");
	};
};

template<typename T>
int& easyfind(T& cont, int x)
{
    if (cont.begin() == cont.end())
        throw (easyEmptyException());
    typename T::iterator value = std::find(cont.begin(), cont.end(), x);
    if (value == cont.end())
        throw (easyFindException());
    
    return (*value);
}

#endif
