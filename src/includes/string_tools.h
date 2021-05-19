#pragma once
#include <vector>
#include <string>

#ifndef STRING_TOOLS_H
#define STRING_TOOLS_H
//using namespace std;
using std::vector;
using std::string;

void replaceAll(std::string& str, const std::string& from, const std::string& to);

vector<string> split(string s, const char c);

void remove_og_spaces(std::string& str);

std::string one_space(std::string str);

int new_rfind(std::string str, char chr, int offset);

std::vector<std::string> get_args(std::string str);

#endif