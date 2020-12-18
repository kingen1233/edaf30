#include <string>
#include <vector>
#include <set>
#include <iostream>
#include <fstream>

using namespace std;

string findTrigramms(string);


int main(){
	
	ifstream inFile("dict-words.txt");
	ofstream outFile;
	outFile.open("words.txt");
	string currentLine;
	while(getline(inFile, currentLine)){
		string outLine = findTrigramms(currentLine);
		outFile << outLine << endl;
	}
	
	inFile.close();	
	outFile.close();
	return 0;
	
}

string findTrigramms(string line){
		
	string::size_type actualLineLength = line.length()-1;
	
	if(actualLineLength  < 2){
		return line;		
	}
	
	int charAt{0};
	string::size_type index{0};
	set<string> trigrams;
	
	while(index < (actualLineLength - 1)){		
				
		trigrams.insert(line.substr(charAt, 3));
		charAt++;
		index++;
		
	}
	line.append(" " + to_string(charAt));
	
	for(const string& x : trigrams){
		line.append(" " + x);
	}

	return line;
	
}