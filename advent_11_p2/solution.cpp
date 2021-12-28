#include "solution.hpp"
#include <vector>
#include <algorithm>
#include <iterator>
#include <sstream>
#include <iostream>

void increment(std::vector<std::vector<int>>& map, int row, int col)
{
    if(row >= 0 && row < map.size() && col >=0 && col < map[row].size())
    {
        map[row][col]++;
    }
}

int solution(std::vector<std::vector<int>> map)
{
    int steps = 0;
    while(true)
    {
        int flashes = 0;
        steps++;
        for (int row = 0; row < map.size(); row++)
        {
            for (int col = 0 ; col < map[row].size(); col++)
            {
                increment(map, row, col);
            }
        }

        std::vector<std::vector<int>> hasFlashed = map;
        for(auto& row: hasFlashed)
            for(auto& val: row)
                val = 0;

        bool anyFlashed = true;
        while(anyFlashed)
        {
            anyFlashed = false;
            for (int row = 0; row < map.size(); row++)
            {
                for (int col = 0 ; col < map[row].size(); col++)
                {
                    if (map[row][col] > 9 && !hasFlashed[row][col])
                    {
                        anyFlashed = true;
                        hasFlashed[row][col] = true;
                        increment(map, row - 1, col - 1);
                        increment(map, row - 1, col);
                        increment(map, row - 1, col + 1);
                        increment(map, row    , col - 1);
                        increment(map, row    , col + 1);
                        increment(map, row + 1, col - 1);
                        increment(map, row + 1, col);
                        increment(map, row + 1, col + 1);
                    }
                }
            }
        }
        

        for (int row = 0; row < map.size(); row++)
        {
            for (int col = 0 ; col < map[row].size(); col++)
            {
                if (map[row][col] > 9)
                {
                    flashes++;
                    map[row][col] = 0;
                }
            }
        }
        if (flashes == 100)
            break;
    }
    return steps;
}


std::vector<std::vector<int>> readMap(std::istream& is)
{
    std::vector<std::string> data;
    std::copy(std::istream_iterator<std::string>(is), std::istream_iterator<std::string>(), back_inserter(data));
    std::vector<std::vector<int>> map;
    for(const auto& line: data)
    {
        std::vector<int> lineOfDigits;
        for(auto ch: line)
        {
            if(ch >= '0' && ch <= '9')
                lineOfDigits.push_back(ch - '0');
        }
        map.push_back(lineOfDigits);
    }
    return map;
}