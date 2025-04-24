#ifndef INTERSECTION_H
#define INTERSECTION_H

#include <string>
#include "DSWTree.h"

class Intersection {
public:
    std::string id;
    int vehicleCount;
    DSWTree history;

    Intersection(std::string intersectionID);
    void updateVehicleCount(int count);
};

#endif
