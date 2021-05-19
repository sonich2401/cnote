#include <typedefs.h>


int ProcessCommands(int argc, vector<string> argv);

enum ARGS {
    HELP,
    PATH,
    DEFAULT,
    REMOVE,
    DELETE,
    LIST,
    SEARCH,
    CLEAR,
};