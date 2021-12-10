#pragma once
#include <vector>
#include <stdexcept>
#include <iostream>

enum class Direction
{
    up,
    down,
    forward
};

struct Move
{
    Direction direction;
    int value;
};

std::istream& operator>>(std::istream& is, Move& m);



int solution(const std::vector<Move>& v);