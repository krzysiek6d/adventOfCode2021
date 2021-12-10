#include <gtest/gtest.h>
#include "solution.hpp"

TEST(advent, t1)
{
    const char* input_data = R"(
        2199943210
        3987894921
        9856789892
        8767896789
        9899965678
    )";
    std::istringstream ss;
    ss.str(input_data);

    auto numbers = readNums(ss);

    EXPECT_EQ(15, solution(numbers));

}
