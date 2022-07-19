#include <iostream>
#include <vector>
using namespace std;
#include <round.hpp>
class Game {
public:
    Game(bool win_, bool end_);
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