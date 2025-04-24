#ifndef EDGE_H
#define EDGE_H

struct Edge {
    int src;
    int dest;
    int weight;

    Edge() : src(0), dest(0), weight(0) {}
    Edge(int s, int d, int w) : src(s), dest(d), weight(w) {}

    // Needed for sorting or using in priority queues
    bool operator<(const Edge& other) const {
        return weight > other.weight;  // For min-heap behavior in std::priority_queue
    }
};

#endif
