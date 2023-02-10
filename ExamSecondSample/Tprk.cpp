#include "Tprk.h"
#include <cmath>

using namespace std;

int compare(const void* x1, const void* x2)
{
	return (*(int*)x1 - *(int*)x2);
}

Tprk::Tprk(int _n, Tqueue _arr) 
{
	n = _n;
	Matr = new int* [n];
	for (int i = 0; i < n; i++) 
	{
		Matr[i] = new int[30];
	}
	for (int i = 0; i < n; i++) 
	{
		for (int j = 0; j < 30; j++) 
		{
			Matr[i][j] = 0;
		}
	}
	SMatr = new int* [n];
	for (int i = 0; i < n; i++) 
	{
		SMatr[i] = new int[30];
	}
	for (int i = 0; i < n; i++) 
	{
		for (int j = 0; j < 30; j++) 
		{
			SMatr[i][j] = 0;
		}
	}
	a = _arr;
}

Tprk::~Tprk() 
{
	for (int i = 0; i < n; i++)
	{
		delete[] Matr[i];
	}
	delete[] Matr;
	for (int i = 0; i < n; i++) 
	{
		delete[] SMatr[i];
	}
	delete[] SMatr;
}

bool Tprk::checkNum(const int num)
{
	return (num / 10000 == 0 && num / 1000 != 0) && !((num / 1000 == num / 100 % 10) 
			&& (num / 100 % 10 == num / 10 % 10) && (num / 10 % 10 == num % 10));
}

void Tprk::Sort(int num, int &num_min, int &num_max)
{
	int digit;
	int digits[4];
	for (int i = 0; i < 4; i++) 
	{
		digit = num / (int(pow(10, i))) % 10;
		digits[i] = digit;
	}
	for (int i = 0; i < 3; i++) 
	{
		for (int j = 0; j < 3 - i; j++) 
		{
			if (digits[j] < digits[j + 1]) 
				swap(digits[j], digits[j + 1]);
		}
	}
	num_max = digits[0] * 1000 + digits[1] * 100 + digits[2] * 10 + digits[3];
	num_min = digits[3] * 1000 + digits[2] * 100 + digits[1] * 10 + digits[0];
}

int Tprk::Kaprek(int num, int &num_min, int &num_max)
{
	Sort(num, num_min, num_max);
	num = num_max - num_min;
	return num;
}

void Tprk::getMatr()
{
	int num = 0, num_min = 0, num_max = 0, j = 0, m = 0;
	for(int i = 0; i < n; i++)
	{
		if(checkNum(a[i]))
		{
			num = a[i];
			while(num != 6174)
			{
				num = Kaprek(num, num_min, num_max);
				Matr[i][++j] = num_max;
				Matr[i][++j] = num_min;
				m++;
			}
			Matr[i][++j] = num;
			Matr[i][0] = m;
			j = 0;
			m = 0;
		}
	}
}

void Tprk::getSMatr()
{
	for(int i = 0; i <= n - 1; i++)
	{
		for(int j = 0; j < 16; j++)
		{
			SMatr[i][j] = Matr[i][j];
		}
	}
	for(int i = 0; i <= n - 1; i++)
    {
		for(int j = 0; j < n - i - 1; j++)
		{
			if(SMatr[j][0] > SMatr[j + 1][0])
				swap(SMatr[j], SMatr[j + 1]);
		}
    }
}

ostream& operator << (ostream& out, const Tprk& m)
{
	out << "Unsorted matr:" << endl;
	for (int i = 0; i < m.n; i++) 
	{
		if (m.Matr[i][0] != 0) 
		{
			for (int j = 0; j < (m.Matr[i][0] + 1) * 2; j++) 
			{
				out << m.Matr[i][j] << " ";
			}
			out << endl;
		}
	}
	out << "\nSorted matr:" << endl;
	for (int i = 0; i < m.n; i++) 
	{
		if (m.SMatr[i][0] != 0) 
		{
			for (int j = 0; j < (m.SMatr[i][0] + 1) * 2; j++) 
			{
				out << m.SMatr[i][j] << " ";
			}
			out << endl;
		}
	}
	return out;
}