#include "solution.hpp"

int solution(const std::vector<int>& v)
{
    if (v.size() <= 1)
        return 0;
    auto prev = v[0];
    int num_of_increases = 0;
    for (int i = 1; i < v.size(); i++)
    {
        if (prev < v[i])
            num_of_increases++;
        prev = v[i];
    }
    return num_of_increases;
}