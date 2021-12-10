#include "solution.hpp"
#include <vector>
#include <algorithm>
#include <iterator>
#include <sstream>
#include <numeric>
#include <iostream>

int get_value(const std::vector<std::vector<int>>& v, int x, int y)
{
    if (x < 0 || y < 0 || x >= v.size() || y >= v.front().size())
        return 9;
    else 
        return v[x][y];
}


int getSizeOfArea(const std::vector<std::vector<int>>& v, std::vector<std::vector<bool>>& isVisited, int x, int y)
{
    if (get_value(v, x, y) == 9)
        return 0;
    if (isVisited[x][y])
        return 0;
    isVisited[x][y] = true;
    int currentSize = 1;
    currentSize += getSizeOfArea(v, isVisited, x, y-1);
    currentSize += getSizeOfArea(v, isVisited, x, y+1);
    currentSize += getSizeOfArea(v, isVisited, x+1, y);
    currentSize += getSizeOfArea(v, isVisited, x-1, y);
    return currentSize;
}

int solution(const std::vector<std::vector<int>>& v)
{
    std::vector<std::vector<bool>> isVisited(v.size(), std::vector<bool>(v.front().size(), false));

    std::vector<int> basins;
    for (int x = 0; x < v.size(); x++)
    {
        for(int y = 0; y < v.front().size(); y++)
        {
            if (not isVisited[x][y])
                basins.push_back(getSizeOfArea(v, isVisited, x, y));
        }
    }

    std::sort(basins.begin(), basins.end(), std::greater<>());
    
    int sol = 1;
    for (int i = 0 ; i < 3 && i < basins.size(); i++)
        sol *= basins[i];
    return sol;


    // std::copy(basins.begin(), basins.end(), std::ostream_iterator<int>(std::cout, " "));
    // std::cout << std::endl;
    
    // return 5;
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

