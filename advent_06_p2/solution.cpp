#include "solution.hpp"
#include <vector>
#include <algorithm>
#include <iterator>
#include <sstream>
#include <iostream>
#include <numeric>
#include <map>

long solution(std::vector<int> numbers, int days)
{
    std::array<long, 9> numberOfFishAtDay = {0, 0, 0, 0, 0, 0, 0, 0, 0};
    for(auto num: numbers)
    {
        numberOfFishAtDay[num]++;
    }
    for (int day = 0; day < days; day++)
    {
        long newBorns = numberOfFishAtDay[0];

        numberOfFishAtDay[0] = numberOfFishAtDay[1];
        numberOfFishAtDay[1] = numberOfFishAtDay[2];
        numberOfFishAtDay[2] = numberOfFishAtDay[3];
        numberOfFishAtDay[3] = numberOfFishAtDay[4];
        numberOfFishAtDay[4] = numberOfFishAtDay[5];
        numberOfFishAtDay[5] = numberOfFishAtDay[6];
        numberOfFishAtDay[6] = numberOfFishAtDay[7] + newBorns;
        numberOfFishAtDay[7] = numberOfFishAtDay[8];
        numberOfFishAtDay[8] = newBorns;

        // std::cout << "day " << day + 1 << " : ";
        // for (int i = 0; i < 9; i++)
        // {
        //     std::cout << "[" << i << "->" << numberOfFishAtDay[0] << "]";
        // }
        // std::cout << std::endl;
    }
    return std::accumulate(numberOfFishAtDay.begin(), numberOfFishAtDay.end(), 0l);
}


std::vector<int> readNums(std::istream& is)
{
    std::vector<int> nums;
    for (std::string line; std::getline(is, line, ','); ) {
        nums.push_back(std::stoi(line));
    }
    return nums;
}
