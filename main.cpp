
#include <iostream>
#include <vector>
#include <game.hpp>
using namespace std;
int main()
{
    Game* game = new Game(false, false);
    game->start();
}

