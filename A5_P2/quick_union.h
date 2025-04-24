// quick_union.h
#ifndef QUICK_UNION_H
#define QUICK_UNION_H

#include <vector>

class QuickUnion {
private:
    std::vector<int> parent;

public:
    QuickUnion(int n) {
        parent.resize(n);
        for (int i = 0; i < n; ++i) parent[i] = i;
    }

    int find(int x) {
        while (x != parent[x]) x = parent[x];
        return x;
    }

    void unite(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX != rootY) parent[rootX] = rootY;
    }

    bool connected(int x, int y) {
        return find(x) == find(y);
    }
};

#endif
