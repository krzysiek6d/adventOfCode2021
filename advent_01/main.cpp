#include "solution.hpp"
#include <vector>
#include <algorithm>
#include <iostream>
#include <iterator>

int main()
{  
    std::vector<int> data;
    std::copy(std::istream_iterator<int>(std::cin), std::istream_iterator<int>(), back_inserter(data));
    std::cout << "solution: " << solution(data) << std::endl;
}