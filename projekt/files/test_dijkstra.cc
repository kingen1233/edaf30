#include <iostream>
#include <fstream>
#include <cassert>
#include "graph.h"
#include "dijkstra.h"

using std::cout;
using std::endl;

void test()
{
    Node lund{"Lund"};
    Node dalby{"Dalby"};
    Node sandby{"Sodra Sandby"};
    Node hallestad{"Torna Hallestad"};
    Node flyinge{"Flyinge"};
    Node veberod{"Veberod"};


    lund.addEdge(&dalby, 12);
    lund.addEdge(&sandby, 12);
    dalby.addEdge(&sandby, 12);
    dalby.addEdge(&veberod, 11);
    dalby.addEdge(&hallestad, 5);
    sandby.addEdge(&lund, 12);
    sandby.addEdge(&flyinge, 4);
    hallestad.addEdge(&veberod, 8);


    std::string method = "nodes";
    Dijkstra d;
    //Dijkstra, length
    std::cout << "--- Testing length function ---" << std::endl;
    d.dijkstra(&lund, [](const Node &n, const Edge &e) -> int { 
        (void)n; 
        return e.getLength(); 
        });

    assert(lund.getValue() == 0);
    assert(dalby.getValue() == 12);
    assert(sandby.getValue() == 12);
    assert(hallestad.getValue() == 17);
    assert(veberod.getValue() == 23);
    assert(flyinge.getValue() == 16);
    
    //Adding 1 more node, so that there is one path that is longer than the other
    Node eslov{"Eslov"};
    flyinge.addEdge(&eslov, 10);
    eslov.addEdge(&flyinge, 10);

    //Dijkstra, amount of nodes
    std::cout << "--- Testing amount of nodes passed function ---" << std::endl;
    d.dijkstra(&lund, [](const Node &n, const Edge &e) -> int { 
        (void)n;
        (void)e;
        return 1;
        });
    assert(lund.getValue() == 0);
    assert(dalby.getValue() == 1);
    assert(sandby.getValue() == 1);
    assert(hallestad.getValue() == 2);
    assert(veberod.getValue() == 2);
    assert(flyinge.getValue() == 2);
    assert(eslov.getValue() == 3);

#ifdef INFO
    cout << "----\nAll distances from Lund:\n";

    for (auto &t : {lund, dalby, sandby, hallestad, veberod, flyinge})
    {
        cout << t.getName() << " : " << t.getValue() << " ";
        cout << endl;
    }
#endif
    cout << "test_dijkstra passed" << endl;
}

void testUsingGraph()
{
    std::ifstream file("graf.txt");
    Graph g(file);   
    Dijkstra d;

    //Dijkstra, length
    std::cout << "--- Testing length using graph function ---" << std::endl;

    Node* lund = g.find("Lund");
    d.dijkstra(lund, [](const Node &n, const Edge &e) -> int { 
        (void)n; 
        return e.getLength(); 
        });

    Node* flyinge = g.find("Flyinge");
    Node* dalby = g.find("Dalby");
    Node* sandby = g.find("Sodra Sandby");
    Node* hallestad = g.find("Torna Hallestad");
    Node* veberod = g.find("Veberod");
    assert(lund->getValue() == 0);
    assert(dalby->getValue() == 12);
    assert(sandby->getValue() == 12);
    assert(hallestad->getValue() == 17);
    assert(veberod->getValue() == 23);
    assert(flyinge->getValue() == 16);
    
    cout << "test_dijkstra passed" << endl;
}

int main()
{
    test();
    testUsingGraph();
    return 0;
}
