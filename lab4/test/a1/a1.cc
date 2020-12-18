#include "a1.h"
using std::cin;
using std::cout;
using std::endl;


TagRemover::TagRemover(std::istream& in) {
    std::noskipws(in);
    std::istream_iterator <char> itr(in);
    std::istream_iterator <char> itre{};
    std::string s(itr, itre);

    str = deTag(s);
}

std::string& TagRemover::deTag(std::string& s){

    while(s.find("<") != std::string::npos){
        auto i1 = s.find("<");
        auto i2 = s.find(">");
        if(i2 == std::string::npos){
            break;
        }
        auto amntReplace = (i2-i1)+1;
        s.erase(i1, amntReplace);
    }
    while(s.find("&") != std::string::npos){
        auto i1 = s.find("&");
        auto i2 = s.find(";");
        if(i2 == std::string::npos){
            break;
        }
        auto amntReplace = (i2-i1)+1;
        std::string sub = s.substr(i1,amntReplace);
        s.erase(i1, amntReplace);        

        // Kunde använt en map här
        if (sub == "&lt;") {
            s.insert(i1, "<");
        } 
         else if (sub == "&gt;") {
            s.insert(i1, ">");
        } 
         else if (sub == "&nbsp;") {
            s.insert(i1, " ");
        } 
         else if (sub == "&amp;") {
            s.insert(i1, "&");
        } 
    }

    return s;
}

std::string TagRemover::print(std::ostream& out) const {
    out << str << endl;
    return str;
}