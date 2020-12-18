#ifndef NODE_H
#define NODE_H

#include "edge.h"
#include <string>
#include <limits>
#include <vector>
class Edge;

class Node
{
public:
    Node(const std::string &name);
    std::string getName() const;
    void setValue(int v);
    int getValue() const;
    void addEdge(Node *destination, int length);
    const std::vector<Edge> &getEdges() const;
    static const int max_value = std::numeric_limits<int>::max();

private:
    std::string nodeName;
    std::vector<Edge> edges;
    int value;    
};



#endif