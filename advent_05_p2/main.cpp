#include "solution.hpp"
#include <iostream>

int main()
{  
    auto pipes = readPipes(std::cin);
    std::cout << "solution: " << solution(pipes) << std::endl;
}