#include "Player.h"

void Player::set_last_peg(Point last_peg)
{
    this->last_peg = last_peg;
}

void Player::set_own_pegs(vector<Point> own_pegs)
{
    this->own_pegs = own_pegs;
}

string Player::debug()
{
    string output = "last_peg: " + this->last_peg.debug() +
                    "\nMy pegs: ";

    for (auto peg : this->own_pegs)
    {
        output += peg.debug();
    }
    return output;
}