#pragma once
#include <vector>
#include <array>

struct Line
{
    std::array<std::string, 10> numbers;
    std::array<std::string, 4> question;

};

std::ostream& operator<<(std::ostream& os, const Line& line);

int solution(std::vector<Line> numbers);
std::vector<Line> readInput(std::istream& is);