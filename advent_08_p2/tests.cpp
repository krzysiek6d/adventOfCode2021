#include <gtest/gtest.h>
#include "solution.hpp"

TEST(advent, t1)
{
    const char* input_data = R"(
        be cfbegad cbdgef fgaecd cgeb fdcge agebfd fecdb fabcd edb |
        fdgacbe cefdb cefbgd gcbe
        edbfga begcd cbg gc gcadebf fbgde acbgfd abcde gfcbed gfec |
        fcgedb cgb dgebacf gc
        fgaebd cg bdaec gdafb agbcfd gdcbef bgcad gfac gcb cdgabef |
        cg cg fdcagb cbg
        fbegcd cbd adcefb dageb afcb bc aefdc ecdab fgdeca fcdbega |
        efabcd cedba gadfec cb
        aecbfdg fbg gf bafeg dbefa fcge gcbea fcaegb dgceab fcbdga |
        gecf egdcabf bgf bfgea
        fgeab ca afcebg bdacfeg cfaedg gcfdb baec bfadeg bafgc acf |
        gebdcfa ecba ca fadegcb
        dbcfg fgd bdegcaf fgec aegbdf ecdfab fbedc dacgb gdcebf gf |
        cefg dcbef fcge gbcadfe
        bdfegc cbegaf gecbf dfcage bdacg ed bedf ced adcbefg gebcd |
        ed bcgafe cdgba cbgef
        egadfb cdbfeg cegd fecab cgb gbdefca cg fgcdab egfdb bfceg |
        gbdfcae bgc cg cgb
        gcafb gcf dcaebfg ecagb gf abcdeg gaef cafbge fdbac fegbdc |
        fgae cfgab fg bagce
    )";
    std::istringstream ss;
    ss.str(input_data);

    auto in = readInput(ss);

    std::copy(in.begin(), in.end(), std::ostream_iterator<Line>(std::cout, "\n"));
    EXPECT_EQ(61229, solution(in));
}


TEST(advent, readSegmentA)
{
    const char* input_data = R"(
        acedgfb cdfbe gcdfa fbcad dab cefabd cdfgeb eafb cagedb ab |
        cdfeb fcadb cdfeb cdbaf
    )";
    std::istringstream ss;
    ss.str(input_data);

    auto in = readInput(ss);

    std::copy(in.begin(), in.end(), std::ostream_iterator<Line>(std::cout, "\n"));
    EXPECT_EQ('d', findSegmentA(in.front()));
}

TEST(advent, readSegmentB)
{
    const char* input_data = R"(
        acedgfb cdfbe gcdfa fbcad dab cefabd cdfgeb eafb cagedb ab |
        cdfeb fcadb cdfeb cdbaf
    )";
    std::istringstream ss;
    ss.str(input_data);

    auto in = readInput(ss);

    std::copy(in.begin(), in.end(), std::ostream_iterator<Line>(std::cout, "\n"));
    EXPECT_EQ('e', findSegmentB(in.front()));
}

TEST(advent, readSegmentC)
{
    const char* input_data = R"(
        acedgfb cdfbe gcdfa fbcad dab cefabd cdfgeb eafb cagedb ab |
        cdfeb fcadb cdfeb cdbaf
    )";
    std::istringstream ss;
    ss.str(input_data);

    auto in = readInput(ss);

    std::copy(in.begin(), in.end(), std::ostream_iterator<Line>(std::cout, "\n"));
    EXPECT_EQ('a', findSegmentC(in.front()));
}

TEST(advent, readSegmentD)
{
    const char* input_data = R"(
        acedgfb cdfbe gcdfa fbcad dab cefabd cdfgeb eafb cagedb ab |
        cdfeb fcadb cdfeb cdbaf
    )";
    std::istringstream ss;
    ss.str(input_data);

    auto in = readInput(ss);

    std::copy(in.begin(), in.end(), std::ostream_iterator<Line>(std::cout, "\n"));
    EXPECT_EQ('f', findSegmentD(in.front()));
}

TEST(advent, readSegmentE)
{
    const char* input_data = R"(
        acedgfb cdfbe gcdfa fbcad dab cefabd cdfgeb eafb cagedb ab |
        cdfeb fcadb cdfeb cdbaf
    )";
    std::istringstream ss;
    ss.str(input_data);

    auto in = readInput(ss);

    std::copy(in.begin(), in.end(), std::ostream_iterator<Line>(std::cout, "\n"));
    EXPECT_EQ('g', findSegmentE(in.front()));
}

TEST(advent, readSegmentF)
{
    const char* input_data = R"(
        acedgfb cdfbe gcdfa fbcad dab cefabd cdfgeb eafb cagedb ab |
        cdfeb fcadb cdfeb cdbaf
    )";
    std::istringstream ss;
    ss.str(input_data);

    auto in = readInput(ss);

    std::copy(in.begin(), in.end(), std::ostream_iterator<Line>(std::cout, "\n"));
    EXPECT_EQ('b', findSegmentF(in.front()));
}

TEST(advent, readSegmentG)
{
    const char* input_data = R"(
        acedgfb cdfbe gcdfa fbcad dab cefabd cdfgeb eafb cagedb ab |
        cdfeb fcadb cdfeb cdbaf
    )";
    std::istringstream ss;
    ss.str(input_data);

    auto in = readInput(ss);

    std::copy(in.begin(), in.end(), std::ostream_iterator<Line>(std::cout, "\n"));
    EXPECT_EQ('c', findSegmentG(in.front()));
}