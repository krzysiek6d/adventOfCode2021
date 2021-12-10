#pragma once
#include <vector>
#include <sstream>
#include <utility>

class Pipe
{
    public:
    Pipe(std::pair<int, int> from, std::pair<int, int> to);
    std::vector<std::pair<int, int>> getPipeElements() const;
    private:
    std::vector<std::pair<int, int>> pipeElements;
};

std::vector<Pipe> readPipes(std::istream& is);

int solution(const std::vector<Pipe>& pipes);