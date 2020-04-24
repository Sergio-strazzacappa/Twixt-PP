#include "Io.h"
#include "../Models/Game.h"

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