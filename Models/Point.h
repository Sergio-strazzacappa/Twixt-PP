#ifndef _POINT_
#define _POINT_

#include <string>

using std::string;
using std::to_string;

class Point
{
    char x;
    int y;
    char content; // - (empty) 1 (own) 0 (enemy) X (corner)

public:
    Point();
    Point(char, int, char);
    string debug();
};

#endif