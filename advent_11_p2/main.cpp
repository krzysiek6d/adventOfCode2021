#include "solution.hpp"
#include <iostream>


int main()
{  
    auto lines = readMap(std::cin);
    auto steps = solution(lines);
    std::cout << steps << std::endl;
}