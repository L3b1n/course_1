#include <iostream>
#include "color.cpp"
#include "model.cpp"

using namespace std;

int main()
{
    Model a;
    string str, moves;
    cout << "Enter moves: ";
    getline(cin, str);
    Search(a, str);
    string color[8] = {"white", "blue", "yellow", "green", "blue", "yellow", "green", "white"};
    cout << a << endl;
    cout << "-------------" << endl;
    Intersection_fast(a, moves);
    // Corners_slow(a, moves);
    // Middles_slow(a, moves);
    // Down_intersection_slow(a, moves);
    F2l(a, moves);
    OLL(a, moves);
    PLL(a, moves);
    cout << a << endl;
    cout << moves << endl;
    //for(int i = 0; i < 4; i++){  cout << a.Combination(color) << endl;} // r' d' r d' f d f' l d l'
    // r' u2 f' u2 l' u' l' d' r b d' // u2 l u r2 f u u b2 l l2 r2 f' d u2 u f' f r2 d2 f2
}