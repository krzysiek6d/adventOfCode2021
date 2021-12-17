#include "solution.hpp"
#include <vector>
#include <algorithm>
#include <iterator>
#include <sstream>
#include <iostream>


int solution(std::vector<int> numbers, int days)
{
    for (int day = 0; day < days; day++)
    {
        int newborns = std::count_if(numbers.begin(), numbers.end(), [](auto d){return d==0;});
        std::transform(numbers.begin(), numbers.end(), numbers.begin(),
            [](int d)
            {
                if (d == 0) return 6;
                return d-1;
            }
        );
        for (int i = 0; i < newborns; i++) numbers.push_back(8);

        //std::cout << "day " << day << ": "; 
        //std::copy(numbers.begin(), numbers.end(), std::ostream_iterator<int>(std::cout, " "));
        //std::cout << std::endl; 
    }
    return numbers.size();
}


std::vector<int> readNums(std::istream& is)
{
    std::vector<int> nums;
    for (std::string line; std::getline(is, line, ','); ) {
        nums.push_back(std::stoi(line));
    }
    return nums;
}
