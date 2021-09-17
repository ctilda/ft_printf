#include <stack> 
#include <iostream>
#include <list>
#include "mutantstack.hpp"

int main()
{
    std::cout << "===_STACK_===" << std::endl;
    // std::stack<int>::iterator it1 = st1.
    std::stack<int> st1;

    st1.push(1);
    st1.push(2);
    st1.push(3);
    std::cout << "Top: " << st1.top() << std::endl;
	st1.pop();
	std::cout << "Size: " << st1.size() << std::endl;
    st1.push(4);
    st1.push(5);
    int i = 1;
    while (!st1.empty()) 
	{ 
         std::cout << i++ << ": " << st1.top() << std::endl;
        st1.pop(); 
	} 
    std::cout << "------------------------------" << std::endl;


    std::cout << "===_LIST_===" << std::endl;
    std::list<int> list1;
    list1.push_back(1);
    list1.push_back(2);
    list1.push_back(3);
    std::cout << "Top: " << list1.back() << std::endl;
	list1.pop_back();
	std::cout << "Size: " << list1.size() << std::endl;
    list1.push_back(4);
    list1.push_back(5);

    std::list<int>::iterator itB = list1.begin();
    std::list<int>::iterator itE = list1.end();
    i = 1;
    while (itB != itE)
    {
        std::cout << i++ << ": " << *itB << std::endl;
        ++itB;
    }

    std::cout << "------------------------------" << std::endl;


    std::cout << "===_MutantStack_===" << std::endl;
    MutantStack<int> mstack;
	mstack.push(1);
    mstack.push(2);
    mstack.push(3);
    std::cout << "Top: " << mstack.top() << std::endl;
	mstack.pop();
	std::cout << "Size: " << mstack.size() << std::endl;
	mstack.push(4);
    mstack.push(5);

    MutantStack<int>::iterator mitB = mstack.begin();
	MutantStack<int>::iterator mitE = mstack.end();
    
    i = 1;
    while (mitB != mitE)
    {
        std::cout << i++ << ": " << *mitB << std::endl;
        ++mitB;
    }

    std::stack<int> s(mstack);

    std::cout << "------------------------------" << std::endl;

    return (0);
}
