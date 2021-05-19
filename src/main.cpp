#include <stdio.h>
#include <fstream>
#include <vector>
#include <string>
#include <typedefs.h>
#include <iostream>

//includes
#include "helper/args.h"
#include "helper/save/save.h"
//

int main(int argc, cstring _argv[]){
    //error message handling
    bool error_encountered = false;
    string error_message;
    //

    //settings
    Save save;
    //

    //Convert argv into a vector
    vector<string> argv;
    for(uint8 i =1; i < argc; i++){
        argv.push_back((string)_argv[i]);
    }
    argc--;

    int chosen_command = ProcessCommands(argc, argv);

    if(chosen_command <= 0){
        chosen_command *= -1;
        argc--;
        
        switch (chosen_command)
        {
            case HELP:
                save.Help();
                break;
            case PATH:
                if(argc != 1){
                    error_encountered = true;
                    error_message = "No path specified";
                    break;
                }
                save.SetPath(argv[argc]);
                break;
            case DEFAULT:
                save.path = DEFAULT_PATH;
                break;
            case DELETE:
            case REMOVE:
                if(argc != 1){
                    error_encountered = true;
                    error_message = "No command to delete specified";
                    break;
                }
                save.Remove(argv[argc]);
                break;
            case LIST:
                save.List();
                break;
            case SEARCH:
                if(argc != 1){
                    error_encountered = true;
                    error_message = "No command to take note specified";
                    break;
                }
                save.Search(argv[argc]);
                break;
            case CLEAR:
                save.Clear();
            break;
            default:
                error_encountered = true;
                error_message = "Detected -- but no valid arg given\nSee --help for options.";
            break;
        }
        if(error_encountered){
            printf("ERROR: %s\n", error_message.c_str());
            return -1;
        }
        save.Export();
        return 0;
    }


    Entry new_entry;

    if(argc == 1){
        new_entry.command = argv[1];
    }else{
        printf("What is the command: ");
        std::getline(std::cin, new_entry.command);
    }


    printf("What should the short discription be: ");
    std::getline(std::cin, new_entry.short_disc);

    printf("What should the detailed discription be: ");
    std::getline(std::cin, new_entry.disc);
    
    save.entries.push_back(new_entry);


    printf("Are you sure you want to save? [Y/n]\n");
    string tmp = " ";
    std::getline(std::cin, tmp);
    if(tmp[0] == 'Y'){
        tmp = "y";
    }
    if(tmp[0] == 'N'){
        tmp = "n";
    }

    if(tmp == "y"){
        save.Export();
    }

    return 0;
}