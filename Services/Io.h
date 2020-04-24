#ifndef _IO_
#define _Io_

#include <iostream>
#include <string>
#include <vector>
#include "../Models/Game.h"

using std::cerr;
using std::cin;
using std::endl;
using std::string;
using std::vector;

class Io
{
public:
    static Game read_turn();
    static void debug_game(Game);
};

#endif