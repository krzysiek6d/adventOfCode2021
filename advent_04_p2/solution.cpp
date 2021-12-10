#include "solution.hpp"
#include <vector>
#include <algorithm>
#include <iterator>
#include <sstream>


int solution(std::vector<BingoTable> v, const std::vector<int>& numbers)
{
    std::vector<bool> winners(v.size(), false);
    int lastWinner = -1;
    int lastNum = 0;
    for(const auto& num: numbers)
    {
        for (int i = 0; i < v.size(); i++)
        {
            if (winners[i])
            {
                continue;
            }
            auto& bingoTable = v[i];
            bingoTable.set(num);
            if (bingoTable.isBingo())
            {
                winners[i] = true;
                lastWinner = i;
                lastNum = num;
            }
        }
    }
    if (lastWinner == -1)
        return 0;
    
    return v[lastWinner].sumOfNotMarked() * lastNum;
}

bool BingoTable::isBingo() const
{
    for (const auto& row: table)
    {
        if (std::all_of(row.begin(), row.end(), [](const auto& entry){return entry.match;}))
            return true;
    }
    for (int i = 0; i < 5; i++)
    {
        if (std::all_of(table.begin(), table.end(), [i](const auto& row){return row[i].match;}))
            return true;
    }
    return false;
}

void BingoTable::set(int num)
{
    for (auto& row: table)
    {
        for(auto &entry: row)
        {
            if (entry.value == num)
                entry.match = true;
        }
    }
}

int BingoTable::sumOfNotMarked() const
{
    int sum = 0;
    for (auto& row: table)
    {
        for(auto &entry: row)
        {
            if (entry.match == false)
                sum += entry.value;
        }
    }
    return sum;
}

std::ostream& operator<<(std::ostream& os, const BingoTable& b)
{
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            os << b.table[i][j].value << " ";
        }
        os << std::endl;
    }
    return os;
}

std::istream& operator>>(std::istream& is, BingoTable& b)
{
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            int value = 0;
            is >> value;
            b.table[i][j].value = value;
            b.table[i][j].match = false;
        }
    }
    return is;
}

std::vector<int> readNums(std::istream& is)
{
    std::vector<int> bingoNumbers;
    std::string line;
    std::getline(is, line, '\n');
    std::istringstream input;
    input.str(line);
    for (std::string line; std::getline(input, line, ','); ) {
        bingoNumbers.push_back(std::stoi(line));
    }
    return bingoNumbers;
}

std::vector<BingoTable> readTables(std::istream& is)
{
    std::vector<BingoTable> data;
    std::copy(std::istream_iterator<BingoTable>(is), std::istream_iterator<BingoTable>(), back_inserter(data));
    return data;
}