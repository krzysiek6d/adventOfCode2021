#include "solution.hpp"
#include <vector>
#include <algorithm>
#include <iostream>
#include <iterator>

int main()
{  
    std::vector<Move> data;
    std::copy(std::istream_iterator<Move>(std::cin), std::istream_iterator<Move>(), back_inserter(data));
    std::cout << "solution: " << solution(data) << std::endl;
}