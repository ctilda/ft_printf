#include "mutantstack.hpp"


template<typename T>
MutantStack<T> &MutantStack<T>::operator=(MutantStack<T> const &other)
{
    this->c = other.c;
    return (*this);
}
