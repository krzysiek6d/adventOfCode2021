#include "solution.hpp"
#include <iostream>
#include <iterator>

int main()
{  
    auto numbers = readNums(std::cin);

    // for (const auto& line: numbers)
    // {
    //      std::copy(line.begin(), line.end(), std::ostream_iterator<int>(std::cout, " "));
    //      std::cout << std::endl;
    // }

    std::cout << solution(numbers) << std::endl;
}