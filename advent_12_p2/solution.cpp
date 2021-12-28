#include "solution.hpp"
#include <vector>
#include <algorithm>
#include <iterator>
#include <sstream>
#include <iostream>
#include <set>
#include <cassert>
#include <map>

void printConnections(const Connections& connections)
{
    for (auto [from, to]: connections)
    {
        std::cout << from << " - " << to << std::endl;
    }
}

void printNeighbors(const std::vector<std::string>& neighbors)
{
    for(const auto& n: neighbors)
    {
        std::cout << n << " ";
    }
    std::cout << std::endl;
}

std::vector<std::string> getNeighbors(const Connections& connections, const std::string& node)
{
    std::vector<std::string> neighbors;
    for(auto [v1, v2]: connections)
    {
        if (v1 == node)
            neighbors.push_back(v2);
        else if (v2 == node)
            neighbors.push_back(v1);
    }
    return neighbors;
}

bool isSmall(const std::string& node)
{
    assert(node.length() > 0);
    return node[0] >= 'a' && node[0] <= 'z';
}

bool mayBeVisitedTwice(const std::string& node)
{
    return isSmall(node) && node != "start" && node != "end";
}

bool isAnyOfSmallCavesVisitedTwice(std::map<std::string, int> visited)
{
    return std::any_of(visited.begin(), visited.end(), [](auto c){return c.second==2;});
}

int waysToEnd(const Connections& connections, const std::string& node, std::map<std::string, int> visited, std::vector<std::string> path)
{
    int ways = 0;
    path.push_back(node);
    if (node == "end")
    {
        for (const auto& p: path)
            std::cout << p << ",";
        std::cout << std::endl;
        return 1;
    }
    if (visited.count(node) == 0 || !isAnyOfSmallCavesVisitedTwice(visited) && mayBeVisitedTwice(node) && visited[node] <= 1)
    {
        if (isSmall(node))
        {
            visited[node]++;
            //std::cout << node << " visited " << visited[node] << std::endl;
        }
        auto neighbors = getNeighbors(connections, node);
        for(const auto& n: neighbors)
        {
            ways += waysToEnd(connections, n, visited, path);
        }
    }
    return ways;
}

int solution(Connections connections)
{
    return waysToEnd(connections, "start", {}, {});
}


Connections readConnections(std::istream& is)
{
    std::vector<std::string> data;
    std::copy(std::istream_iterator<std::string>(is), std::istream_iterator<std::string>(), back_inserter(data));

    Connections connections;
    for(auto&& line: data)
    {
        std::string from;
        std::string to;
        std::replace(line.begin(), line.end(), '-', ' ');
        std::istringstream is;
        is.str(line);
        is >> from >> to;
        connections.push_back(Connection(from, to));
    }
    return connections;
}