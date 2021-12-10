#include "solution.hpp"
#include <vector>
#include <algorithm>
#include <iostream>
#include <iterator>

int main()
{  
    std::vector<std::bitset<12>> data;
    std::copy(std::istream_iterator<std::bitset<12>>(std::cin), std::istream_iterator<std::bitset<12>>(), back_inserter(data));
    std::cout << "solution: " << solution<12>(data) << std::endl;
}