
#ifndef GRAPH_H
#define GRAPH_H

#include <memory>
#include <vector>
#include <iostream>
#include <algorithm>
#include "node.h"

class node;

class Graph {
public:
	Graph(); 
    Graph(std::istream& in);
    ~Graph();
    void addNode(const std::string& name);
    Node* find(const std::string& name);
    void resetVals();
	std::vector<Node*>::iterator begin();
    std::vector<Node*>::iterator end();

private:
    std::vector<Node*> graph;
};



#endif

