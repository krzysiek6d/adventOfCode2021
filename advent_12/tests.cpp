#include <gtest/gtest.h>
#include "solution.hpp"
#include <sstream>

TEST(advent, t1)
{
    const char* input_data = R"(
        dc-end
        HN-start
        start-kj
        dc-start
        dc-HN
        LN-dc
        HN-end
        kj-sa
        kj-HN
        kj-dc
    )";
    std::istringstream ss;
    ss.str(input_data);

    auto connections = readConnections(ss);
    auto ways = solution(connections);
    
    EXPECT_EQ(19, ways);
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
    
    EXPECT_EQ(226, ways);
}