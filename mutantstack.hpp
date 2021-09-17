#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <algorithm>
#include <stack>

template<typename T>
class MutantStack: public std::stack<T>
{
public:
    MutantStack();
    MutantStack(MutantStack<T> const &other);
    virtual ~MutantStack();

    typedef typename std::stack<T>::container_type::iterator iterator;
    MutantStack<T> &operator=(MutantStack<T> const &other);
    iterator begin();
    iterator end();
};

template<typename T>
MutantStack<T>::MutantStack():std::stack<T>()
{
}

template<typename T>
MutantStack<T>::MutantStack(MutantStack<T> const &other) : std::stack<T>(other)
{
}

template<typename T>
MutantStack<T>::~MutantStack()
{
}

template<typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin()
{
    return (this->c.begin());
}

template<typename T>
typename MutantStack<T>::iterator MutantStack<T>::end()
{
    return (this->c.end());
}

#endif
