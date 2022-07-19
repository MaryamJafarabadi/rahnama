#include <iostream>
#include <vector>
#include <round.hpp>
using namespace std;
vector<string> Round::get_hint()
{
    return hint;
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