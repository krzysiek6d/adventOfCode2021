#include "solution.hpp"
#include <iostream>


int main()
{  
    auto numbers = readNums(std::cin);

    std::cout << solution(numbers) << std::endl;
}