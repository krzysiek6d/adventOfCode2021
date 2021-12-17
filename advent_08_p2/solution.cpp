#include "solution.hpp"
#include <vector>
#include <algorithm>
#include <iterator>
#include <sstream>
#include <iostream>
#include <map>
#include <cassert>


std::vector<char> getCharsWithOccurences(const Line& line, int num)
{
    std::vector<char> result;
    std::map<char, int> occurences;
    for (const auto& q: line.numbers)
    {
        for(auto ch: q)
        {
            occurences[ch]++;
        }
    }
    auto it = std::find_if(occurences.begin(), occurences.end(), [num](auto occ){return occ.second == num;});
    while (it != occurences.end())
    {
        result.push_back(it->first);
        it = std::find_if(std::next(it), occurences.end(), [num](auto occ){return occ.second == num;});
    }
    return result;
}

char findSegmentA(const Line& line)
{
    std::string one;
    std::string seven;
    for (const auto& q: line.numbers)
    {
        if (q.length() == 2)
            one = q;
        if (q.length() == 3)
            seven = q;
    }
    std::sort(one.begin(), one.end());
    std::sort(seven.begin(), seven.end());
    std::vector<char> diff;
    std::set_difference(seven.begin(), seven.end(), one.begin(), one.end(), std::back_inserter(diff));
    return diff.front();
}

char findSegmentB(const Line& line)
{
    auto chars = getCharsWithOccurences(line, 6);
    assert(chars.size() == 1);
    return chars.front();
}

char findSegmentC(const Line& line)
{
    auto chars = getCharsWithOccurences(line, 8);
    assert(chars.size() == 2);
    char segmentA = findSegmentA(line);
    chars.erase(std::remove_if(chars.begin(), chars.end(), [segmentA](char v){return v==segmentA;}), chars.end());
    assert(chars.size() == 1);
    return chars.front();
}

char findSegmentD(const Line& line)
{
    std::string four;
    for (const auto& q: line.numbers)
    {
        if (q.length() == 4)
            four = q;
    }
    assert(four.length() == 4);
    four.erase(std::remove(four.begin(), four.end(), findSegmentB(line)), four.end());
    four.erase(std::remove(four.begin(), four.end(), findSegmentC(line)), four.end());
    four.erase(std::remove(four.begin(), four.end(), findSegmentF(line)), four.end());
    assert(four.length() == 1);

    return four.front();
}

char findSegmentE(const Line& line)
{
    auto chars = getCharsWithOccurences(line, 4);
    assert(chars.size() == 1);
    return chars.front();
}

char findSegmentF(const Line& line)
{
    auto chars = getCharsWithOccurences(line, 9);
    assert(chars.size() == 1);
    return chars.front();
}

char findSegmentG(const Line& line)
{
    auto chars = getCharsWithOccurences(line, 7);
    assert(chars.size() == 2);
    chars.erase(std::remove(chars.begin(), chars.end(), findSegmentD(line)), chars.end());
    assert(chars.size() == 1);
    return chars.front();
}

int lineSolution(const Line& line)
{
    char segA = findSegmentA(line);
    char segB = findSegmentB(line);
    char segC = findSegmentC(line);
    char segD = findSegmentD(line);
    char segE = findSegmentE(line);
    char segF = findSegmentF(line);
    char segG = findSegmentG(line);
    std::vector<std::string> numberEncoding = {
       {segA, segB, segC, segE, segF, segG},
       {segC, segF},
       {segA, segC, segD, segE, segG},
       {segA, segC, segD, segF, segG},
       {segB, segC, segD, segF},
       {segA, segB, segD, segF, segG},
       {segA, segB, segD, segE, segF, segG},
       {segA, segC, segF},
       {segA, segB, segC, segD, segE, segF, segG},
       {segA, segB, segC, segD, segF, segG}};

    for(auto& number: numberEncoding)
    {
        std::sort(number.begin(), number.end());
    }

    int num = 0;
    assert(line.question.size() == 4);
    for (auto q: line.question)
    {
        std::sort(q.begin(), q.end());
        int digit = std::distance(numberEncoding.begin(), std::find(numberEncoding.begin(), numberEncoding.end(), q));
        //std::cout << "decoded digit: " << digit << std::endl;
        num = num * 10 + digit;
    }
    return num;
}

int solution(std::vector<Line> numbers)
{
    int sum = 0;
    for (auto l: numbers)
    {
        sum += lineSolution(l);
    }
    return sum;
}

std::ostream& operator<<(std::ostream& os, const Line& line)
{
    for (auto n: line.numbers)
    {
        os << n << std::string(" ");
    }
    os << std::string("| ");
    for (auto n: line.question)
    {
        os << n << std::string(" ");
    }
    return os;
}


std::vector<Line> readInput(std::istream& is)
{
    std::vector<Line> lines;
    Line line;
    std::string delimiter;
    while(is >> line.numbers[0] >>
                line.numbers[1] >> 
                line.numbers[2] >> 
                line.numbers[3] >> 
                line.numbers[4] >> 
                line.numbers[5] >> 
                line.numbers[6] >> 
                line.numbers[7] >> 
                line.numbers[8] >> 
                line.numbers[9] >> 
                delimiter >> 
                line.question[0] >> 
                line.question[1] >> 
                line.question[2] >> 
                line.question[3] 
                )
    {
        lines.push_back(line);
    }
    return lines;
}
