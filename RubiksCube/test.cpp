#include <iostream>
#include <vector>
#include <time.h>
#include "color.cpp"
#include "model.cpp"

using namespace std;

int main()
{
    Model a;
    string moves;
    srand(time(NULL));
    bool output_bool[10];
    string str[10], output[10];
    std::vector<string> turn = {" r", " r'", " r2", " l", " l'", " l2", " u", " u'", " u2", " d", " d'", " d2", " f", " f'", " f2", " b", " b'", " b2"};
    for(int j = 0; j < 10; j++)
    {
        for(int i = 0; i < 20; i++)
        {
            str[j].append(turn[rand() % 18]);
        }
        output[j] = str[j];
        Search(a, str[j]);
        Intersection_fast(a, moves);
        F2l(a, moves);
        OLL(a, moves);
        PLL(a, moves);
        if(a.is_full()){ output_bool[j] = true;}
        else output_bool[j] = false;
        moves = "";
    }
    std::ofstream out("Output.txt", ios::app);
    out << "\n\n";
    for(int i = 0; i < 10; i++)
    {
        if(!output_bool[i])
        {
            out << i << "_____________________________________________________" << endl;
            out << output[i] << endl;
            out << "______________________________________________________" << endl;
        }
    }
    out.close();
}