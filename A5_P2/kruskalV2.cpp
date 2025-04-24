#include "union_find.h"
#include "BinomialHeap.h"  // Or whatever it’s called
#include <vector>
#include "edge.h"

std::vector<Edge> kruskalV2(std::vector<Edge>& edges, int numVertices) {
    BinomialHeap<Edge> heap; // Assuming BinomialHeap supports insert and extractMin
    for (Edge e : edges) heap.insert(e);

    UnionFind uf(numVertices);
    std::vector<Edge> mst;

    while (!heap.isEmpty() && mst.size() < numVertices - 1) {
        Edge e = heap.extractMin();
        if (!uf.connected(e.src, e.dest)) {
            uf.unite(e.src, e.dest);
            mst.push_back(e);
        }
    }
    return mst;
}
