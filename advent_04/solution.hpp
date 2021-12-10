#pragma once
#include <vector>
#include <array>

struct BingoTableElem
{
    int value;
    bool match;
};

struct BingoTable
{
    std::array<std::array<BingoTableElem, 5>, 5> table;

    bool isBingo() const;
    void set(int num);
    int sumOfNotMarked() const;
};


int solution(std::vector<BingoTable> v, const std::vector<int>& numbers);
std::ostream& operator<<(std::ostream& os, const BingoTable& b);
std::istream& operator>>(std::istream& is, BingoTable& b);

std::vector<int> readNums(std::istream& is);
std::vector<BingoTable> readTables(std::istream& is);