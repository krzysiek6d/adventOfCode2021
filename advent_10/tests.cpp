#include <gtest/gtest.h>
#include "solution.hpp"

TEST(advent, t1)
{
    std::vector<std::string> input_data = {
        "{([(<{}[<>[]}>{[]{[(<()>",
        "[[<[([]))<([[{}[[()]]]",
        "[{[{({}]{}}([{[{{{}}([]",
        "[<(<(<(<{}))><([]([]()",
        "<{([([[(<>()){}]>(<<{{"
    };
    EXPECT_EQ(26397, solution(input_data));
}
