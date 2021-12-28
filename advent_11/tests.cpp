#include <gtest/gtest.h>
#include "solution.hpp"
#include <sstream>

void printMap(const std::vector<std::vector<int>>& map)
{
    for (const auto& row: map)
    {
        for (const auto& elem: row)
        {
            std::cout << elem << " ";
        }
        std::cout <<std::endl;
    }
}

TEST(advent, t1)
{
    const char* input_data = R"(
        5483143223
        2745854711
        5264556173
        6141336146
        6357385478
        4167524645
        2176841721
        6882881134
        4846848554
        5283751526
    )";
    std::istringstream ss;
    ss.str(input_data);

    auto map = readMap(ss);
    printMap(map);

    int steps = 100;

    auto [flashes, newMap] = solution(map, steps);
    
    std::cout << "after " << steps << " steps: " << std::endl;
    printMap(newMap);

    EXPECT_EQ(1656, flashes);
}

