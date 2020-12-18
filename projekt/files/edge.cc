#include "edge.h"

/** Skapa en ny båge till noden destination, med längden length. */
Edge::Edge(Node* destination, int length){
    edgeDest = destination;
    edgeLength = length;
}

/** Hämtar bågens destination. */
Node* Edge::getDestination(){
    return edgeDest;
}

/** Hämtar bågens längd. */
int Edge::getLength() const{
    return edgeLength;
}