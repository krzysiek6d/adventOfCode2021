#pragma once
#include <vector>
#include <string>
#include <sstream>

std::pair<long, std::vector<std::vector<int>>> solution(std::vector<std::vector<int>> map, int steps);
std::vector<std::vector<int>> readMap(std::istream& is);
