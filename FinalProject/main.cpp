#include <iostream>
#include <fstream>
#include <ctime>
#include "TrafficNetwork.h"

int main() {
    srand(time(0));
    TrafficNetwork city(100);
    city.addIntersection("A");
    city.addIntersection("B");
    city.addIntersection("C");
    city.addIntersection("D");

    std::ofstream outFile("traffic_report.txt");

    // Simulate dynamic traffic updates
    for (int t = 1; t <= 5; ++t) {
        city.updateTraffic("A", rand() % 100, t);
        city.updateTraffic("B", rand() % 100, t);
        city.updateTraffic("C", rand() % 100, t);
        city.updateTraffic("D", rand() % 100, t);
    }

    city.mergeCongestion("A", "C");
    city.mergeCongestion("B", "D");

    city.showRanking(outFile);
    city.showHistoricalData("A", outFile);
    city.showCongestionClusters(outFile);

    outFile.close();
    std::cout << "Traffic report saved to traffic_report.txt" << std::endl;
    return 0;
}
