#include "solution.hpp"
#include <vector>
#include <algorithm>
#include <iterator>
#include <sstream>
#include <iostream>


int lineSolution(const Line& line)
{
    //std::cout << line << std::endl;
    int uniqueNums = 0;
    for (const auto& q: line.question)
    {
        if (q.length() == 2 || q.length() == 3 || q.length() == 4 || q.length() == 7)
            uniqueNums++;
    }
    return uniqueNums;
}

int solution(std::vector<Line> numbers)
{
    int uniqueNums = 0;
    for (auto l: numbers)
    {
        uniqueNums += lineSolution(l);
    }
    return uniqueNums;
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
