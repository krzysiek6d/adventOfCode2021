#pragma once
#include <vector>
#include <string>
#include <sstream>

using Connection = std::pair<std::string, std::string>;
using Connections = std::vector<Connection>;

int solution(Connections connections);
Connections readConnections(std::istream& is);
