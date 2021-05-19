#include "../save.h"
#include <string_tools.h>

#define THRESHOLD 80


int SameLetters(string word, string filter){
    int total = 0;
    for(uint128 i = 0; i < filter.size() && i < word.size(); i++){
        total += (filter[i] == word[i]);
    }
    return total;
}

/*
void Save::Search(string filter){
    for(Entry ent : this->entries){
        vector<string> spl = split(ent.command, '-');
        for(string word : spl){
            float total_same = SameLetters(word, filter);
            if((total_same/word.size()) >= (THRESHOLD/100)){
                ent.print(1);
            }
        }
    }
}*/

void Save::Search(string filter){
    for(Entry ent : this->entries){
        if(ent.command == filter){
            ent.print();
            return;
        }
    }
    printf("That command was not found!\nTry --list to see all of the entries.\n");
}