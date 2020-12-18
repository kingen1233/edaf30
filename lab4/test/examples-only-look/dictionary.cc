#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <algorithm>
#include <unordered_set>
#include "dictionary.h"

using std::string;
using std::vector;
using std::ifstream;
using std::cout;
using std::endl;
using std::pair;

Dictionary::Dictionary() {
	for(int i = 0; i <= wordsSize; i++){
		words[i].reserve(4000);
	}
	ifstream inFile("words.txt");
	
	string currentLine;
	while(getline(inFile, currentLine)){
		
		string word = "";
		string firstWord = "";
		int firstWordLength = 0;
		vector<string> trigrams;
		bool getFirst = true;
		for (auto x : currentLine) {
			
			if (x == ' '){
				if(getFirst){
					getFirst = false;
					firstWord = word;
					firstWordLength = word.length();
					word = "";					
				}
				else{
					if(word.length() == 3){
						trigrams.push_back(word);
					}
					else{
						if(firstWordLength > wordsSize){
							break;
						}
						trigrams.reserve(stoi(word));
					}
					word = "";
				}
			}
			else {
				word = word + x;
			}
		}
		
		if(getFirst){
			firstWord = word;
			firstWordLength = word.length();
		}
		if(firstWordLength <= wordsSize){
			trigrams.push_back(word);	
			
			words[firstWordLength].emplace_back(firstWord, trigrams);
		}
	}	
}

bool Dictionary::contains(const string& word) const {

	for(const auto& s : words[word.length()]){
		if(s.get_word() == word){
			return true;
		}
	}
    return false;
}

vector<string> Dictionary::get_suggestions(const string& word) const {
	vector<string> suggestions;
	add_trigram_suggestions(suggestions, word);
	rank_suggestions(suggestions, word);
	trim_suggestions(suggestions);
	return suggestions;
}

void Dictionary::add_trigram_suggestions(vector<string>& suggestions, const string& word) const{
	int wordLength = word.length();
	vector<string> wordTris = findTrigramms(word);
	for(int i = wordLength-1; i <= wordLength+1; i++){
		for(const auto& x : words[i]){
			
			if(word.length() < 3){
				suggestions.push_back(x.get_word());
			}			
			else if(x.get_matches(wordTris) >= (word.length() - 2)/2 ){
				suggestions.push_back(x.get_word());
			}			
		}
	}
}

void Dictionary::rank_suggestions(vector<string>& suggestions, const string& word) const{
	const int length1 = word.length();
	vector<pair<int,string>> rankedSuggestions;
	for(string s : suggestions){
		
		int d[26][26];		
		d[0][0] = 0;
		const int length2 = s.length();
		
		for(int i = 1; i <= length1; i++) 
		d[i][0] = i;
		
		for(int i = 1; i <= length2; i++) 
		d[0][i] = i;
		
		for(int i = 1; i <= length1; i++){		
			for(int j = 1; j <= length2; j++){
			int val1 = (word[i-1] == s[j-1] ? d[i-1][j-1] : d[i-1][j-1] +1);
			int val2 = d[i-1][j] + 1;
			int val3 = d[i][j-1] + 1;
				d[i][j] = std::min({val1, val2, val3});					
			}
		}		
		int shortestDistance = d[length1][length2];
		rankedSuggestions.emplace_back(shortestDistance, s));
	}

	std::sort (rankedSuggestions.begin(), rankedSuggestions.end());
	suggestions.clear();
	for(auto s : rankedSuggestions){
		suggestions.push_back(s.second);
	}
}

void Dictionary::trim_suggestions(vector<string>& suggestions)const {	
	suggestions.resize(5);
}

vector<string> Dictionary::findTrigramms(const string& word) const{
	
	
	string::size_type actualLineLength = word.length()-1; 

	vector<string> trigrams;	
	int charAt{0};
	string::size_type index{0};
	
	while(index < (actualLineLength - 1)){		
				
		trigrams.push_back(word.substr(charAt, 3));
		charAt++;
		index++;
		
	}
	std::sort (trigrams.begin(), trigrams.end());
	return trigrams;
	
}