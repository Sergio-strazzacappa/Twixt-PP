#include "Game.h"

void Game::init(string his_last_peg, vector<string> my_pegs)
{
    char x = ' ';
    int y = 0;
    string_to_point(his_last_peg, x, y);
    this->opp.set_last_peg(Point(x, y, '0'));

    vector<Point> my_point_pegs;

    for (auto s : my_pegs)
    {
        string_to_point(s, x, y);
        my_point_pegs.push_back(Point(x, y, '1'));
    }
    this->me.set_own_pegs(my_point_pegs);
}

string Game::debug()
{
    return "Opponent info: " + this->opp.debug();
}