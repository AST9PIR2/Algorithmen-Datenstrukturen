#include "edge.h"

 const std::string& Edge::getSrc() const{
     return this->src;
 }

void Edge::setSrc(std::string src) {
    this->src = src;
}
const std::string& Edge::getDest() const {
    return this->dest;
}
void Edge::setDest(std::string dest) {
    this->dest = dest;
}

int Edge::getDistance() const {
    return distance;
}

void Edge::setDistance(int distance) {
    Edge::distance = distance;
}

