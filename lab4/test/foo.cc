#include <string>
#include <iostream>
#include <iterator>
#include <iomanip>

int main()
{
    std::noskipws(std::cin);
    std::istream_iterator<char> a(std::cin);
    std::istream_iterator<char> b{};
    std::string s(a, b);
    std::cout << s << std::endl;
}