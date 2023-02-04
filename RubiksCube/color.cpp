#include "color.h"
#include <string>

Color::Color(){ index = new int[9]; color = new string[9];}

Color::Color(string str)
{
    index = new int[9];
    color = new string[9];
    for(int i = 0, j = 1; i < 9; i++, j++)
    { 
        color[i] = str; 
        index[i] = j;
    }
}

Color::~Color(){}

void Color::Change_index(int ind, int data)
{
    index[ind] = data;
}

void Color::Change_color(int ind, string data)
{
    color[ind] = data;
}

void Color::Swap_index(int ind_one, int ind_two)
{
    swap(index[ind_one], index[ind_two]);
}

void Color::Change_index()
{
    int a[9] = {index[6], index[3], index[0], index[7], index[4], index[1], index[8], index[5], index[2]};
    string b[9] = {color[6], color[3], color[0], color[7], color[4], color[1], color[8], color[5], color[2]};
    for(int i = 0; i < 9; i++){ index[i] = a[i]; color[i] = b[i];}
}

void Color::Change_index_stroke()
{
    int a[9] = {index[2], index[5], index[8], index[1], index[4], index[7], index[0], index[3], index[6]};
    string b[9] = {color[2], color[5], color[8], color[1], color[4], color[7], color[0], color[3], color[6]};
    for(int i = 0; i < 9; i++){ index[i] = a[i]; color[i] = b[i];}
}