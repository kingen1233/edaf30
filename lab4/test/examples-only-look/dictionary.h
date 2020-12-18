#ifndef DICTIONARY_H
#define DICTIONARY_H

#include <string>
#include <vector>
#include "word.h"

class Dictionary {
public:
	Dictionary();
	bool contains(const std::string& word) const;
	std::vector<std::string> get_suggestions(const std::string& word) const;
	
	std::vector<std::string> findTrigramms(const std::string& word) const;
	void add_trigram_suggestions(std::vector<std::string>& suggestions, const std::string& word) const;
	void rank_suggestions(std::vector<std::string>& suggestions, const std::string& word) const; 
	void trim_suggestions(std::vector<std::string>& suggestions) const ;
	
	
private:
	
	constexpr static int wordsSize = 25;
	std::vector<Word> words[wordsSize];
	
};

#endif
