#include <iostream>
#include <sstream>
#include <string>
#include "date.h"
using namespace std;

template <typename T>
string toString(T t)
{
    std::stringstream s;
    s << t;
    return s.str();
}

void checkStringRepresentation(string toString, string expectedOutcome)
{
    if (toString == expectedOutcome)
    {
        cout << "Correct! " << toString << " equals " << expectedOutcome << endl;
    }
    else
    {
        cout << "False! " << toString << " does not equal "<< expectedOutcome << endl;
    }
}

int main()
{
    Date dt(2020,10,02);
    double db = 1.234;
    float f = 0.94;
    
    checkStringRepresentation(toString(dt),"2020-10-02");
    checkStringRepresentation(toString(db),"1.234");
    checkStringRepresentation(toString(f),"0.94");
    return 0;
}