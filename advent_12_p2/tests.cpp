#include <gtest/gtest.h>
#include "solution.hpp"
#include <sstream>

TEST(advent, t1)
{
    const char* input_data = R"(
        start-A
        start-b
        A-c
        A-b
        b-d
        A-end
        b-end
    )";
    std::istringstream ss;
    ss.str(input_data);

    auto connections = readConnections(ss);
    auto ways = solution(connections);
    
    EXPECT_EQ(36, ways);
}

TEST(advent, t2)
{
    const char* input_data = R"(
        fs-end
        he-DX
        fs-he
        start-DX
        pj-DX
        end-zg
        zg-sl
        zg-pj
        pj-he
        RW-he
        fs-DX
        pj-RW
        zg-RW
        start-pj
        he-WI
        zg-he
        pj-fs
        start-RW
    )";
    std::istringstream ss;
    ss.str(input_data);

    auto connections = readConnections(ss);
    auto ways = solution(connections);
    
    EXPECT_EQ(3509, ways);
}