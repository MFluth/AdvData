#ifndef TRAFFICNETWORK_H
#define TRAFFICNETWORK_H

#include <string>
#include <unordered_map>
#include "UnionFind.h"
#include "AVLTree.h"
#include "DSWTree.h"
#include "Intersection.h"

class TrafficNetwork {
private:
    std::unordered_map<std::string, Intersection> intersections;
    AVLTree trafficRank;
    UnionFind unionFind;
    int index;
    std::unordered_map<std::string, int> idToIndex;

public:
    TrafficNetwork(int maxSize);
    void addIntersection(std::string id);
    void updateTraffic(std::string id, int vehicleCount, int timestamp);
    void mergeCongestion(std::string id1, std::string id2);
    void showRanking(std::ofstream& out);
    void showHistoricalData(std::string id, std::ofstream& out);
    void showCongestionClusters(std::ofstream& out);
};

#endif
