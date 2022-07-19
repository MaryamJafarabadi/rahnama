#include <iostream>
#include <vector>
using namespace std;

class Mohre {
public:
    Mohre(string color_);
    string get_color();
private:
    string color;
};
class Round {
public:
    Round(int n_mohre_);
    void start_round();
    void add_this_mohre(Mohre* this_mohre);
    vector<Mohre*> get_mohreha();
    void check_similarity();
    vector<string> get_hint();
private:
    int n_mohre;
    vector<Mohre*>mohreha;
    vector<string>colors;
    vector<string>hint;
    
};
vector<string> Round::get_hint()
{
    return hint;
}
class Game {
public:
    Game(bool win_,bool end_);
    void start();
    void check_end(Round* this_round);
    //void check_similarity(vector<Mohre*>mohreha);
private:
    bool end;
    int number_of_passes_round;
    int n_round;
    vector<string>initial_colors;
    bool win;
};
Game::Game(bool win_,bool end_) {
    win = win_;
    end = end_;
}
Round::Round(int n_mohre_)
{
    n_mohre = n_mohre_;
}
void Round::start_round()
{
    for (int i = 0; i < n_mohre; i++)
    {
        string color;
        cin >> color;
        Mohre* this_mohre = new Mohre(color);
        add_this_mohre(this_mohre);
    }
}
void Round::check_similarity()
{
    for (int i = 0; i < n_mohre; i++)
    {
        if (mohreha[i]->get_color() == colors[i])
        {
            hint.push_back("black");
        }
        else
        {
            int flag = 0;
            for (int j = 0; j < n_mohre; j++)
            {
                if (mohreha[i]->get_color() == colors[j])
                {
                    hint.push_back("white");
                    flag = 1;
                }    
            }
            if (!flag)
                hint.push_back("empty");
        }
    }
}
void Round::add_this_mohre(Mohre* this_mohre)
{
    mohreha.push_back(this_mohre);
}
vector<Mohre*> Round::get_mohreha()
{
    return mohreha;
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
    while (number_of_passes_round< n_round && !end)
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
Mohre::Mohre(string color_)
{
    color = color_;
}
string Mohre::get_color()
{
    return color;
}
int main()
{
    Game* game = new Game(false,false); 
    game->start();
}

