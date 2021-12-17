#pragma once
#include <vector>
#include <array>

struct Line
{
    std::array<std::string, 10> numbers;
    std::array<std::string, 4> question;

};

std::ostream& operator<<(std::ostream& os, const Line& line);

char findSegmentA(const Line& line);
char findSegmentB(const Line& line);
char findSegmentC(const Line& line);
char findSegmentD(const Line& line);
char findSegmentE(const Line& line);
char findSegmentF(const Line& line);
char findSegmentG(const Line& line);
int solution(std::vector<Line> numbers);
std::vector<Line> readInput(std::istream& is);