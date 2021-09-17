#include "span.hpp"

int main()
{

    try
    {
        Span spA = Span(1);
        const int count = 1;
        std::cout << "Longest span: " << spA.longestSpan() << std::endl;
        std::cout << "Shortest span: " << spA.shortestSpan() << std::endl;
        
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    } 
    std::cout << "------------------------------" << std::endl;



    try
    {
        Span spB = Span(5);
        spB.addNumber(5);
        spB.addNumber(3);
        spB.addNumber(17);
        spB.addNumber(9);
        spB.addNumber(11);
        std::cout << "Longest span: " << spB.longestSpan() << std::endl;
        std::cout << "Shortest span: " << spB.shortestSpan() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    } 
    std::cout << "------------------------------" << std::endl;


    try
    {
        srand(time(NULL));
        const int count = 10000;
        int random = 0;
        Span spC(count);
        for (int i = 0; i < count; i++)
        {
            random = rand() % count;
            spC.addNumber(random);
        }

        std::cout << "Longest span: " << spC.longestSpan() << std::endl;
        std::cout << "Shortest span: " << spC.shortestSpan() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
    std::cout << "------------------------------" << std::endl;
}
