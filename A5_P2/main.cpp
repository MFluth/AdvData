#include <iostream>
#include <vector>
#include <chrono>
#include "edge.h"

using namespace std;
using namespace std::chrono;

// Declarations from kruskalV1.cpp and kruskalV2.cpp
vector<Edge> kruskalV1(const vector<Edge>& edges, int numVertices);
vector<Edge> kruskalV2(const vector<Edge>& edges, int numVertices);

int main() {
    vector<Edge> edges = {
        {0, 1, 4},
        {0, 2, 3},
        {1, 2, 1},
        {1, 3, 2},
        {2, 3, 4},
        {3, 4, 2},
        {4, 5, 6}
    };
    int numVertices = 6;

    // Version 1
    cout << "Running Kruskal V1 (Binary Heap + Quick Union)\n";
    auto start1 = high_resolution_clock::now();
    vector<Edge> mst1 = kruskalV1(edges, numVertices);
    auto end1 = high_resolution_clock::now();

    cout << "MST from Kruskal V1:\n";
    for (const Edge& e : mst1)
        cout << e.src << " -- " << e.dest << " == " << e.weight << endl;
    cout << "Time: " << duration_cast<milliseconds>(end1 - start1).count() << " ms\n\n";

    // Version 2
    cout << "Running Kruskal V2 (Binomial Heap + Union-Find)\n";
    auto start2 = high_resolution_clock::now();
    vector<Edge> mst2 = kruskalV2(edges, numVertices);
    auto end2 = high_resolution_clock::now();

    cout << "MST from Kruskal V2:\n";
    for (const Edge& e : mst2)
        cout << e.src << " -- " << e.dest << " == " << e.weight << endl;
    cout << "Time: " << duration_cast<milliseconds>(end2 - start2).count() << " ms\n";

    return 0;
}