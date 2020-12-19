#include "node.h"

/** Skapar en nod med givet namn, utan bågar och med maximalt värde. */
Node::Node(const std::string& name){
    nodeName = name;
    value = std::numeric_limits<int>::max();
}

/** Hämtar nodens namn. */
std::string Node::getName() const{
    return nodeName;
}

/** Sätter nodens värde till v. */
void Node::setValue(int v){
    value = v;
}

/** Hämtar nodens värde. */
int Node::getValue() const{
    return value;
}

/** Lägger till en ny båge från denna nod till en given destination.
Bågen ska ha längden length. */
void Node::addEdge(Node* destination, int length){
    edges.emplace_back(destination, length);
}

/** Hämtar de bågar som utgår från denna nod. */
const std::vector<Edge>& Node::getEdges() const{
    return edges;
}

void Node::setParent(Node* node){
    parent = node;
}

Node* Node::getParent() const{
    return parent;
}