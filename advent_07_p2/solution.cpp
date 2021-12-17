#include "solution.hpp"
#include <vector>
#include <algorithm>
#include <iterator>
#include <sstream>
#include <iostream>

int sumto(int v)
{
    return (v * (v+1)) / 2;
}

int solution(std::vector<int> numbers)
{
    auto [min_it, max_it] = std::minmax_element(numbers.begin(), numbers.end());
    int min = *min_it;
    int max = *max_it;

    int distance = -1;
    for(int i = min; i <=max; i++)
    {
        int localDistance = 0;
        for (int num: numbers)
        {
            localDistance += sumto(std::abs(num - i));
        }
        if (distance == -1)
            distance = localDistance;
        else
        {
            distance = std::min(distance, localDistance);
        }
    }
    return distance;
}


std::vector<int> readNums(std::istream& is)
{
    std::vector<int> nums;
    for (std::string line; std::getline(is, line, ','); ) {
        nums.push_back(std::stoi(line));
    }
    return nums;
}
