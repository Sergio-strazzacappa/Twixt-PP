#ifndef _PLAYER_
#define _PLAYER_

#include <vector>
#include <array>
#include "Point.h"

using std::array;
using std::vector;

class Player
{
    Point last_peg;
    vector<Point> own_pegs;
    array<vector<Point>, 2> own_segments;
    vector<Point> enemy_pegs;
    array<vector<Point>, 2> enemy_segments;

public:
    void set_last_peg(Point);
    void set_own_pegs(vector<Point>);
    string debug();
};

#endif