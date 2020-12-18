#include <iostream>
#include <cassert>
#include "graph.h"
#include <algorithm>
#include <utility>
#include <set>
#include <string>

using std::cout;
using std::endl;

void print_neighbours(Node* n)
{
    cout << "Anslutningar från " << n->getName() << "(" << n->getValue() << ") :\n";
    for(auto de : n->getEdges()){
        cout << de.getLength() << " to " << de.getDestination()->getName() << endl;
    }
}

Node* find_and_test(const std::string& s, Graph& g)
{
    Node* n = g.find(s);
    assert(n != nullptr);
    assert(n->getName() == s);
    assert(n->getValue() == Node::max_value);
    return n;
}

void test_graph()
{
    Graph g{};
    g.addNode("Lund");
    g.addNode("Dalby");
    g.addNode("Sodra Sandby");
    g.addNode("Flyinge");
    g.addNode("Torna Hallestad");
    g.addNode("Veberod");

    auto n_lund = find_and_test("Lund", g);
    find_and_test("Dalby", g);
    find_and_test("Sodra Sandby", g);
    find_and_test("Veberod", g);
    find_and_test("Torna Hallestad", g);
    auto n_flyinge = find_and_test("Flyinge", g);

    n_lund->setValue(17);
    auto n2 = g.find("Lund");
    assert(n2->getValue()==17);

    auto n3 = g.find("Flyinge");
    n_flyinge->setValue(42);
    assert(n3->getValue()==42);

    g.resetVals();
    for(auto it = g.begin(); it != g.end(); ++it){
        assert((*it)->getValue() == Node::max_value);
    }
    cout << "test_graph passed" << endl;
}


int main()
{
    test_graph();
    return 0;
}
