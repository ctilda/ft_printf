#include "easyfind.hpp"
#include <vector>

int main()
{
    try
    {
        std::vector<int> vectorA;
        vectorA.push_back(1);
        vectorA.push_back(3);
        vectorA.push_back(4);
        vectorA.push_back(6);
        vectorA.push_back(5);
        std::cout << easyfind(vectorA, 12) << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }

    try
    {
        std::vector<int> vectorA;
        std::cout << easyfind(vectorA, 3) << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }

    try
    {
        std::vector<int> vectorA;
        vectorA.push_back(19);
        vectorA.push_back(232);
        vectorA.push_back(12);
        vectorA.push_back(942);
        std::cout << easyfind(vectorA, 19) << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
    
}
