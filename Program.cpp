#include "Services/Io.h"
#include "Models/Game.h"

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