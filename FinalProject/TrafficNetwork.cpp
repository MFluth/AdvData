#include "TrafficNetwork.h"
#include <fstream>
#include <cstdlib>
#include "Intersection.h"

TrafficNetwork::TrafficNetwork(int maxSize) : unionFind(maxSize), index(0) {}

void TrafficNetwork::addIntersection(std::string id) {
    intersections[id] = Intersection(id);
    idToIndex[id] = index++;
}

void TrafficNetwork::updateTraffic(std::string id, int vehicleCount, int timestamp) {
    intersections[id].vehicleCount = vehicleCount;
    intersections[id].history.insert(timestamp, vehicleCount);
    trafficRank.insert(id, vehicleCount);
}

void TrafficNetwork::mergeCongestion(std::string id1, std::string id2) {
    unionFind.unionSets(idToIndex[id1], idToIndex[id2]);
}

void TrafficNetwork::showRanking(std::ofstream& out) {
    out << "\nTraffic Ranking (High to Low):\n";
    trafficRank.displayDescending(out);
}

void TrafficNetwork::showHistoricalData(std::string id, std::ofstream& out) {
    if (intersections.find(id) != intersections.end()) {
        out << "\nHistory for Intersection " << id << ":\n";
        intersections[id].history.displayHistory(out);
    }
}

void TrafficNetwork::showCongestionClusters(std::ofstream& out) {
    auto clusters = unionFind.getClusters();
    out << "\nCongestion Clusters:\n";
    for (auto& cluster : clusters) {
        out << "[ ";
        for (int i : cluster) {
            for (auto& kv : idToIndex)
                if (kv.second == i)
                    out << kv.first << " ";
        }
        out << "]\n";
    }
}
