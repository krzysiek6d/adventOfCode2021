#include "solution.hpp"
#include <iostream>


int main()
{  
    auto numbers = readNums(std::cin);
    auto tables = readTables(std::cin);

    std::cout << solution(tables, numbers) << std::endl;
}