#include "args.h"

const string args[8] = {
    "--help",
    "--path",
    "--default",
    "--remove",
    "--delete",
    "--list",
    "--search",
    "--clear"
};


int ProcessCommands(int argc, vector<string> argv){
    if(argv.empty()){
        return 100;
    }
    if(argv[0].empty()){
        return 100;
    }
    
    if(argv[0][0] == '-'){
        for(uint i = 0; i < 8;i++){
            if(args[i] == argv[0]){
                return i * -1;
            }
        }
    }else{
        return 100; //command name not --
    }
    return -100; //-- not found
}
