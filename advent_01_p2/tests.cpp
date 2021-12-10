#include <gtest/gtest.h>
#include "solution.hpp"

TEST(advent, t1)
{
    std::vector<int> v{607, 618, 618, 617, 647, 716, 769, 792};
    EXPECT_EQ(5u, solution(v));
}