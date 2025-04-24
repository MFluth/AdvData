#ifndef UNIONFIND_H
#define UNIONFIND_H

#include <vector>
#include <unordered_map>

class UnionFind {
    std::vector<int> parent, rank;
public:
    UnionFind(int n);
    int find(int x);
    void unionSets(int x, int y);
    std::vector<std::vector<int>> getClusters();
};

#endif
