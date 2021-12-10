#include <gtest/gtest.h>
#include "solution.hpp"

TEST(advent, t1)
{
    std::vector<int> v{199, 200, 208, 210, 200, 207, 240, 269, 260, 263};
    EXPECT_EQ(7u, solution(v));
}

 