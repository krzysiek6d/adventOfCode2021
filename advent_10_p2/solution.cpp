#include "solution.hpp"
#include <vector>
#include <algorithm>
#include <iterator>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <iostream>
#include <unordered_map>


long solution(std::vector<std::string> lines)
{
    std::unordered_map<char, int> points;
    points[')'] = 1;
    points[']'] = 2;
    points['}'] = 3;
    points['>'] = 4;
    std::unordered_map<char, char> openingForCloseBracket{
        {')', '('}, 
        {'>', '<'}, 
        {'}', '{'},
        {']', '['}};
    std::unordered_map<char, char> closingForOpeningBracket{
        {'(', ')'}, 
        {'<', '>'}, 
        {'{', '}'},
        {'[', ']'}};
    std::vector<long> scores;

    for (const auto& line: lines)
    {
        std::cout << "line" << line << std::endl;
        std::stack<char> st = {};
        for (auto ch : line)
        {
            if (std::string("(<{[").find(ch) != std::string::npos)
                st.push(ch);
            else
            {
                if (st.empty())
                    break;
                auto topElement = st.top(); 
                st.pop();
                if (openingForCloseBracket.at(ch) != topElement)
                {
                    // broken
                    st = std::stack<char>();
                    break;
                }
            }
        }
        long singleScore = 0;
        while (!st.empty())
        {
            //std::cout << closingForOpeningBracket[st.top()] << std::endl;
            singleScore = singleScore * 5 + points[closingForOpeningBracket[st.top()]];
            st.pop();
        }
        if (singleScore != 0)
        {
            std::cout << "score: " << singleScore << std::endl;
            scores.push_back(singleScore);
        }
        
    }
    std::sort(scores.begin(), scores.end());
    if (scores.empty())
        return 0;
    return scores[scores.size()/2];
}


std::vector<std::string> readLines(std::istream& is)
{
    std::vector<std::string> data;
    std::copy(std::istream_iterator<std::string>(is), std::istream_iterator<std::string>(), back_inserter(data));
    return data;
}