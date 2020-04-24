#include <bits/stdc++.h>
using namespace std;

void string_to_point(string s, char &x, int &y)
{
    x = ' ';
    y = 0;
    int digit = 1;
    int size = s.size();

    for (int i = 0; i < size; i++)
    {
        if (s[i] >= 'A' &&
            s[i] <= 'L')
        {
            x = s[i];
        }
        else if (s[i] >= '1' &&
                 s[i] <= '9')
        {
            y += s[i] * digit;
            digit * 10;
        }
    }
    y -= 48;
}



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



class Game
{
    Player me;
    Player opp;
    array<array<Point, 12>, 12> board;

public:
    void init(string, vector<string>);
    string debug();
};


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



class Io
{
public:
    static Game read_turn();
    static void debug_game(Game);
};


Game Io::read_turn()
{
    Game game;

    string his_last_peg;
    cin >> his_last_peg;
    cin.ignore();

    int num_your_pegs;
    cin >> num_your_pegs;
    cin.ignore();
    vector<string> my_pegs;

    for (int i = 0; i < num_your_pegs; i++)
    {
        string your_peg;
        cin >> your_peg;
        cin.ignore();
        my_pegs.push_back(your_peg);
    }

    game.init(his_last_peg, my_pegs);

    /*
    int numYourSegments; // The number of segments you have on the board.
    cin >> numYourSegments;
    cin.ignore();
    for (int i = 0; i < numYourSegments; i++)
    {
        string yourSegPeg1; // The first end of one of your segments.
        string yourSegPeg2; // The second end of one of your segments.
        cin >> yourSegPeg1 >> yourSegPeg2;
        cin.ignore();
    }
    int numHisPegs; // The number of pegs your opponent has on the board.
    cin >> numHisPegs;
    cin.ignore();
    for (int i = 0; i < numHisPegs; i++)
    {
        string hisPeg; // One of his pegs.
        cin >> hisPeg;
        cin.ignore();
    }
    int numHisSegments; // The number of segments of your opponent.
    cin >> numHisSegments;
    cin.ignore();
    for (int i = 0; i < numHisSegments; i++)
    {
        string hisSegPeg1; // The first end of one of his segments.
        string hisSegPeg2; // The second end of one of his segments.
        cin >> hisSegPeg1 >> hisSegPeg2;
        cin.ignore();*/
    return game;
}

void Io::debug_game(Game game)
{
    cerr << "GAME STATE: [ " << endl
         << "\t" << game.debug() << endl
         << " ]" << endl;
}

Game game;

int main()
{
    while (true)
    {
        game = Io::read_turn();
        Io::debug_game(game);

        cout << "E5" << endl;
    }
}
