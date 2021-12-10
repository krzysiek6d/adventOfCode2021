#pragma once
#include <vector>
#include <bitset>
#include <stdexcept>
#include <iostream>

template <int N>
std::pair<int, int> getNumOfOnesAndZerosOnPos(const std::vector<std::bitset<N>>& v, int bit_id)
{
    int zeros = 0;
    int ones = 0;
    for(auto bits : v)
    {
        if(bits[bit_id] == 1)
            ones++;
        else
            zeros++;
    }
    return std::make_pair(zeros, ones);
}

template <int N> 
unsigned long calculateOxygen(const std::vector<std::bitset<N>>& v)
{
    std::vector<std::bitset<N>> not_filtered_oxygen_inputs = v;
    std::vector<std::bitset<N>> oxygen_inputs = {};
    
    for(int position = N - 1; position >= 0; position--)
    {
        auto [numOfZeros, numOfOnes] = getNumOfOnesAndZerosOnPos<N>(not_filtered_oxygen_inputs, position);
        if (numOfOnes >= numOfZeros)
        {
            for (auto possible_oxygen_input: not_filtered_oxygen_inputs)
            {
                if (possible_oxygen_input[position])
                {
                    oxygen_inputs.push_back(possible_oxygen_input);
                }
            }
        }
        else
        {
            for (auto possible_oxygen_input: not_filtered_oxygen_inputs)
            {
                if (not possible_oxygen_input[position])
                {
                    oxygen_inputs.push_back(possible_oxygen_input);
                }
            }
        }

        if (oxygen_inputs.size() == 1)
        {
            not_filtered_oxygen_inputs = oxygen_inputs;
            break;
        }
        not_filtered_oxygen_inputs = oxygen_inputs;
        oxygen_inputs = {};
    }
    if (oxygen_inputs.size() != 1)
        throw std::invalid_argument("oxygen inputs contain multiple entries");

    return oxygen_inputs.front().to_ulong();
}

template <int N> 
unsigned long calculateCO2(const std::vector<std::bitset<N>>& v)
{
    std::vector<std::bitset<N>> not_filtered_co2_inputs = v;
    std::vector<std::bitset<N>> co2_inputs = {};
    
    for(int position = N - 1; position >= 0; position--)
    {
        auto [numOfZeros, numOfOnes] = getNumOfOnesAndZerosOnPos<N>(not_filtered_co2_inputs, position);
        if (numOfOnes < numOfZeros)
        {
            for (auto possible_co2_input: not_filtered_co2_inputs)
            {
                if (possible_co2_input[position])
                {
                    co2_inputs.push_back(possible_co2_input);
                }
            }
        }
        else
        {
            for (auto possible_co2_input: not_filtered_co2_inputs)
            {
                if (not possible_co2_input[position])
                {
                    co2_inputs.push_back(possible_co2_input);
                }
            }
        }

        if (co2_inputs.size() == 1)
        {
            not_filtered_co2_inputs = co2_inputs;
            break;
        }
        not_filtered_co2_inputs = co2_inputs;
        co2_inputs = {};
    }
    if (co2_inputs.size() != 1)
        throw std::invalid_argument("co2 inputs contain multiple entries");

    return co2_inputs.front().to_ulong();
}

template <int N>
unsigned long solution(const std::vector<std::bitset<N>>& v)
{
    return calculateOxygen<N>(v) * calculateCO2<N>(v);
}
