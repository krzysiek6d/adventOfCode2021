#include <gtest/gtest.h>
#include "solution.hpp"

TEST(advent, t1)
{
    std::vector<Move> v{
        {Direction::forward, 5},
        {Direction::down, 5},
        {Direction::forward, 8},
        {Direction::up, 3},
        {Direction::down, 8},
        {Direction::forward, 2}
    };
    EXPECT_EQ(150, solution(v));
}
