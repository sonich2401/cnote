#include "../save.h"

void Save::List(){
    for(Entry ent : this->entries){
        ent.print();
    }
}