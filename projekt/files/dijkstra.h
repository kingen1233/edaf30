#ifndef DIJKSTRA_H
#define DIJKSTRA_H

#include "node_set.h"
#include "node.h"

class node;
class node_set;

class Dijkstra {
public:
	Dijkstra();
    void dijkstra(Node *start, int (*f)(const Node&, const Edge&));   
	
private:
    void printPath(Node* lastnode);
};



#endif
