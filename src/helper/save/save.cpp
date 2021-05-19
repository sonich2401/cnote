#include "save.h"




extern const string homedir;

extern const string DEFAULT_PATH;

void Entry::print(bool type){
    printf("%s:\n",this->command.c_str());
    printf("\t%s\n",this->short_disc.c_str());
    
    if(type == true){
        printf("\t%s\n",this->disc.c_str());
    }
}






#include <fstream>

bool DirExists(string path){
    path ="ls " + path +" >erase_output19921124.tmp 2>erase_output19921124.tmp";
    int ret = system(path.c_str());
    system("rm erase_output19921124.tmp");
    return ret == 0;
}




void Save::Export(){
    string command = "mkdir " + homedir + "/.cnote";

    if(!DirExists(homedir +"/.cnote")){
        system(command.c_str());
    }
    
    //export path
    std::fstream file(homedir + "/.cnote/path", std::ios::out);
    command = "cp "+homedir+"/.cnote/path " + homedir+"/.cnote/path.old >";
    system(command.c_str());
    file << this->path;
    file.close();
    //

    //export db to path
    if(!DirExists(this->path)){
        command = "mkdir " + this->path;
        system(command.c_str());
    }
    command = "cp " + this->path + "/cnote.db " + this->path + "/cnote.db.old";
    system(command.c_str()); //make backup before writing to file
    //clear file
    file.open(this->path + "/cnote.db", std::ios::out);
    file << "";
    file.close();
    //write to file
    file.open(this->path + "/cnote.db", std::ios::out | std::ios::app);
    

    for(Entry ent : this->entries){
        file << ent.command << "\n";
        file << ent.short_disc << "\n";
        file << ent.disc << "\n";
    }
    file.close();

    
    
}

vector<string> load_lines(string fp){
    int prg = 0;
    std::vector < string > lines;
    std::fstream file(fp, std::ios::in);

    if (file.fail()) { //file failed to open
        return lines;
    }

    string tmp;
    while (!file.eof()) {
        std::getline(file, tmp);
        //'�'
        //replaceAll(tmp, "�", "");
        lines.push_back(tmp);
    }
    file.close();
    return lines;
}


Save::Save(){

    vector<string> lines = load_lines("/home/rendev/.cnote/path");

    //Start of file decoding
    if(lines.empty()){ //if empty then set to default
        lines.push_back(DEFAULT_PATH);
    }
    this->path = lines[0];

    lines = load_lines(this->path + "/cnote.db");

    if(!lines.empty()){//if empty then dont decode    
        for(uint128 i = 0; i + 3 < lines.size(); i+=3){
            entries.push_back({lines[i], lines[i+1], lines[i+2]});
        }
    }
}
