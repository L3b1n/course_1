#include <iostream>
#include <fstream>
#include "Tqueue.cpp"
#include "Tprk.cpp"

using namespace std;

int main()
{
    Tqueue a;
    std::ifstream input("Input.txt", ios::in);
    input >> a;
    Tprk num(a.tail, a);
    cout << a << endl;
    num.getMatr();
    num.getSMatr();
    std::ofstream output("Output.txt", ios::out);
    output << "Numbers from file:\n" << a << num << endl;
    input.close();
    output.close();
    cout << num;
}
