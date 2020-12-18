#include "node_set.h"
#include <iterator>
#include <string>
#include <algorithm>
#include <iostream>
/** Skapar en tom mängd av noder. */
NodeSet::NodeSet(){

}

/** Lägger till noden node till mängden,
om mängden inte redan innehåller en nod med samma namn. */
void NodeSet::add(Node* node){
    //Itererar över alla element i nodeSet. Om namnet för den nod som skickas in redan finns i vektorn görs ingenting, om inte läggs noden till.
    auto itr = std::find_if(nodeSet.begin(), nodeSet.end(), [&node](const Node* n) {return n->getName() == node->getName();});
    if(itr == nodeSet.end()){
       nodeSet.push_back(node);
    }
    return;
}

/** Returnerar true om mängden noder är tom. */
bool NodeSet::isEmpty(){
    return nodeSet.size() == 0;
}

/** Väljer ut den nod som har lägst värde och returnerar den.
Den returnerade noden tas bort ur mängden.
Om mängden är tom returneras null. */
Node* NodeSet::removeMin(){

    if (!isEmpty()){
        // Create a comperator for Nodes, based on their value
        auto comp = [](Node* n1, Node* n2){ return n1->getValue() < n2->getValue(); };
        // Use comperator to find node with the smallest value
        std::vector<Node*>::iterator min = std::min_element(nodeSet.begin(), nodeSet.end(), comp);
        Node* min_element = *min;
        nodeSet.erase(min);
        return min_element;
    }
    
    return NULL;

}