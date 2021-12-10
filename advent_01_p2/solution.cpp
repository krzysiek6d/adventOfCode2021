#include "solution.hpp"

int solution(const std::vector<int>& v)
{
    if (v.size() <= 3)
        return 0;
    auto prev = v[0] + v[1] + v[2];
    int num_of_increases = 0;
    for (int i = 1; i < v.size() - 2; i++)
    {
        auto curr_window = v[i] + v[i+1] + v[i+2];
        if (prev < curr_window)
            num_of_increases++;
        prev = curr_window;
    }
    return num_of_increases;
}