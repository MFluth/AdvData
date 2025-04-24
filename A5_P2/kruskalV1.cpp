#include "quick_union.h"
#include <queue>
#include <vector>
#include "edge.h"  // Assuming this struct contains: int src, dest, weight

bool compareEdges(const Edge& a, const Edge& b) {
    return a.weight > b.weight;  // For min-heap
}

std::vector<Edge> kruskalV1(std::vector<Edge>& edges, int numVertices) {
    std::priority_queue<Edge, std::vector<Edge>, decltype(&compareEdges)> pq(compareEdges);
    for (Edge e : edges) pq.push(e);

    QuickUnion qu(numVertices);
    std::vector<Edge> mst;

    while (!pq.empty() && mst.size() < numVertices - 1) {
        Edge e = pq.top(); pq.pop();
        if (!qu.connected(e.src, e.dest)) {
            qu.unite(e.src, e.dest);
            mst.push_back(e);
        }
    }
    return mst;
}
