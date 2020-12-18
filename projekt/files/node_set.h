#ifndef NODESET_H
#define NODESET_H

#include "node.h"
#include <set>


struct classcomp {
  bool operator() (const Node* n1, const Node* n2) const
  {return n1->getValue() < n2->getValue();}
};
class NodeSet
{
public:
    NodeSet();
    void add(Node *node);
    bool isEmpty();
    Node *removeMin();

private:
    std::vector<Node*> nodeSet;
};

#endif