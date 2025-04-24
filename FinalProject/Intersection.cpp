#include "Intersection.h"

Intersection::Intersection(std::string intersectionID) : id(intersectionID), vehicleCount(0) {}

void Intersection::updateVehicleCount(int count) {
    vehicleCount = count;
}
