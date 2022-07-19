
#include <iostream>
#include <vector>
using namespace std; 
#include <mohre.hpp>
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