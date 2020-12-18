#include <string>
#include <vector>
#include "word.h"
#include <iostream>
#include <ostream>

using std::vector;
using std::string;
using std::cout;
using std::endl;

Word::Word(const string& w, const vector<string>& t) {
	word = w;
	trigram = t;
}

string Word::get_word() const {
	return word;
}

unsigned int Word::get_matches(const vector<string>& t) const {
	
	int matches = 0;
	int i = 0;
	int j = 0;
	
	while(i < t.size() && j < trigram.size()){
		auto compared = t.at(i).compare(trigram.at(j));
		if(compared > 0){
			j++;
		}
		else if(compared < 0){
			i++;
		}
		else{
			matches++;
			i++;
			j++;
		}
	}
	return matches;
}
