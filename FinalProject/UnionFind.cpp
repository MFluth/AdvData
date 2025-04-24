#include "UnionFind.h"

UnionFind::UnionFind(int n) : parent(n), rank(n, 0) {
    for (int i = 0; i < n; ++i) parent[i] = i;
}

int UnionFind::find(int x) {
    if (parent[x] != x)
        parent[x] = find(parent[x]);
    return parent[x];
}

void UnionFind::unionSets(int x, int y) {
    int xr = find(x), yr = find(y);
    if (xr == yr) return;
    if (rank[xr] < rank[yr])
        parent[xr] = yr;
    else if (rank[xr] > rank[yr])
        parent[yr] = xr;
    else {
        parent[yr] = xr;
        rank[xr]++;
    }
}

std::vector<std::vector<int>> UnionFind::getClusters() {
    std::unordered_map<int, std::vector<int>> clusters;
    for (int i = 0; i < parent.size(); ++i) {
        int root = find(i);
        clusters[root].push_back(i);
    }
    std::vector<std::vector<int>> result;
    for (auto& kv : clusters) result.push_back(kv.second);
    return result;
}
