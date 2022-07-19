#include <iostream>
#include <vector>
using namespace std;
#include <mohre.hpp>
Mohre::Mohre(string color_)
{
    color = color_;
}
string Mohre::get_color()
{
    return color;
}