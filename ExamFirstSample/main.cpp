#pragma warning(disable 4996)
#include <iostream>
#include <fstream>
#include "Stud.cpp"

using namespace std;

int main()
{
    Stud a;
    a.ball = 10;
    std::ifstream input("Input.txt");
    input >> a;
    a.GetSorted();
    cout << a << endl;
    std::ofstream output("Output.txt");
    output << "Количество поступивших равно " << a.size() << "\n" << a << endl;
    input.close();
    output.close();
}
