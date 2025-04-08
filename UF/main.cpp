#include "uf.h"

int main()
{
    WeightedQuickUnion uf(10);

    uf.Union(1,2);
    uf.Union(1,4);
    uf.Union(2, 5);
    uf.Union(5,6);
    int root = uf.find(1);
    bool connect = uf.connected(1,2);
    cout << "Root of 1 is" << root << endl;
    uf.print();
    return 0;

}