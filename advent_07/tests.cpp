#include <gtest/gtest.h>
#include "solution.hpp"

TEST(advent, t1)
{
    const char* input_data = "16,1,2,0,4,2,7,1,2,14";
    std::istringstream ss;
    ss.str(input_data);

    auto numbers = readNums(ss);

    std::copy(numbers.begin(), numbers.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;
    EXPECT_EQ(37, solution(numbers));
}
