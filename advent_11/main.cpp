#include "solution.hpp"
#include <iostream>


int main()
{  
    auto lines = readMap(std::cin);
    auto [flashes, map] = solution(lines, 100);
    std::cout << flashes << std::endl;
}