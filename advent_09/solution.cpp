#include "solution.hpp"
#include <vector>
#include <algorithm>
#include <iterator>
#include <sstream>
#include <numeric>

int get_value(const std::vector<std::vector<int>>& v, int x, int y)
{
    if (x < 0 || y < 0 || x >= v.size() || y >= v.front().size())
        return 9;
    else 
        return v[x][y];
}

int solution(const std::vector<std::vector<int>>& v)
{
    std::vector<int> minimums;
    for (int x = 0; x < v.size(); x++)
    {
        for(int y = 0; y < v.front().size(); y++)
        {
            int currentValue = v[x][y];
            auto neighbors = {
                get_value(v, x-1, y),
                get_value(v, x+1, y),
                get_value(v, x, y-1),
                get_value(v, x, y+1),
            };
            if (std::all_of(neighbors.begin(), neighbors.end(), [currentValue](const int& neighbor){return neighbor > currentValue;}))
            {
                minimums.push_back(currentValue);
            }
        }
    }
    // each minimum is incremented by 1
    return std::accumulate(minimums.begin(), minimums.end(), minimums.size());
}

std::vector<std::vector<int>> readNums(std::istream& is)
{
    std::vector<std::string> lines;
    std::copy(std::istream_iterator<std::string>(is), std::istream_iterator<std::string>(), back_inserter(lines));
    

    std::vector<std::vector<int>> numbers;
    for (const auto& line: lines)
    {
        std::vector<int> numbersInLine;
        for (auto ch: line)
        {
            numbersInLine.push_back(ch - '0');
        }
        numbers.push_back(numbersInLine);
    }

    return numbers;
}

