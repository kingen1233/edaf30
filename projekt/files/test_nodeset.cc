#include "node_set.h"
#include "node.h"
#include <cassert>
#include <iostream>

void test()
{
    NodeSet ns{};

    Node a("A");
    a.setValue(10);
    Node b("B");
    b.setValue(20);
    Node c("C");
    c.setValue(30);

    ns.add(&a);
    ns.add(&b);
    ns.add(&c);

    assert(ns.removeMin() == &a);
    assert(ns.removeMin() == &b);
    assert(ns.removeMin() == &c);
    assert(ns.isEmpty());

    ns.add(&a);
    assert(!ns.isEmpty());

    ns.add(&b);
    assert(!ns.isEmpty());

    ns.add(&c);
    assert(!ns.isEmpty());

    ns.add(&a);
    assert(!ns.isEmpty());

    a.setValue(40);
    std::cout << a.getValue() << b.getValue() << c.getValue() << std::endl;
    assert(ns.removeMin() == &b);
    assert(ns.removeMin() == &c);
    assert(ns.removeMin() == &a);

    assert(ns.isEmpty());
}

int main()
{
    test();
    std::cout << "test_nodeset passed" << std::endl;
    return 0;
}
