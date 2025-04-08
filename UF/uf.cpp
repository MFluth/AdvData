#include "uf.h"

WeightedQuickUnion::WeightedQuickUnion(int n)
{
    this->n = n;
    parent = new int[n];
    size = new int[n];

    // initialize the array
    for (int i = 0; i < n; i++)
    {
        parent[i] = i;
        size[i] = 1;
    }
}

WeightedQuickUnion::~WeightedQuickUnion()
{
    delete[] parent;
    delete[] size;
}

int WeightedQuickUnion::find(int p)
{
    while(p != parent[p])
    {
        parent[p] = parent[parent[p]];
        p = parent[p];
    }
    return p;
}

void WeightedQuickUnion::Union(int p, int q)
{
    int rootP = find(p);
    int rootQ = find(q);

    if (rootP = rootQ)
    {
        return;
    }

    //Union by size/rank
    if (size[rootP] < size[rootQ])
    {
        parent[rootP] = rootQ;
        size[rootQ] += size [rootP];
    }
    else
    {
        parent[rootQ] = rootP;
        size[rootP] += size[rootQ];
    }
}

bool WeightedQuickUnion::connected(int p, int q)
{
    return find(p) == find (q);
}

void WeightedQuickUnion::print()
{
    cout << "Parent" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << size[i] << " ";
    }
    cout << endl;
}