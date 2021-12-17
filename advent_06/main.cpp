#include "solution.hpp"
#include <iostream>


int main()
{  
    auto numbers = readNums(std::cin);

    std::cout << solution(numbers, 80) << std::endl;
}