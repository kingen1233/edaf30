#include "dijkstra.h"

Dijkstra::Dijkstra(){
}

void Dijkstra::dijkstra(Node *start){
    NodeSet set;
    start->setValue(0);
    set.add(start);
    while (!set.isEmpty()){
        Node *prevNode = set.removeMin();
        std::vector<Edge> list = prevNode->getEdges();

        for (Edge e : list){
            Node *nextNode = e.getDestination();
            int dist = prevNode->getValue() + e.getLength();
            
            if (dist < nextNode->getValue()){
                nextNode->setValue(dist);
                set.add(nextNode);
            }
        }
    }
}