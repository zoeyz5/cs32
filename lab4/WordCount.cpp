// WordCount.cpp

#include "WordCount.h"
#include <vector>

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
    // STUB.
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
    // STUB
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
    // STUB
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
    // STUB
    if((c>= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')){
        return true;
    }
    return false;
}


std::string WordCount::makeValidWord(std::string word) {
    // STUB
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
