#include <string>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include "date.h"

using std::cout;
using std::endl;

template <class T>
T string_cast(std::string input)
{
    std::istringstream convertThis(input);
    T convertedValue;
    convertThis >> convertedValue;
    if (convertThis.fail())
    {
        throw std::invalid_argument("Could not be converted conversion has been flagged");
    }
    else
    {
        return convertedValue;
    }
}

int main()
{
    try
    {
        int i = string_cast<int>("123");
        double d = string_cast<double>("12.3");
        Date dt = string_cast<Date>("2020-10-20");
        cout << i << "  " << d << "  " << dt << endl;
    }
    catch (std::invalid_argument &e)
    {
        cout << "Error: " << e.what() << endl;
    }
    
    try
    {
        int i = string_cast<int>("aaa123");
        //Date dt = string_cast<Date>("2020-10-37");
        cout << i << endl;
    }
    catch (std::invalid_argument &e)
    {
        cout << "Error: " << e.what() << endl;
    }
    return 0;
}