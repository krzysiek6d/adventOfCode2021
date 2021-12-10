#include "solution.hpp"

std::istream& operator>>(std::istream& is, Move& m)
{
    std::string direction = "";
    int value = 0;
    is >> direction >> value;
    std::cout << "direction is: " << direction << std::endl;
    std::cout << "value is: " << value << std::endl;
    if (direction == "up")
        m.direction = Direction::up;
    else if(direction == "down")
        m.direction = Direction::down;
    else if(direction == "forward")
        m.direction = Direction::forward;
    else
    {
        m.direction = Direction::up;
        m.value = 0;
        std::cerr << "direction [" + direction + "] string is invalid";
        return is;
    }
    m.value = value;
    return is;
}

int solution(const std::vector<Move>& v)
{
    int depth = 0;
    int horizontal = 0;
    for (auto [direction, value] : v)
    {
        switch (direction)
        {
        case Direction::down:
            depth += value;
            break;
        case Direction::up:
            depth -= value;
            break;
        case Direction::forward:
            horizontal += value;
            break;
        }
    }
    return depth * horizontal;
}