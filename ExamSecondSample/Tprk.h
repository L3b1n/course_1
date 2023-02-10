#include <iostream>

using namespace std;

class Tprk 
{
	int n;
	int** Matr;
	int** SMatr;
	Tqueue a;
public:
	Tprk(int _n, Tqueue _arr);
	~Tprk();
	void Sort(int num, int &num_min, int &num_max);
	int Kaprek(int num, int &num_min, int &num_max);
	bool checkNum(const int num);
	void getMatr();
	void getSMatr();
	friend ostream& operator << (ostream& out, const Tprk& m);

    friend ofstream& operator << (ofstream& fo, const Tprk& m);
};