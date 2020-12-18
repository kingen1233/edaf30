#ifndef EDGE_H
#define EDGE_H

#include "node.h"

class Node;

class Edge {
public:
	Edge(Node* destination, int length);
    Node* getDestination();
    int getLength() const;
	
private:
    Node* edgeDest;
    int edgeLength;
};

#endif
