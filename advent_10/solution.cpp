#include "solution.hpp"
#include <vector>
#include <algorithm>
#include <iterator>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <iostream>
#include <unordered_map>


int solution(std::vector<std::string> lines)
{
    std::unordered_map<char, int> bad;
    bad[')'] = 0;
    bad[']'] = 0;
    bad['}'] = 0;
    bad['>'] = 0;
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
                    throw std::runtime_error("closing now?");
                auto topElement = st.top(); 
                st.pop();
                if (openingForCloseBracket.at(ch) != topElement)
                {
                    std::cout << "Expected "<< closingForOpeningBracket[topElement] << ", but found " << ch << " instead." << std::endl;
                    bad[ch]++;
                    continue;
                }
            }
        }
    }
    return bad[')'] * 3 + bad[']'] * 57 + bad['}'] * 1197 + bad['>'] * 25137;
}


std::vector<std::string> readLines(std::istream& is)
{
    std::vector<std::string> data;
    std::copy(std::istream_iterator<std::string>(is), std::istream_iterator<std::string>(), back_inserter(data));
    return data;
}