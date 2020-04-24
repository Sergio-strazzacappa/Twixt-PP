#ifndef _GAME_
#define _GAME_

#include <array>
#include <string>
#include "Player.h"
#include "Point.h"
#include "../Services/Functions.h"

using std::array;
using std::string;

class Game
{
    Player me;
    Player opp;
    array<array<Point, 12>, 12> board;

public:
    void init(string, vector<string>);
    string debug();
};

#endif