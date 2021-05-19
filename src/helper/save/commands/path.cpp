#include "../save.h"
#include <string_tools.h>

struct passwd *pw = getpwuid(getuid());

const string homedir = pw->pw_dir;


void Save::SetPath(string new_path){
    remove_og_spaces(new_path);
    this->path = new_path;

    //get rid of the / at the end of the string if it exits
    if(this->path[this->path.size() - 1] == '/'){
        this->path = this->path.substr(0,this->path.size() - 1);
    }

    //resolve homedir
    if(this->path[0] == '~'){
        replaceAll(this->path, "~/", homedir);
    }
}