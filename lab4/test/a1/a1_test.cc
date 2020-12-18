#include <iostream>
#include <fstream>
#include <string>
#include "a1.h"
using std::string;

void test_equals(string x, string y)
{
    if(x != y) {
        std::cout << "Wrong result: " << x << " != " << y << std::endl;
		std::cout << " " << std::endl;
    }
	else{
		std::cout << "Test Passed!: " << x << std::endl;
		std::cout << " " << std::endl;
	};
}

int main() { 
	
	std::ifstream i2("test2.html");
	std::ifstream i3("test3.html");
	std::ifstream i4("test4.html");
	
	TagRemover test2(i2);
	TagRemover test3(i3);
	TagRemover test4(i4);
    test_equals(test2.print(std::cout), "Special chars: <> &");
	test_equals(test3.print(std::cout), "A line with a starting tag ");
	test_equals(test4.print(std::cout), "And this  line has two tags ");
	std::cout << "test done." << std::endl;
}