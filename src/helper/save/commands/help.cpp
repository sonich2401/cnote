#include "../save.h"


const string message = 
PROG_NAME " v" VER " | Build Date: " DATE "\n"
"\nDisciption:\n"
    "\tThis program is to take quick note of any command that you want to remember\n"
    "\tIt is particularly useful when you need to remember commands that are used\n"
    "\tto fix things on your computer. General usage is 'cnote' and it will prompt\n"
    "\tyou with fields to fill out for the command you want to take note of.\n\n"

"Useage:\n"
    "\tcnote --[option]\n"
    "\tcnote <Command Name>\n"
    "\tcnote\n"
"Options\n"
    "\t--help: this message\n"
    "\t--list: List all of the entries in the db. `cnote --list`\n"
    "\t--search: Search the db for a simmilar entry. `cnote --search myCommand`\n"
    "\t--remove / --delete: Delete a item in the db. `cnote --delete myCommand`\n"
    "\t--default: Set the settings to default. `cnote --default`\n"
    "\t--path: Set the path to save the db to. `cnote --path /home/user/myPath`\n"
    "\t--clear: Remove all of the entries in the db. `cnote --clear`\n"
;

void Save::Help(){
    printf("%s", message.c_str());
}