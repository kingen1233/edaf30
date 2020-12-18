#ifndef A1_H
#define A1_H

#include <string>
#include <iostream>
#include <iterator>

class TagRemover {
public:
	TagRemover(std::istream& in);
	TagRemover();
	std::string print(std::ostream& out) const;
	std::string& deTag(std::string& s);
	
private:
    std::string str;
	const std::string inLine;
	
};

#endif
