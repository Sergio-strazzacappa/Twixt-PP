#ifndef _GENERATE_OUTPUT_
#define _GENERATE_OUTPUT_

#include <bits/stdc++.h>
using namespace std;

const int FILES_QUANTITY = 10;
const vector<string> INPUT_FILES = {
    "../Services/Functions.cpp",
    "../Models/Point.h",
    "../Models/Point.cpp",
    "../Models/Player.h",
    "../Models/Player.cpp",
    "../Models/Game.h",
    "../Models/Game.cpp",
    "../Services/Io.h",
    "../Services/Io.cpp",
    "../Program.cpp"};
const string OUTPUT_FILE = "Codingame.cpp";
const vector<string> DIRECTIVES = {
    "#include <bits/stdc++.h>",
    "\n",
    "using namespace std;",
    "\n"};

int main();
void clear_file();
void copy_directives();
void copy_file(ifstream &);
bool exclude_line(string line);

#endif