#include <gtest/gtest.h>
#include "solution.hpp"

TEST(advent, t1)
{
    std::vector<std::bitset<5>> v{
        std::bitset<5>{"00100"},
        std::bitset<5>{"11110"},
        std::bitset<5>{"10110"},
        std::bitset<5>{"10111"},
        std::bitset<5>{"10101"},
        std::bitset<5>{"01111"},
        std::bitset<5>{"00111"},
        std::bitset<5>{"11100"},
        std::bitset<5>{"10000"},
        std::bitset<5>{"11001"},
        std::bitset<5>{"00010"},
        std::bitset<5>{"01010"}
    };
    EXPECT_EQ(230, solution<5>(v));
}

