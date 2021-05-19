#include "../save.h"

//
void Save::Remove(string Entry){
    for(uint128 i = 0; i < entries.size(); i++){
        if(entries[i].command == Entry){
            entries.erase(entries.begin() + i);
            return;
        }
    }
    printf("ERROR: Entry not found!!!\n");
}