#include "graph.h"

Graph::Graph(){
}

Graph::Graph(std::istream& in){
    
} 
 
Graph::~Graph(){
    for(auto i : graph){
        delete i;
    }
}

void Graph::addNode(const std::string& name){
    graph.push_back(new Node(name));
}

Node *Graph::find(const std::string& name) {
    
    auto comp = [name](Node* n1){ 
            return !name.compare(n1->getName());
    };
    auto foundNode = std::find_if(graph.begin(), graph.end(), comp);
    if (foundNode != graph.end()){       
        Node* temp = *foundNode;
        return *foundNode;
    }
    return nullptr;
}

void Graph::resetVals(){
    int max = std::numeric_limits<int>::max();
    for(auto i : graph){
        i->setValue(max);
    }
}

std::vector<Node*>::iterator Graph::begin(){
    return graph.begin();
}

std::vector<Node*>::iterator Graph::end(){
    return graph.end();
}
