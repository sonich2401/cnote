#include <typedefs.h>
#include <unistd.h>
#include <sys/types.h>
#include <pwd.h>

#ifndef HOME_DIR
#define HOME_DIR
extern struct passwd *pw;

extern const string homedir;
#endif

#ifdef HOME_DIR
extern const string DEFAULT_PATH;
#endif

struct Entry{
    string command;
    string short_disc;
    string disc;

    void print(bool type = 0);
};


struct Save{
    string path;
    vector<Entry> entries;

    Save();


    void Default();
    void Help();
    void List();
    void SetPath(string new_path);
    void Remove(string entry_name);
    void Search(string entry_name);
    void Clear();

    void Export();
};
