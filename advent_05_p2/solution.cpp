#include "solution.hpp"
#include <stdexcept>
#include <iostream>
#include <map>

Pipe::Pipe(std::pair<int, int> from, std::pair<int, int> to)
{
    auto [from_x, from_y] = from;
    auto [to_x, to_y] = to;
    if (from_x == to_x)
    {
        auto x = from_x;
        auto smaller_y = std::min(from_y, to_y);
        auto greater_y = std::max(from_y, to_y);
        for (int y = smaller_y; y <= greater_y; y++)
            pipeElements.push_back(std::make_pair(x, y));
    }
    else if (from_y == to_y)
    {
        auto y = from_y;
        auto smaller_x = std::min(from_x, to_x);
        auto greater_x = std::max(from_x, to_x);
        for (int x = smaller_x; x <= greater_x; x++)
            pipeElements.push_back(std::make_pair(x, y));
    }
    else
    {
        auto diff_x = to_x - from_x;
        auto diff_y = to_y - from_y;

        int x = from_x;
        int y = from_y;

        for (; x != to_x && y != to_y; )
        {
            pipeElements.push_back(std::make_pair(x, y));
            x = x + abs(diff_x)/diff_x;
            y = y + abs(diff_y)/diff_y;
        }
        pipeElements.push_back(std::make_pair(x, y));
    }
}

std::vector<std::pair<int, int>> Pipe::getPipeElements() const
{
    return pipeElements;
}

std::vector<Pipe> readPipes(std::istream& is)
{
    std::vector<Pipe> pipes;
    for (std::string line; std::getline(is, line, '\n');)
    {
        if(line.empty() || std::all_of(line.begin(), line.end(), [](const auto& ch){ return ch == ' ';}))
            continue;
        std::istringstream ss;
        ss.str(line);
        std::string from;
        std::string arrow;
        std::string to;
        ss >> from >> arrow >> to;

        auto replaceCommaWithSpace = [](const auto& ch){ if (ch == ',') return ' '; return ch;};

        std::istringstream ss_from;
        std::transform(from.begin(), from.end(), from.begin(), replaceCommaWithSpace);
        ss_from.str(from);

        std::istringstream ss_to;
        std::transform(to.begin(), to.end(), to.begin(), replaceCommaWithSpace);
        ss_to.str(to);
        std::cout << "parsed: from[" << from << "] arrow[" << arrow << "] to ["<< to << "] " << std::endl;

        int from_x, from_y;
        int to_x, to_y;

        ss_from >> from_x >> from_y;
        ss_to >> to_x >> to_y;

        try 
        {
            auto p = Pipe(std::make_pair(from_x, from_y), std::make_pair(to_x, to_y));
            pipes.push_back(p);
        }
        catch(const std::exception& ex)
        {
            std::cout << "ommiting value because of error: " << ex.what() << std::endl;
        }
    }
    return pipes;
}

int solution(const std::vector<Pipe>& pipes)
{
    std::map<std::pair<int, int>, int> occurences;
    for (const auto& pipe: pipes)
    {
        for (const auto& entry: pipe.getPipeElements())
        {
            occurences[entry]++;
        }
    }
    auto duplicates = std::count_if(occurences.begin(), occurences.end(), [](const auto& occurence)
    {
        auto [entry, numOfDuplicates] = occurence;
        if (numOfDuplicates > 1)
            return true;
        return false;
    });
    return duplicates;
}