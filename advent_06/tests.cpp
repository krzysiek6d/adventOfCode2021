#include <gtest/gtest.h>
#include "solution.hpp"

TEST(advent, t1)
{
    const char* input_data = "3,4,3,1,2";
    std::istringstream ss;
    ss.str(input_data);

    auto numbers = readNums(ss);

    //std::copy(numbers.begin(), numbers.end(), std::ostream_iterator<int>(std::cout, " "));
    //std::cout << std::endl;
    EXPECT_EQ(26, solution(numbers, 18));
    EXPECT_EQ(5934, solution(numbers, 80));
}
