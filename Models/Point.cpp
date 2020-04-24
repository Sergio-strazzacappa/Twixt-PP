#include "Point.h"

Point::Point()
{
    this->x = 0;
    this->y = 0;
    this->content = '-';
}

Point::Point(char x, int y, char content)
{
    this->x = x;
    this->y = y;
    this->content = content;
}

string Point::debug()
{
    return "(" + string(1, this->x) + ", " + to_string(this->y) + ")";
}