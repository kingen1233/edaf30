#include "graph.h"
using std::string;
Graph::Graph()
{
}

Graph::Graph(std::istream &in)
{
    string line;

    while (std::getline(in, line))
    {
        int idx = line.find(":");
        string startNode = line.substr(0, idx);
        //Node n(startNode);
        line.erase(0, idx + 1);
        idx = line.find(" ");
        int length = std::stoi(line.substr(0, idx - 1));
        string destination = "";
        if (length > 9) {
            destination = line.substr(idx + 4, (line.length() - idx + 1));
        }
        else {
            destination = line.substr(idx + 3, (line.length() - idx + 1));
        }
        //Node dest(destination);
        addNode(destination);
        addNode(startNode);
        Node *start = find(startNode);
        Node *dest = find(destination);
        start->addEdge(dest, length);

        /*std::cout << startNode << length <<  destination << std::endl;
        n.addEdge(&dest, length);
        addNode(&n);*/
    }
}

Graph::~Graph()
{
    for (auto i : graph)
    {
        delete i;
    }
}

void Graph::addNode(const std::string &name)
{
    graph.push_back(new Node(name));
}

void Graph::addNode(Node *node)
{
    graph.push_back(node);
}

Node *Graph::find(const std::string &name)
{

    auto comp = [name](Node *n1) {
        return !name.compare(n1->getName());
    };
    auto foundNode = std::find_if(graph.begin(), graph.end(), comp);
    if (foundNode != graph.end())
    {
        return *foundNode;
    }
    return nullptr;
}

void Graph::resetVals()
{
    int max = std::numeric_limits<int>::max();
    for (auto i : graph)
    {
        i->setValue(max);
    }
}

std::vector<Node *>::iterator Graph::begin()
{
    return graph.begin();
}

std::vector<Node *>::iterator Graph::end()
{
    return graph.end();
}
