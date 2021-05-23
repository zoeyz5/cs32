// WordCount.cpp

#include "WordCount.h"

using namespace std;

// Default constructor
WordCount::WordCount() {}

// Simple hash function. Do not modify.
size_t WordCount::hash(std::string word) const {
	size_t accumulator = 0;
	for (size_t i = 0; i < word.size(); i++) {
		accumulator += word.at(i);
	}
	return accumulator % CAPACITY;
}

int WordCount::getTotalWords() const {
    size_t i,j;
    int count = 0;
    for(i = 0; i < CAPACITY; i++){
        for(j = 0; j<table[i].size(); j++){
            count += table[i][j].second;
        }
    }
    return count;
}

int WordCount::getNumUniqueWords() const {
    // STUB
    size_t i;
    int count = 0;
    for(i = 0; i<CAPACITY; i++){
        count += table[i].size();
    }
    return count;
}

int WordCount::getWordCount(std::string word) const {
	// STUB - your solution from Lab04 goes here
    word = makeValidWord(word);
    if(word == ""){
        return 0;
    }
    size_t i;
    size_t hashkey = hash(word);
    for(i = 0; i<table[hashkey].size(); i++){
        if(table[hashkey][i].first == word){
            return table[hashkey][i].second;
        }
    }
    return 0;
}
	
int WordCount::incrWordCount(std::string word) {
    word = makeValidWord(word);
    if(word == ""){
        return 0;
    }
    size_t i;
    size_t hashkey = hash(word);
    for(i = 0; i<table[hashkey].size(); i++){
        if(table[hashkey][i].first == word){
            table[hashkey][i].second ++;
            return table[hashkey][i].second;
        }
    }
    std::pair<std::string, size_t> entry;
    entry.first = word;
    entry.second = 1;
    table[hashkey].push_back(entry);
    return 1;
}

int WordCount::decrWordCount(std::string word) {
    word = makeValidWord(word);
    if(word == ""){
        return -1;
    }
    size_t i;
    size_t hashkey = hash(word);
    for(i = 0; i<table[hashkey].size(); i++){
        if(table[hashkey][i].first == word){
            if(table[hashkey][i].second>1){
                table[hashkey][i].second --;
                return table[hashkey][i].second;
            }
            else(table[hashkey].erase(table[hashkey].begin()+i));
            return 0;
        }
    }
    return -1;
}


bool WordCount::isWordChar(char c) {
	// STUB - your solution from Lab04 goes here
    if((c>= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')){
        return true;
    }
    return false;
}

std::string WordCount::makeValidWord(std::string word) {
	// STUB - your solution from Lab04 goes here
    size_t i;
    for(i = 0; i < word.size(); i++) {
        if(isWordChar(word.at(i))){
            if(word.at(i) >= 'A' && word.at(i)<= 'Z'){
                word.at(i) += 32;
            }
            continue;
        }
        if(i == 0 || i == word.size() - 1) {
            word.erase(i, 1);
            i --;
        }
        else {
            if(word.at(i) == '\'' || word.at(i) == '-')
                continue;
            word.erase(i, 1);
            i --;
        }
    }

    i = word.size() - 1;
    while(word.size() > 0 && !isWordChar(word.at(i))) {
        word.erase(i, 1);
        i = word.size() - 1;
    }
        return word;
}

void WordCount::dumpWordsSortedByWord(std::ostream &out) const {
    std::vector<std::pair<std::string,int> > vect;
    for(size_t i = 0; i < CAPACITY; i++){
        for(size_t j = 0; j < table[i].size(); j++){
            std::pair<std::string,int> entry = table[i][j];
            vect.push_back(entry);
        }
    }
    
    std::pair<std::string,int> temp;
    for(size_t i = 0; i <vect.size(); i++){
        for(size_t j = i+1; j<vect.size(); j++){
            if(vect[i].first<vect[j].first){
                temp = vect[i];
                vect[i] = vect[j];
                vect[j] = temp;
            }
        }
    }
    
    for(size_t i = 0; i <vect.size(); i++){
        out<< vect[i].first<<"," <<std::to_string(vect[i].second)<<endl;
    }
}

void WordCount::dumpWordsSortedByOccurence(std::ostream &out) const {
	// STUB
    std::vector<std::pair<std::string,int> > vect;
    for(size_t i = 0; i < CAPACITY; i++){
        for(size_t j = 0; j < table[i].size(); j++){
            std::pair<std::string,int> entry = table[i][j];
            vect.push_back(entry);
        }
    }
    
    std::pair<std::string,int> temp;
    for(size_t i = 0; i<vect.size(); i++){
        for(size_t j = i+1; j<vect.size(); j++)
        {
            if(vect[i].first>vect[j].first){
                temp = vect[i];
                vect[i] = vect[j];
                vect[j] = temp;
            }
        }
    }
    
    std::pair<std::string,int> temp2;
    int shiftIndex;
    for(size_t i = 1; i<vect.size(); i++){
        temp2 = vect[i];
        shiftIndex = i-1;
        
        while(shiftIndex>=0&&vect[shiftIndex].second>temp2.second){
            vect[shiftIndex+1] =  vect[shiftIndex];
            shiftIndex -= 1;
        }
        vect[shiftIndex+1] = temp2;
    }
    for(size_t i = 0; i <vect.size(); i++){
        out<< vect[i].first<<"," <<std::to_string(vect[i].second)<<endl;
    }
    
}

void WordCount::addAllWords(std::string text) {
	// STUB
    string aWord="";
    for(size_t i = 0; i < text.length(); i++){
        if((text[i]==' ')||(text[i]=='\n')||(text[i]=='\t'))
        {
            incrWordCount(aWord);
            aWord = "";
        }
        else{
            aWord = aWord + text[i];
        }
    }
    incrWordCount(aWord);
}
