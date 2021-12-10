#pragma once
#include <vector>
#include <bitset>

template <int N>
int solution(const std::vector<std::bitset<N>>& v)
{
    std::vector<int> bit_count(N, 0);
    for(auto bits : v)
    {
        for(int bit_id = 0; bit_id < N; bit_id++)
        {
            if(bits[bit_id] == 1)
                bit_count[bit_id]++;
        }
    }
    std::bitset<N> gamma_rate{""};
    for(int bit_id = 0; bit_id < N; bit_id++)
    {
        if (bit_count[bit_id] > v.size()/2)
            gamma_rate.set(bit_id, true);
    }
    std::bitset<N> epsilon_rate = gamma_rate;
    epsilon_rate.flip();

    return gamma_rate.to_ulong() * epsilon_rate.to_ulong();
}