#include "dijkstra.h"
#include <iostream>

Dijkstra::Dijkstra(){
}

void Dijkstra::dijkstra(Node *start, int (*f)(const Node&, const Edge&)){
    NodeSet set;
    Node *prevNode = start;
    start->setValue(0);
    set.add(start);
    while (!set.isEmpty()){
        prevNode = set.removeMin();
        std::vector<Edge> list = prevNode->getEdges();

        for (Edge e : list){
            Node *nextNode = e.getDestination();
            int dist = 0;
            int cost = (*f)(*nextNode, e);
            dist = prevNode->getValue() + cost;

            if (dist < nextNode->getValue()){
                nextNode->setValue(dist);
                nextNode->setParent(prevNode);
                set.add(nextNode);
            }
        }
    }

    printPath(prevNode);    
}


void Dijkstra::printPath(Node* lastNode){
    std::vector<std::string> nodePath;
    //Length is always equal to the last nodes value, since this is the furthest one
    int length = lastNode->getValue();
    //Add to list
    while(lastNode->getParent() != nullptr) {
        nodePath.push_back(lastNode->getName());  
        lastNode = lastNode->getParent();  
    }

    nodePath.push_back(lastNode->getName());   

    //Traverse vector and print elements
    while(nodePath.size()){
        std::string element = nodePath.back();
        nodePath.pop_back();
        std::cout << element << " ";
    }
    std::cout << length << std::endl;

}