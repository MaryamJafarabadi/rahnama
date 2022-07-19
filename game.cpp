#include <iostream>
#include <vector>
using namespace std;
#include <game.hpp>
Game::Game(bool win_, bool end_) {
    win = win_;
    end = end_;
}
void Game::start()
{
    int n_mohre;
    cin >> n_round >> n_mohre;
    for (int i = 0; i < n_mohre; i++)
    {
        string this_color;
        cin >> this_color;
        initial_colors.push_back(this_color);
    }
    end = false;
    number_of_passes_round = 0;
    while (number_of_passes_round < n_round && !end)
    {
        Round* this_round = new Round(n_mohre);
        this_round->start_round();

        n_round++;
        //this_round->get_hint();
        check_end(this_round);

    }
    if (win)
    {
        cout << "you win!";
    }
    else
    {
        cout << "you loose!";
    }

}
void Game::check_end(Round* this_round)
{
    int flag = 0;
    for (int i = 0; i < initial_colors.size(); i++)
    {
        cout << this_round->get_hint()[i] << endl;
        if (initial_colors[i] != this_round->get_hint()[i])
        {
            flag = 1;
            continue;
        }
    }
    if (number_of_passes_round == n_round && flag)
    {
        end = 1;
        win = 0;
    }
    else if (!flag)
    {
        win = 1;
        end = 1;
    }
}