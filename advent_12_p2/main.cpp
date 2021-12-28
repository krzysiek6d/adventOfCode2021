#include "solution.hpp"
#include <iostream>


int main()
{  
    auto connections = readConnections(std::cin);
    auto ways = solution(connections);
    std::cout << ways << std::endl;
}