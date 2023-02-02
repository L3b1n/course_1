#include "model.h"
#include <vector>
#include <cmath>
#include <string>
#include <fstream>
#include <iostream>
#include <cstring>

using namespace std;

string r = "r", r_ = "r'", r2 = "r2";
string l = "l", l_ = "l'", l2 = "l2";
string u = "u", u_ = "u'", u2 = "u2";
string d = "d", d_ = "d'", d2 = "d2";
string f = "f", f_ = "f'", f2 = "f2";
string b = "b", b_ = "b'", b2 = "b2";
string m = "m", m_ = "m'", m2 = "m2";
string s = "s", s_ = "s'", s2 = "s2";
string y = "y", y_ = "y'", y2 = "y2";
string z = "z", z_ = "z'", z2 = "z2";
string uw = "uw", uw_ = "uw'", uw2 = "uw2";
string dw = "dw", dw_ = "dw'", dw2 = "dw2";
string rw = "rw", rw_ = "rw'", rw2 = "rw2";
string lw = "lw", lw_ = "lw'", lw2 = "lw2";
string fw = "fw", fw_ = "fw'", fw2 = "fw2";
string bw = "bw", bw_ = "bw'", bw2 = "bw2";

int compare(const void* x1, const void* x2)
{
	return (*(int*)x1 - *(int*)x2);
}

void Search(Model& a, string& str1)
{
	int temp;
	char *buf;
    char str2[256];
    const char *sf = " ";
	strcpy(str2, str1.c_str());
	buf = strtok(str2, sf);
	while(buf)
	{
		string str(buf);
		if(str == y && a.top_facet == 0)
		{ 
			if(a.current_facet == 1){ r = "f"; r_ = "f'"; r2 = "f2"; l = "b"; l_ = "b'"; l2 = "b2"; f = "l"; f_ = "l'"; 
			f2 = "l2"; b = "r"; b_ = "r'"; b2 = "r2"; m = "s'"; m_ = "s"; m2 = "s2"; s = "m"; s_ = "m'"; s2 = "m2"; rw = "fw"; 
			rw_ = "fw'"; rw2 = "fw2"; lw = "bw"; lw_ = "bw'"; lw2 = "bw2"; fw = "lw"; fw_ = "lw'"; fw2 = "lw2"; bw = "rw"; 
			bw_ = "rw'"; bw2 = "rw2"; temp = 4;}
			if(a.current_facet == 2){ r = "r"; r_ = "r'"; r2 = "r2"; l = "l"; l_ = "l'"; l2 = "l2"; f = "f"; f_ = "f'"; 
			f2 = "f2"; b = "b"; b_ = "b'"; b2 = "b2"; m = "m"; m_ = "m'"; m2 = "m2"; s = "s"; s_ = "s'"; s2 = "s2"; rw = "rw"; 
			rw_ = "rw'"; rw2 = "rw2"; lw = "lw"; lw_ = "lw'"; lw2 = "lw2"; fw = "fw"; fw_ = "fw'"; fw2 = "fw2"; bw = "bw"; 
			bw_ = "bw'"; bw2 = "bw2"; temp = 1;}
			if(a.current_facet == 3){ r = "b"; r_ = "b'"; r2 = "b2"; l = "f"; l_ = "f'"; l2 = "f2"; f = "r"; f_ = "r'"; 
			f2 = "r2"; b = "l"; b_ = "l'"; b2 = "l2"; m = "s"; m_ = "s'"; m2 = "s2"; s = "m"; s_ = "m'"; s2 = "m2"; rw = "bw"; 
			rw_ = "bw'"; rw2 = "bw2"; lw = "fw"; lw_ = "fw'"; lw2 = "fw2"; fw = "rw"; fw_ = "rw'"; fw2 = "rw2"; bw = "lw"; 
			bw_ = "lw'"; bw2 = "lw2"; temp = 2;}
			if(a.current_facet == 4){ r = "l"; r_ = "l'"; r2 = "l2"; l = "r"; l_ = "r'"; l2 = "r2"; f = "b"; f_ = "b'"; 
			f2 = "b2"; b = "f"; b_ = "f'"; b2 = "f2"; m = "m'"; m_ = "m"; m2 = "m2"; s = "s'"; s_ = "s"; s2 = "s2"; rw = "lw"; 
			rw_ = "lw'"; rw2 = "lw2"; lw = "rw"; lw_ = "rw'"; lw2 = "rw2"; fw = "bw"; fw_ = "bw'"; fw2 = "bw2"; bw = "fw"; 
			bw_ = "fw'"; bw2 = "fw2"; temp = 3;}
			a.current_facet = temp;
		}
		if(str == y && a.top_facet == 5)
		{
			if(a.current_facet == 1){ r = "b"; r_ = "b'"; r2 = "b2"; l = "f"; l_ = "f'"; l2 = "f2"; f = "l"; f_ = "l'"; 
			f2 = "l2"; b = "r"; b_ = "r'"; b2 = "r2"; m = "s"; m_ = "s'"; m2 = "s2"; s = "m"; s_ = "m'"; s2 = "m2"; rw = "bw"; 
			rw_ = "bw'"; rw2 = "bw2"; lw = "fw"; lw_ = "fw'"; lw2 = "fw2"; fw = "lw"; fw_ = "lw'"; fw2 = "lw2"; bw = "rw"; 
			bw_ = "rw'"; bw2 = "rw2"; temp = 2;}
			if(a.current_facet == 2){ r = "r"; r_ = "r'"; r2 = "r2"; l = "l"; l_ = "l'"; l2 = "l2"; f = "b"; f_ = "b'"; 
			f2 = "b2"; b = "f"; b_ = "f'"; b2 = "f2"; m = "m"; m_ = "m'"; m2 = "m2"; s = "s"; s_ = "s'"; s2 = "s2"; rw = "rw"; 
			rw_ = "rw'"; rw2 = "rw2"; lw = "lw"; lw_ = "lw'"; lw2 = "lw2"; fw = "bw"; fw_ = "bw'"; fw2 = "bw2"; bw = "fw"; 
			bw_ = "fw'"; bw2 = "fw2"; temp = 3;}
			if(a.current_facet == 3){ r = "f"; r_ = "f'"; r2 = "f2"; l = "b"; l_ = "b'"; l2 = "b2"; f = "r"; f_ = "r'"; 
			f2 = "r2"; b = "l"; b_ = "l'"; b2 = "l2"; m = "s'"; m_ = "s"; m2 = "s2"; s = "m'"; s_ = "m"; s2 = "m2"; rw = "fw"; 
			rw_ = "fw'"; rw2 = "fw2"; lw = "bw"; lw_ = "bw'"; lw2 = "bw2"; fw = "rw"; fw_ = "rw'"; fw2 = "rw2"; bw = "lw"; 
			bw_ = "lw'"; bw2 = "lw2"; temp = 4;}
			if(a.current_facet == 4){ r = "l"; r_ = "l'"; r2 = "l2"; l = "r"; l_ = "r'"; l2 = "r2"; f = "f"; f_ = "f'"; 
			f2 = "f2"; b = "b"; b_ = "b'"; b2 = "b2"; m = "m'"; m_ = "m"; m2 = "m2"; s = "s'"; s_ = "s"; s2 = "s2"; rw = "lw"; 
			rw_ = "lw'"; rw2 = "lw2"; lw = "rw"; lw_ = "rw'"; lw2 = "rw2"; fw = "fw"; fw_ = "fw'"; fw2 = "fw2"; bw = "bw"; 
			bw_ = "bw'"; bw2 = "bw2"; temp = 1;}
			a.current_facet = temp;
		}

		if(str == y_ && a.top_facet == 0)
		{ 
			if(a.current_facet == 1){ r = "b"; r_ = "b'"; r2 = "b2"; l = "f"; l_ = "f'"; l2 = "f2"; f = "r"; f_ = "r'"; 
			f2 = "r2"; b = "l"; b_ = "l'"; b2 = "l2"; m = "s"; m_ = "s'"; m2 = "s2"; s = "m'"; s_ = "m"; s2 = "m2"; rw = "bw"; 
			rw_ = "bw'"; rw2 = "bw2"; lw = "fw"; lw_ = "fw'"; lw2 = "fw2"; fw = "rw"; fw_ = "rw'"; fw2 = "rw2"; bw = "lw"; 
			bw_ = "lw'"; bw2 = "lw2"; temp = 2;}
			if(a.current_facet == 2){ r = "l"; r_ = "l'"; r2 = "l2"; l = "r"; l_ = "r'"; l2 = "r2"; f = "b"; f_ = "b'"; 
			f2 = "b2"; b = "f"; b_ = "f'"; b2 = "f2"; m = "m'"; m_ = "m"; m2 = "m2"; s = "s'"; s_ = "s"; s2 = "s2"; rw = "lw"; 
			rw_ = "lw'"; rw2 = "lw2"; lw = "rw"; lw_ = "rw'"; lw2 = "rw2"; fw = "bw"; fw_ = "bw'"; fw2 = "bw2"; bw = "fw"; 
			bw_ = "fw'"; bw2 = "fw2"; temp = 3;}
			if(a.current_facet == 3){ r = "f"; r_ = "f'"; r2 = "f2"; l = "b"; l_ = "b'"; l2 = "b2"; f = "l"; f_ = "l'"; 
			f2 = "l2"; b = "r"; b_ = "r'"; b2 = "r2"; m = "s'"; m_ = "s"; m2 = "s2"; s = "m"; s_ = "m'"; s2 = "m2"; rw = "fw"; 
			rw_ = "fw'"; rw2 = "fw2"; lw = "bw"; lw_ = "bw'"; lw2 = "bw2"; fw = "lw"; fw_ = "lw'"; fw2 = "lw2"; bw = "rw"; 
			bw_ = "rw'"; bw2 = "rw2"; temp = 4;}
			if(a.current_facet == 4){ r = "r"; r_ = "r'"; r2 = "r2"; l = "l"; l_ = "l'"; l2 = "l2"; f = "f"; f_ = "f'"; 
			f2 = "f2"; b = "b"; b_ = "b'"; b2 = "b2"; m = "m"; m_ = "m'"; m2 = "m2"; s = "s"; s_ = "s'"; s2 = "s2"; rw = "rw"; 
			rw_ = "rw'"; rw2 = "rw2"; lw = "lw"; lw_ = "lw'"; lw2 = "lw2"; fw = "fw"; fw_ = "fw'"; fw2 = "fw2"; bw = "bw"; 
			bw_ = "bw'"; bw2 = "bw2"; temp = 1;}
			a.current_facet = temp;
		}
		if(str == y_ && a.top_facet == 5)
		{
			if(a.current_facet == 1){ r = "f"; r_ = "f'"; r2 = "f2"; l = "b"; l_ = "b'"; l2 = "b2"; f = "r"; f_ = "r'"; 
			f2 = "r2"; b = "l"; b_ = "l'"; b2 = "l2"; m = "s'"; m_ = "s"; m2 = "s2"; s = "m'"; s_ = "m"; s2 = "m2"; rw = "fw"; 
			rw_ = "fw'"; rw2 = "fw2"; lw = "bw"; lw_ = "bw'"; lw2 = "bw2"; fw = "rw"; fw_ = "rw'"; fw2 = "rw2"; bw = "lw"; 
			bw_ = "lw'"; bw2 = "lw2"; temp = 4;}
			if(a.current_facet == 2){ r = "l"; r_ = "l'"; r2 = "l2"; l = "r"; l_ = "r'"; l2 = "r2"; f = "f"; f_ = "f'"; 
			f2 = "f2"; b = "b"; b_ = "b'"; b2 = "b2"; m = "m'"; m_ = "m"; m2 = "m2"; s = "s'"; s_ = "s"; s2 = "s2"; rw = "lw"; 
			rw_ = "lw'"; rw2 = "lw2"; lw = "rw"; lw_ = "rw'"; lw2 = "rw2"; fw = "fw"; fw_ = "fw'"; fw2 = "fw2"; bw = "bw"; 
			bw_ = "bw'"; bw2 = "bw2"; temp = 1;}
			if(a.current_facet == 3){ r = "b"; r_ = "b'"; r2 = "b2"; l = "f"; l_ = "f'"; l2 = "f2"; f = "l"; f_ = "l'"; 
			f2 = "l2"; b = "r"; b_ = "r'"; b2 = "r2"; m = "s"; m_ = "s'"; m2 = "s2"; s = "m'"; s_ = "m"; s2 = "m2"; rw = "bw"; 
			rw_ = "bw'"; rw2 = "bw2"; lw = "fw"; lw_ = "fw'"; lw2 = "fw2"; fw = "lw"; fw_ = "lw'"; fw2 = "lw2"; bw = "rw"; 
			bw_ = "rw'"; bw2 = "rw2"; temp = 2;}
			if(a.current_facet == 4){ r = "r"; r_ = "r'"; r2 = "r2"; l = "l"; l_ = "l'"; l2 = "l2"; f = "b"; f_ = "b'"; 
			f2 = "b2"; b = "f"; b_ = "f'"; b2 = "f2"; m = "m"; m_ = "m'"; m2 = "m2"; s = "s"; s_ = "s'"; s2 = "s2"; rw = "rw"; 
			rw_ = "rw'"; rw2 = "rw2"; lw = "lw"; lw_ = "lw'"; lw2 = "lw2"; fw = "bw"; fw_ = "bw'"; fw2 = "bw2"; bw = "fw"; 
			bw_ = "fw'"; bw2 = "fw2"; temp = 3;}
			a.current_facet = temp;
		}

		if(str == y2 && a.top_facet == 0)
		{ 
			if(a.current_facet == 1){ r = "l"; r_ = "l'"; r2 = "l2"; l = "r"; l_ = "r'"; l2 = "r2"; f = "b"; f_ = "b'"; 
			f2 = "b2"; b = "f"; b_ = "f'"; b2 = "f2"; m = "m'"; m_ = "m"; m2 = "m2"; s = "s'"; s_ = "s"; s2 = "s2"; rw = "lw"; 
			rw_ = "lw'"; rw2 = "lw2"; lw = "rw"; lw_ = "rw'"; lw2 = "rw2"; fw = "bw"; fw_ = "bw'"; fw2 = "bw2"; bw = "fw"; 
			bw_ = "fw'"; bw2 = "fw2"; temp = 3;}
			if(a.current_facet == 2){ r = "f"; r_ = "f'"; r2 = "f2"; l = "b"; l_ = "b'"; l2 = "b2"; f = "l"; f_ = "l'"; 
			f2 = "l2"; b = "r"; b_ = "r'"; b2 = "r2"; m = "s'"; m_ = "s"; m2 = "s2"; s = "m"; s_ = "m'"; s2 = "m2"; rw = "fw"; 
			rw_ = "fw'"; rw2 = "fw2"; lw = "bw"; lw_ = "bw'"; lw2 = "bw2"; fw = "lw"; fw_ = "lw'"; fw2 = "lw2"; bw = "rw"; 
			bw_ = "rw'"; bw2 = "rw2"; temp = 4;}
			if(a.current_facet == 3){ r = "r"; r_ = "r'"; r2 = "r2"; l = "l"; l_ = "l'"; l2 = "l2"; f = "f"; f_ = "f'"; 
			f2 = "f2"; b = "b"; b_ = "b'"; b2 = "b2"; m = "m"; m_ = "m'"; m2 = "m2"; s = "s"; s_ = "s'"; s2 = "s2"; rw = "rw"; 
			rw_ = "rw'"; rw2 = "rw2"; lw = "lw"; lw_ = "lw'"; lw2 = "lw2"; fw = "fw"; fw_ = "fw'"; fw2 = "fw2"; bw = "bw"; 
			bw_ = "bw'"; bw2 = "bw2"; temp = 1;}
			if(a.current_facet == 4){ r = "b"; r_ = "b'"; r2 = "b2"; l = "f"; l_ = "f'"; l2 = "f2"; f = "r"; f_ = "r'"; 
			f2 = "r2"; b = "l"; b_ = "l'"; b2 = "l2"; m = "s"; m_ = "s'"; m2 = "s2"; s = "m'"; s_ = "m"; s2 = "m2"; rw = "bw"; 
			rw_ = "bw'"; rw2 = "bw2"; lw = "fw"; lw_ = "fw'"; lw2 = "fw2"; fw = "rw"; fw_ = "rw'"; fw2 = "rw2"; bw = "lw"; 
			bw_ = "lw'"; bw2 = "lw2"; temp = 2;}
			a.current_facet = temp;
		}
		if(str == y2 && a.top_facet == 5)
		{
			if(a.current_facet == 1){ r = "r"; r_ = "r'"; r2 = "r2"; l = "l"; l_ = "l'"; l2 = "l2"; f = "b"; f_ = "b'"; 
			f2 = "b2"; b = "f"; b_ = "f'"; b2 = "f2"; m = "m"; m_ = "m'"; m2 = "m2"; s = "s"; s_ = "s'"; s2 = "s2"; rw = "rw"; 
			rw_ = "rw'"; rw2 = "rw2"; lw = "lw"; lw_ = "lw'"; lw2 = "lw2"; fw = "bw"; fw_ = "bw'"; fw2 = "bw2"; bw = "fw"; 
			bw_ = "fw'"; bw2 = "fw2"; temp = 3;}
			if(a.current_facet == 2){ r = "f"; r_ = "f'"; r2 = "f2"; l = "b"; l_ = "b'"; l2 = "b2"; f = "r"; f_ = "r'"; 
			f2 = "r2"; b = "l"; b_ = "l'"; b2 = "l2"; m = "s'"; m_ = "s"; m2 = "s2"; s = "m'"; s_ = "m"; s2 = "m2"; rw = "fw"; 
			rw_ = "fw'"; rw2 = "fw2"; lw = "bw"; lw_ = "bw'"; lw2 = "bw2"; fw = "rw"; fw_ = "rw'"; fw2 = "rw2"; bw = "lw"; 
			bw_ = "lw'"; bw2 = "lw2"; temp = 4;}
			if(a.current_facet == 3){ r = "l"; r_ = "l'"; r2 = "l2"; l = "r"; l_ = "r'"; l2 = "r2"; f = "f"; f_ = "f'"; 
			f2 = "f2"; b = "b"; b_ = "b'"; b2 = "b2"; m = "m'"; m_ = "m"; m2 = "m2"; s = "s'"; s_ = "s"; s2 = "s2"; rw = "lw"; 
			rw_ = "lw'"; rw2 = "lw2"; lw = "rw"; lw_ = "rw'"; lw2 = "rw2"; fw = "fw"; fw_ = "fw'"; fw2 = "fw2"; bw = "bw"; 
			bw_ = "bw'"; bw2 = "bw2"; temp = 1;}
			if(a.current_facet == 4){ r = "b"; r_ = "b'"; r2 = "b2"; l = "f"; l_ = "f'"; l2 = "f2"; f = "l"; f_ = "l'"; 
			f2 = "l2"; b = "r"; b_ = "r'"; b2 = "r2"; m = "s"; m_ = "s'"; m2 = "s2"; s = "m'"; s_ = "m"; s2 = "m2"; rw = "bw"; 
			rw_ = "bw'"; rw2 = "bw2"; lw = "fw"; lw_ = "fw'"; lw2 = "fw2"; fw = "lw"; fw_ = "lw'"; fw2 = "lw2"; bw = "rw"; 
			bw_ = "rw'"; bw2 = "rw2"; temp = 2;}
			a.current_facet = temp;
		}

		if(str == z2 && a.top_facet == 0)
		{ 
			if(a.current_facet == 1){ r = "l"; r_ = "l'"; r2 = "l2"; l = "r"; l_ = "r'"; l2 = "r2"; f = "f"; f_ = "f'"; 
			f2 = "f2"; b = "b"; b_ = "b'"; b2 = "b2"; m = "m'"; m_ = "m"; m2 = "m2"; s = "s'"; s_ = "s"; s2 = "s2"; rw = "lw"; 
			rw_ = "lw'"; rw2 = "lw2"; lw = "rw"; lw_ = "rw'"; lw2 = "rw2"; fw = "fw"; fw_ = "fw'"; fw2 = "fw2"; bw = "bw"; 
			bw_ = "bw'"; bw2 = "bw2"; u = "d"; u_ = "d'"; u2 = "d2"; d = "u"; d_ = "u'"; d2 = "u2";}
			if(a.current_facet == 2){ r = "b"; r_ = "b'"; r2 = "b2"; l = "f"; l_ = "f'"; l2 = "f2"; f = "r"; f_ = "r'"; 
			f2 = "r2"; b = "l"; b_ = "l'"; b2 = "l2"; m = "s"; m_ = "s'"; m2 = "s2"; s = "m'"; s_ = "m"; s2 = "m2"; rw = "bw"; 
			rw_ = "bw'"; rw2 = "bw2"; lw = "fw"; lw_ = "fw'"; lw2 = "fw2"; fw = "rw"; fw_ = "rw'"; fw2 = "rw2"; bw = "lw"; 
			bw_ = "lw'"; bw2 = "lw2"; u = "d"; u_ = "d'"; u2 = "d2"; d = "u"; d_ = "u'"; d2 = "u2";}
			if(a.current_facet == 3){ r = "r"; r_ = "r'"; r2 = "r2"; l = "l"; l_ = "l'"; l2 = "l2"; f = "f"; f_ = "f'"; 
			f2 = "f2"; b = "b"; b_ = "b'"; b2 = "b2"; m = "m"; m_ = "m'"; m2 = "m2"; s = "s"; s_ = "s'"; s2 = "s2"; rw = "rw"; 
			rw_ = "rw'"; rw2 = "rw2"; lw = "lw"; lw_ = "lw'"; lw2 = "lw2"; fw = "fw"; fw_ = "fw'"; fw2 = "fw2"; bw = "bw"; 
			bw_ = "bw'"; bw2 = "bw2"; u = "d"; u_ = "d'"; u2 = "d2"; d = "u"; d_ = "u'"; d2 = "u2";}
			if(a.current_facet == 4){ r = "f"; r_ = "f'"; r2 = "f2"; l = "b"; l_ = "b'"; l2 = "b2"; f = "l"; f_ = "l'"; 
			f2 = "l2"; b = "r"; b_ = "r'"; b2 = "r2"; m = "s'"; m_ = "s"; m2 = "s2"; s = "m"; s_ = "m'"; s2 = "m2"; rw = "fw"; 
			rw_ = "fw'"; rw2 = "fw2"; lw = "bw"; lw_ = "bw'"; lw2 = "bw2"; fw = "lw"; fw_ = "lw'"; fw2 = "lw2"; bw = "rw"; 
			bw_ = "rw'"; bw2 = "rw2"; u = "d"; u_ = "d'"; u2 = "d2"; d = "u"; d_ = "u'"; d2 = "u2";}
			a.top_facet = 5;
		}
		else if(str == z2 && a.top_facet == 5)
		{
			if(a.current_facet == 1){ r = "r"; r_ = "r'"; r2 = "r2"; l = "l"; l_ = "l'"; l2 = "l2"; f = "f"; f_ = "f'"; 
			f2 = "f2"; b = "b"; b_ = "b'"; b2 = "b2"; m = "m"; m_ = "m'"; m2 = "m2"; s = "s"; s_ = "s'"; s2 = "s2"; rw = "rw"; 
			rw_ = "rw'"; rw2 = "rw2"; lw = "lw"; lw_ = "lw'"; lw2 = "lw2"; fw = "fw"; fw_ = "fw'"; fw2 = "fw2"; bw = "bw"; 
			bw_ = "bw'"; bw2 = "bw2"; u = "u"; u_ = "u'"; u2 = "u2"; d = "d"; d_ = "d'"; d2 = "d2";}
			if(a.current_facet == 2){ r = "b"; r_ = "b'"; r2 = "b2"; l = "f"; l_ = "f'"; l2 = "f2"; f = "r"; f_ = "r'"; 
			f2 = "r2"; b = "l"; b_ = "l'"; b2 = "l2"; m = "s"; m_ = "s'"; m2 = "s2"; s = "m'"; s_ = "m"; s2 = "m2"; rw = "bw"; 
			rw_ = "bw'"; rw2 = "bw2"; lw = "fw"; lw_ = "fw'"; lw2 = "fw2"; fw = "rw"; fw_ = "rw'"; fw2 = "rw2"; bw = "lw"; 
			bw_ = "lw'"; bw2 = "lw2"; u = "u"; u_ = "u'"; u2 = "u2"; d = "d"; d_ = "d'"; d2 = "d2";}
			if(a.current_facet == 3){ r = "l"; r_ = "l'"; r2 = "l2"; l = "r"; l_ = "r'"; l2 = "r2"; f = "b"; f_ = "b'"; 
			f2 = "b2"; b = "f"; b_ = "f'"; b2 = "f2"; m = "m'"; m_ = "m"; m2 = "m2"; s = "s'"; s_ = "s"; s2 = "s2"; rw = "lw"; 
			rw_ = "lw'"; rw2 = "lw2"; lw = "rw"; lw_ = "rw'"; lw2 = "rw2"; fw = "bw"; fw_ = "bw'"; fw2 = "bw2"; bw = "fw"; 
			bw_ = "fw'"; bw2 = "fw2"; u = "u"; u_ = "u'"; u2 = "u2"; d = "d"; d_ = "d'"; d2 = "d2";}
			if(a.current_facet == 4){ r = "f"; r_ = "f'"; r2 = "f2"; l = "b"; l_ = "b'"; l2 = "b2"; f = "l"; f_ = "l'"; 
			f2 = "l2"; b = "r"; b_ = "r'"; b2 = "r2"; m = "s'"; m_ = "s"; m2 = "s2"; s = "m"; s_ = "m'"; s2 = "m2"; rw = "fw"; 
			rw_ = "fw'"; rw2 = "fw2"; lw = "bw"; lw_ = "bw'"; lw2 = "bw2"; fw = "lw"; fw_ = "lw'"; fw2 = "lw2"; bw = "rw"; 
			bw_ = "rw'"; bw2 = "rw2"; u = "u"; u_ = "u'"; u2 = "u2"; d = "d"; d_ = "d'"; d2 = "d2";}
			a.top_facet = 0;
		}

		if(str == m){ a.Middle_color();}
		if(str == m_){ a.Middle_color_stroke();}
		if(str == m2){ a.Middle_color(); a.Middle_color();}

		if(str == s){ a.Second_color();}
		if(str == s_){ a.Second_color_stroke();}
		if(str == s2){ a.Second_color(); a.Second_color();}
		
		if(str == u){ a.Up_color(); a[0].Change_index();}
		if(str == u_){ a.Up_color_stroke(); a[0].Change_index_stroke();}
		if(str == u2){ a.Up_color(); a[0].Change_index(); a.Up_color(); a[0].Change_index();}
		
		if(str == d){ a.Down_color(); a[5].Change_index();}
		if(str == d_){ a.Down_color_stroke(); a[5].Change_index_stroke();}
		if(str == d2){ a.Down_color(); a[5].Change_index(); a.Down_color(); a[5].Change_index();}
		
		if(str == r){ a.Right_color(); a[4].Change_index();}
		if(str == r_){ a.Right_color_stroke(); a[4].Change_index_stroke();}
		if(str == r2){ a.Right_color(); a[4].Change_index(); a.Right_color(); a[4].Change_index();}
		
		if(str == l){ a.Left_color(); a[2].Change_index();}
		if(str == l_){ a.Left_color_stroke(); a[2].Change_index_stroke();}
		if(str == l2){ a.Left_color(); a[2].Change_index(); a.Left_color(); a[2].Change_index();}

		if(str == f){ a.Front_color(); a[1].Change_index();}
		if(str == f_){ a.Front_color_stroke(); a[1].Change_index_stroke();}
		if(str == f2){ a.Front_color(); a[1].Change_index(); a.Front_color(); a[1].Change_index();}

		if(str == b){ a.Back_color(); a[3].Change_index();}
		if(str == b_){ a.Back_color_stroke(); a[3].Change_index_stroke();}
		if(str == b2){ a.Back_color(); a[3].Change_index(); a.Back_color(); a[3].Change_index();}

		if(str == rw){ a.Rw_color(); a[4].Change_index();}
		if(str == rw_){ a.Rw_color_stroke(); a[4].Change_index_stroke();}
		if(str == rw2){ a.Rw_color(); a[4].Change_index(); a.Rw_color(); a[4].Change_index();}

		if(str == lw){ a.Lw_color(); a[2].Change_index();}
		if(str == lw_){ a.Lw_color_stroke(); a[2].Change_index_stroke();}
		if(str == lw2){ a.Lw_color(); a[2].Change_index(); a.Lw_color(); a[2].Change_index();}

		if(str == fw){ a.Fw_color(); a[1].Change_index();}
		if(str == fw_){ a.Fw_color_stroke(); a[1].Change_index_stroke();}
		if(str == fw2){ a.Fw_color(); a[1].Change_index(); a.Fw_color(); a[1].Change_index();}

		if(str == bw){ a.Bw_color(); a[3].Change_index();}
		if(str == bw_){ a.Bw_color_stroke(); a[3].Change_index_stroke();}
		if(str == bw2){ a.Bw_color(); a[3].Change_index(); a.Bw_color(); a[3].Change_index();}
		buf = strtok(NULL, sf);
	}
	str1 = "";
}

int Data(Model& a, int& pos, int& count)
{
	pos = 0; count = 0;
	///first line
	if(a(5, 1) == 1 && a(5, 2) == 2 && a(5, 3) == 3){ pos = 2; count = 3;}
	if(a(5, 1) == 1 && a(5, 2) == 2 && count < 2){ pos = 2; count = 2;}
	if(a(5, 2) == 2 && a(5, 3) == 3 && count < 2){ pos = 2; count = 2;}

	if(a(5, 1) == 7 && a(5, 2) == 4 && a(5, 3) == 1 && count < 3){ pos = 4; count = 3;}
	if(a(5, 1) == 7 && a(5, 2) == 4 && count < 2){ pos = 4; count = 2;}
	if(a(5, 2) == 4 && a(5, 3) == 1 && count < 2){ pos = 4; count = 2;}

	if(a(5, 1) == 9 && a(5, 2) == 8 && a(5, 3) == 7 && count < 3){ pos = 8; count = 3;}
	if(a(5, 1) == 9 && a(5, 2) == 8 && count < 2){ pos = 8; count = 2;}
	if(a(5, 2) == 8 && a(5, 3) == 7 && count < 2){ pos = 8; count = 2;}

	if(a(5, 1) == 3 && a(5, 2) == 6 && a(5, 3) == 9 && count < 3){ pos = 6; count = 3;}
	if(a(5, 1) == 3 && a(5, 2) == 6 && count < 2){ pos = 6; count = 2;}
	if(a(5, 2) == 3 && a(5, 3) == 6 && count < 2){ pos = 6; count = 2;}

	///second table
	if(a(5, 3) == 1 && a(5, 6) == 2 && a(5, 9) == 3){ pos = 2; count = 3;}
	if(a(5, 3) == 1 && a(5, 6) == 2 && count < 2){ pos = 2; count = 2;}
	if(a(5, 6) == 2 && a(5, 9) == 3 && count < 2){ pos = 2; count = 2;}

	if(a(5, 3) == 7 && a(5, 6) == 4 && a(5, 9) == 1 && count < 3){ pos = 4; count = 3;}
	if(a(5, 3) == 7 && a(5, 6) == 4 && count < 2){ pos = 4; count = 2;}
	if(a(5, 6) == 4 && a(5, 9) == 1 && count < 2){ pos = 4; count = 2;}

	if(a(5, 3) == 9 && a(5, 6) == 8 && a(5, 9) == 7 && count < 3){ pos = 8; count = 3;}
	if(a(5, 3) == 9 && a(5, 6) == 8 && count < 2){ pos = 8; count = 2;}
	if(a(5, 6) == 8 && a(5, 9) == 7 && count < 2){ pos = 8; count = 2;}

	if(a(5, 3) == 3 && a(5, 6) == 6 && a(5, 9) == 9 && count < 3){ pos = 6; count = 3;}
	if(a(5, 3) == 3 && a(5, 6) == 6 && count < 2){ pos = 6; count = 2;}
	if(a(5, 6) == 3 && a(5, 9) == 6 && count < 2){ pos = 6; count = 2;}

	///secont line
	if(a(5, 9) == 1 && a(5, 8) == 2 && a(5, 7) == 3){ pos = 2; count = 3;}
	if(a(5, 9) == 1 && a(5, 8) == 2 && count < 2){ pos = 2; count = 2;}
	if(a(5, 8) == 2 && a(5, 7) == 3 && count < 2){ pos = 2; count = 2;}

	if(a(5, 9) == 7 && a(5, 8) == 4 && a(5, 7) == 1 && count < 3){ pos = 4; count = 3;}
	if(a(5, 9) == 7 && a(5, 8) == 4 && count < 2){ pos = 4; count = 2;}
	if(a(5, 8) == 4 && a(5, 7) == 1 && count < 2){ pos = 4; count = 2;}

	if(a(5, 9) == 9 && a(5, 8) == 8 && a(5, 7) == 7 && count < 3){ pos = 8; count = 3;}
	if(a(5, 9) == 9 && a(5, 8) == 8 && count < 2){ pos = 8; count = 2;}
	if(a(5, 8) == 8 && a(5, 7) == 7 && count < 2){ pos = 8; count = 2;}

	if(a(5, 9) == 3 && a(5, 8) == 6 && a(5, 7) == 9 && count < 3){ pos = 6; count = 3;}
	if(a(5, 9) == 3 && a(5, 8) == 6 && count < 2){ pos = 6; count = 2;}
	if(a(5, 8) == 6 && a(5, 7) == 9 && count < 2){ pos = 6; count = 2;}

	///first table 
	if(a(5, 7) == 1 && a(5, 4) == 2 && a(5, 1) == 3){ pos = 2; count = 3;}
	if(a(5, 7) == 1 && a(5, 4) == 2 && count < 2){ pos = 2; count = 2;}
	if(a(5, 4) == 2 && a(5, 1) == 3 && count < 2){ pos = 2; count = 2;}

	if(a(5, 7) == 7 && a(5, 4) == 4 && a(5, 1) == 1 && count < 3){ pos = 4; count = 3;}
	if(a(5, 7) == 7 && a(5, 4) == 4 && count < 2){ pos = 4; count = 2;}
	if(a(5, 4) == 4 && a(5, 1) == 1 && count < 2){ pos = 4; count = 2;}

	if(a(5, 7) == 9 && a(5, 4) == 8 && a(5, 1) == 7 && count < 3){ pos = 8; count = 3;}
	if(a(5, 7) == 9 && a(5, 4) == 8 && count < 2){ pos = 8; count = 2;}
	if(a(5, 4) == 8 && a(5, 1) == 7 && count < 2){ pos = 8; count = 2;}

	if(a(5, 7) == 3 && a(5, 4) == 6 && a(5, 1) == 9 && count < 3){ pos = 6; count = 3;}
	if(a(5, 7) == 3 && a(5, 4) == 6 && count < 2){ pos = 6; count = 2;}
	if(a(5, 4) == 3 && a(5, 1) == 6 && count < 2){ pos = 6; count = 2;}

	if(count >= 2){ return 0;}
	
	///corners
	if(a(5, 1) == 1 && a(5, 3) == 3){ pos = 1; count = 2;}
	if(a(5, 1) == 7 && a(5, 3) == 1){ pos = 7; count = 2;}
	if(a(5, 1) == 9 && a(5, 3) == 7){ pos = 9; count = 2;}
	if(a(5, 1) == 3 && a(5, 3) == 9){ pos = 3; count = 2;}

	if(a(5, 3) == 1 && a(5, 9) == 3){ pos = 1; count = 2;}
	if(a(5, 3) == 7 && a(5, 9) == 1){ pos = 7; count = 2;}
	if(a(5, 3) == 9 && a(5, 9) == 7){ pos = 9; count = 2;}
	if(a(5, 3) == 3 && a(5, 9) == 9){ pos = 3; count = 2;}

	if(a(5, 9) == 1 && a(5, 7) == 3){ pos = 1; count = 2;}
	if(a(5, 9) == 7 && a(5, 7) == 1){ pos = 7; count = 2;}
	if(a(5, 9) == 9 && a(5, 7) == 7){ pos = 9; count = 2;}
	if(a(5, 9) == 3 && a(5, 7) == 9){ pos = 3; count = 2;}

	if(a(5, 7) == 1 && a(5, 1) == 3){ pos = 1; count = 2;}
	if(a(5, 7) == 7 && a(5, 1) == 1){ pos = 7; count = 2;}
	if(a(5, 7) == 9 && a(5, 1) == 7){ pos = 9; count = 2;}
	if(a(5, 7) == 3 && a(5, 1) == 9){ pos = 3; count = 2;}

	return 0;
}

int* Between(int ind, string str)
{
	int *a = new int [3];
	if(ind == 2 && str == "left") { a[0] = 4; a[1] = 8; a[2] = 6;}
	if(ind == 2 && str == "right") { a[0] = 6; a[1] = 8; a[2] = 4;}
	if(ind == 4 && str == "left") { a[0] = 8; a[1] = 6; a[2] = 2;}
	if(ind == 4 && str == "right") { a[0] = 2; a[1] = 6; a[2] = 8;}
	if(ind == 6 && str == "left") { a[0] = 2; a[1] = 4; a[2] = 8;}
	if(ind == 6 && str == "right") { a[0] = 8; a[1] = 4; a[2] = 2;}
	if(ind == 8 && str == "left") { a[0] = 6; a[1] = 2; a[2] = 4;}
	if(ind == 8 && str == "right") { a[0] = 4; a[1] = 2; a[2] = 6;}
	return a;
}

Model::Model() 
{
	top_facet = 0;
	current_facet = 1;
    Matr = new Color[6];
	Color red("red");
	Color white("white");
	Color blue("blue");
	Color yellow("yellow");
	Color green("green");
	Color orange("orange");
	Matr[0] = red;
	Matr[1] = white;
	Matr[2] = blue;
	Matr[3] = yellow;
	Matr[4] = green;
	Matr[5] = orange;
}

Model::~Model() 
{
	delete[] Matr;
}

Color& Model::operator [] (const int i)
{
    return Matr[i];
}

Col Model::operator () (const int facet, const int position)
{
	Col temp;
	temp.ind = Matr[facet].index[position - 1];
	temp.col = Matr[facet].color[position - 1];
	return temp;
}

bool Model::is_full()
{
	bool b = true;
	string color[6] = {"red", "white", "blue", "yellow", "green", "orange"};
	for(int i = 0; i < 6; i++)
	{
		for(int j = 0; j < 9; j++)
		{
			b = b && (Matr[i].color[j] == color[i]);
			//if(!b) return b;
		}
	}
	return b;
}

int Intersection_fast(Model& a, string& moves)
{
	Col p;
	string str;
	Position pos;
	int ind[4] = {2, 4, 6, 8};
	moves.append("Intersection:\n");
	a.current_facet == 4 ? str = " y'" : (a.current_facet == 3 ? str = " y2" : (a.current_facet == 2 ? str = " y" : str = ""));
	moves.append(str); Search(a, str);
	for(int i = 0, n; i < 4; i++)
	{ 
		pos = a.Pos(ind, n);
		cout << n << "  " << pos << endl;
		if(pos.facet == 1)
		{
			if(pos.position == 2)
			{
				n == 2 && (a(0, 2) == p(8, "red") || a(0, 4) == p(6, "red") || a(0, 6) == p(4, "red")) ? str.append(" f u' r")
				: (n == 2 && (a(0, 2) == p(4, "red") || a(0, 4) == p(8, "red")) ? str.append(" f r")  
				: (n == 2 && (a(0, 2) == p(6, "red") || a(0, 6) == p(8, "red")) ? str.append(" f' l'") 
				: (n == 2 && (a(0, 4) == p(4, "red") || a(0, 6) == p(6, "red")) ? str.append(" f u r") 
				: (n == 2 ? str.append(" f r") : str.append("")))));

				n == 4 && (a(0, 2) == p(6, "red") || a(0, 4) == p(2, "red") || a(0, 6) == p(8, "red")) ? str.append(" f' u l'")
				: (n == 4 && (a(0, 2) == p(8, "red") || a(0, 4) == p(6, "red")) ? str.append(" f r")  
				: (n == 4 && (a(0, 2) == p(2, "red") || a(0, 6) == p(6, "red")) ? str.append(" f' l'") 
				: (n == 4 && (a(0, 4) == p(8, "red") || a(0, 6) == p(2, "red")) ? str.append(" f' u' l'") 
				: (n == 4 ? str.append(" f' l'") : str.append("")))));

				n == 6 && (a(0, 2) == p(4, "red") || a(0, 4) == p(8, "red") || a(0, 6) == p(2, "red")) ? str.append(" f u' r")
				: (n == 6 && (a(0, 2) == p(2, "red") || a(0, 4) == p(4, "red")) ? str.append(" f r")  
				: (n == 6 && (a(0, 2) == p(8, "red") || a(0, 6) == p(4, "red")) ? str.append(" f' l'") 
				: (n == 6 && (a(0, 4) == p(2, "red") || a(0, 6) == p(8, "red")) ? str.append(" f u r") 
				: (n == 6 ? str.append(" f r") : str.append("")))));

				n == 8 && (a(0, 2) == p(2, "red") || a(0, 4) == p(4, "red") || a(0, 6) == p(6, "red")) ? str.append(" f u' r")
				: (n == 8 && (a(0, 2) == p(6, "red") || a(0, 4) == p(2, "red")) ? str.append(" f r")  
				: (n == 8 && (a(0, 2) == p(4, "red") || a(0, 6) == p(2, "red")) ? str.append(" f' l'") 
				: (n == 8 && (a(0, 4) == p(6, "red") || a(0, 6) == p(4, "red")) ? str.append(" f u r") 
				: (n == 8 ? str.append(" f r") : str.append("")))));
			}
			if(pos.position == 4)
			{
				n == 2 && (a(0, 2) == p(6, "red") || a(0, 6) == p(8, "red") || a(0, 8) == p(4, "red")) ? str.append(" l'") 
				: (n == 2 && (a(0, 2) == p(8, "red") || a(0, 4) == p(6, "red") || a(0, 6) == p(4, "red")) ? str.append(" u l'") 
				: (n == 2 && (a(0, 2) == p(4, "red") || a(0, 4) == p(8, "red") || a(0, 8) == p(6, "red")) ? str.append(" u2 l'") 
				: (n == 2 && (a(0, 4) == p(4, "red") || a(0, 6) == p(6, "red") || a(0, 8) == p(8, "red")) ? str.append(" u' l'") 
				: (n == 2 ? str.append(" l'") : str.append("")))));

				n == 4 && (a(0, 2) == p(2, "red") || a(0, 6) == p(6, "red") || a(0, 8) == p(8, "red")) ? str.append(" l'") 
				: (n == 4 && (a(0, 2) == p(6, "red") || a(0, 4) == p(2, "red") || a(0, 6) == p(8, "red")) ? str.append(" u l'") 
				: (n == 4 && (a(0, 2) == p(8, "red") || a(0, 4) == p(6, "red") || a(0, 8) == p(2, "red")) ? str.append(" u2 l'") 
				: (n == 4 && (a(0, 4) == p(8, "red") || a(0, 6) == p(2, "red") || a(0, 8) == p(6, "red")) ? str.append(" u' l'") 
				: (n == 4 ? str.append(" l'") : str.append("")))));

				n == 6 && (a(0, 2) == p(8, "red") || a(0, 6) == p(4, "red") || a(0, 8) == p(2, "red")) ? str.append(" l'") 
				: (n == 6 && (a(0, 2) == p(4, "red") || a(0, 4) == p(8, "red") || a(0, 6) == p(2, "red")) ? str.append(" u l'") 
				: (n == 6 && (a(0, 2) == p(2, "red") || a(0, 4) == p(4, "red") || a(0, 8) == p(8, "red")) ? str.append(" u2 l'") 
				: (n == 6 && (a(0, 4) == p(2, "red") || a(0, 6) == p(8, "red") || a(0, 8) == p(4, "red")) ? str.append(" u' l'") 
				: (n == 6 ? str.append(" l'") : str.append("")))));

				n == 8 && (a(0, 2) == p(4, "red") || a(0, 6) == p(2, "red") || a(0, 8) == p(6, "red")) ? str.append(" l'") 
				: (n == 8 && (a(0, 2) == p(2, "red") || a(0, 4) == p(4, "red") || a(0, 6) == p(6, "red")) ? str.append(" u l'") 
				: (n == 8 && (a(0, 2) == p(6, "red") || a(0, 4) == p(2, "red") || a(0, 8) == p(4, "red")) ? str.append(" u2 l'") 
				: (n == 8 && (a(0, 4) == p(6, "red") || a(0, 6) == p(4, "red") || a(0, 8) == p(2, "red")) ? str.append(" u' l'") 
				: (n == 8 ? str.append(" l'") : str.append("")))));
			}
			if(pos.position == 6)//need check
			{
				n == 2 && (a(0, 2) == p(4, "red") || a(0, 4) == p(8, "red") || a(0, 8) == p(6, "red")) ? str.append(" r") //checked
				: (n == 2 && (a(0, 2) == p(8, "red") || a(0, 4) == p(6, "red") || a(0, 6) == p(4, "red")) ? str.append(" u' r") //checked
				: (n == 2 && (a(0, 2) == p(6, "red") || a(0, 6) == p(8, "red") || a(0, 8) == p(4, "red")) ? str.append(" u2 r") 
				: (n == 2 && (a(0, 4) == p(4, "red") || a(0, 6) == p(6, "red") || a(0, 8) == p(8, "red")) ? str.append(" u r") 
				: (n == 2 ? str.append(" r") : str.append("")))));

				n == 4 && (a(0, 2) == p(8, "red") || a(0, 4) == p(6, "red") || a(0, 8) == p(2, "red")) ? str.append(" r") 
				: (n == 4 && (a(0, 2) == p(6, "red") || a(0, 4) == p(2, "red") || a(0, 6) == p(8, "red")) ? str.append(" u' r") 
				: (n == 4 && (a(0, 2) == p(2, "red") || a(0, 6) == p(6, "red") || a(0, 8) == p(8, "red")) ? str.append(" u2 r") 
				: (n == 4 && (a(0, 4) == p(8, "red") || a(0, 6) == p(2, "red") || a(0, 8) == p(6, "red")) ? str.append(" u r") 
				: (n == 4 ? str.append(" r") : str.append("")))));

				n == 6 && (a(0, 2) == p(2, "red") || a(0, 4) == p(4, "red") || a(0, 8) == p(8, "red")) ? str.append(" r") 
				: (n == 6 && (a(0, 2) == p(4, "red") || a(0, 4) == p(8, "red") || a(0, 6) == p(2, "red")) ? str.append(" u' r") 
				: (n == 6 && (a(0, 2) == p(8, "red") || a(0, 6) == p(4, "red") || a(0, 8) == p(2, "red")) ? str.append(" u2 r") 
				: (n == 6 && (a(0, 4) == p(2, "red") || a(0, 6) == p(8, "red") || a(0, 8) == p(4, "red")) ? str.append(" u r") 
				: (n == 6 ? str.append(" r") : str.append("")))));

				n == 8 && (a(0, 2) == p(4, "red") || a(0, 4) == p(2, "red") || a(0, 8) == p(6, "red")) ? str.append(" r") 
				: (n == 8 && (a(0, 2) == p(2, "red") || a(0, 4) == p(4, "red") || a(0, 6) == p(6, "red")) ? str.append(" u' r") 
				: (n == 8 && (a(0, 2) == p(4, "red") || a(0, 6) == p(2, "red") || a(0, 8) == p(6, "red")) ? str.append(" u2 r") 
				: (n == 8 && (a(0, 4) == p(6, "red") || a(0, 6) == p(4, "red") || a(0, 8) == p(2, "red")) ? str.append(" u r") 
				: (n == 8 ? str.append(" r") : str.append("")))));
			}
			if(pos.position == 8)
			{
				n == 2 && (a(0, 2) == p(4, "red") || a(0, 8) == p(6, "red") || a(0, 4) == p(8, "red")) ? str.append(a(0, 8) == "red" ? " f' r f" : " f' r")
				: (n == 2 && (a(0, 2) == p(8, "red") || a(0, 4) == p(6, "red") || a(0, 6) == p(4, "red")) ? str.append(" f u' r") 
				: (n == 2 && (a(0, 4) == p(4, "red") || a(0, 6) == p(6, "red") || a(0, 8) == p(8, "red")) ? str.append(a(0, 6) == "red" ? " d r'b r" : " d r' b")
				: (n == 2 && (a(0, 2) == p(6, "red") || a(0, 4) == p(8, "red") || a(0, 8) == p(4, "red")) ? str.append(a(0, 8) == "red" ? " f l' f'" : " f l'")
				: (n == 2 ? str.append(f + r) : str.append("")))));

				n == 4 && (a(0, 2) == p(2, "red") || a(0, 6) == p(6, "red") || a(0, 8) == p(8, "red")) ? str.append(a(0, 8) == "red" ? " f l' f'" : " f l'")
				: (n == 4 && (a(0, 2) == p(6, "red") || a(0, 4) == p(2, "red") || a(0, 6) == p(8, "red")) ? str.append(" f' u l'") 
				: (n == 4 && (a(0, 2) == p(8, "red") || a(0, 4) == p(6, "red") || a(0, 8) == p(2, "red")) ? str.append(a(0, 8) == "red" ? " f' r f" : " f' r")
				: (n == 4 && (a(0, 4) == p(8, "red") || a(0, 6) == p(2, "red") || a(0, 8) == p(6, "red")) ? str.append(a(0, 6) == "red" ? " d r'b r" : " d r' b")
				: (n == 4 ? str.append(f_ + l_) : str.append("")))));

				n == 6 && (a(0, 2) == p(2, "red") || a(0, 4) == p(4, "red") || a(0, 8) == p(8, "red")) ? str.append(a(0, 8) == "red" ? " f' r f" : " f' r")
				: (n == 6 && (a(0, 2) == p(4, "red") || a(0, 4) == p(8, "red") || a(0, 6) == p(2, "red")) ? str.append(" f u' r") 
				: (n == 6 && (a(0, 2) == p(8, "red") || a(0, 6) == p(4, "red") || a(0, 8) == p(2, "red")) ? str.append(a(0, 8) == "red" ? " f l' f'" : " f l'")
				: (n == 6 && (a(0, 4) == p(2, "red") || a(0, 6) == p(8, "red") || a(0, 8) == p(4, "red")) ? str.append(a(0, 6) == "red" ? " d r'b r" : " d r' b")
				: (n == 6 ? str.append(" f r") : str.append("")))));

				n == 8 && (a(0, 2) == p(2, "red") || a(0, 4) == p(4, "red") || a(0, 6) == p(6, "red")) ? str.append(" f u' r") 
				: (n == 8 && (a(0, 2) == p(4, "red") || a(0, 6) == p(2, "red") || a(0, 8) == p(6, "red")) ? str.append(a(0, 8) == "red" ? " f l' f'" : " f l'")
				: (n == 8 && (a(0, 2) == p(6, "red") || a(0, 4) == p(2, "red") || a(0, 8) == p(4, "red")) ? str.append(a(0, 8) == "red" ? " f' r f" : " f' r")
				: (n == 8 && (a(0, 4) == p(6, "red") || a(0, 6) == p(4, "red") || a(0, 8) == p(2, "red")) ? str.append(a(0, 6) == "red" ? " d r'b r" : " d r' b")
				: (n == 8 ? str.append(" f r") : str.append("")))));
			}
		}
		if(pos.facet == 2)
		{
			if(pos.position == 2)
			{
				n == 2 && (a(0, 2) == p(6, "red") || a(0, 6) == p(8, "red") || a(0, 8) == p(4, "red")) ? str.append(" l' u b'") 
				: (n == 2 && (a(0, 2) == p(8, "red") || a(0, 6) == p(4, "red")) ? str.append(" l f") 
				: (n == 2 && (a(0, 2) == p(4, "red") || a(0, 8) == p(6, "red")) ? str.append(" l' u' b'") 
				: (n == 2 && (a(0, 6) == p(6, "red") || a(0, 8) == p(8, "red")) ? str.append(" l' b'") 
				: (n == 2 ? str.append(" l' b'") : str.append("")))));

				n == 4 && (a(0, 2) == p(2, "red") || a(0, 6) == p(6, "red") || a(0, 8) == p(8, "red")) ? str.append(" l' u b'") 
				: (n == 4 && (a(0, 2) == p(6, "red") || a(0, 6) == p(8, "red")) ? str.append(" l f") 
				: (n == 4 && (a(0, 2) == p(8, "red") || a(0, 8) == p(2, "red")) ? str.append(" l' u' b'") 
				: (n == 4 && (a(0, 6) == p(2, "red") || a(0, 8) == p(6, "red")) ? str.append(" l' b'") 
				: (n == 4 ? str.append(" l' b'") : str.append("")))));

				n == 6 && (a(0, 2) == p(8, "red") || a(0, 6) == p(4, "red") || a(0, 8) == p(2, "red")) ? str.append(" l' u b'") 
				: (n == 6 && (a(0, 2) == p(4, "red") || a(0, 6) == p(2, "red")) ? str.append(" l f") 
				: (n == 6 && (a(0, 2) == p(2, "red") || a(0, 8) == p(8, "red")) ? str.append(" l u f") 
				: (n == 6 && (a(0, 6) == p(8, "red") || a(0, 8) == p(4, "red")) ? str.append(" l' b'") 
				: (n == 6 ? str.append(" l' b'") : str.append("")))));

				n == 8 && (a(0, 2) == p(4, "red") || a(0, 6) == p(2, "red") || a(0, 8) == p(6, "red")) ? str.append(" l u' f") 
				: (n == 8 && (a(0, 2) == p(2, "red") || a(0, 6) == p(6, "red")) ? str.append(" l f") 
				: (n == 8 && (a(0, 2) == p(6, "red") || a(0, 8) == p(4, "red")) ? str.append(" l u f") 
				: (n == 8 && (a(0, 6) == p(4, "red") || a(0, 8) == p(2, "red")) ? str.append(" l' b'") 
				: (n == 8 ? str.append(" l f") : str.append("")))));
			}
			if(pos.position == 4)
			{
				n == 2 && (a(0, 4) == p(4, "red") || a(0, 6) == p(6, "red") || a(0, 8) == p(8, "red")) ? str.append(" b'") 
				: (n == 2 && (a(0, 2) == p(6, "red") || a(0, 6) == p(8, "red") || a(0, 8) == p(4, "red")) ? str.append(" u b'") 
				: (n == 2 && (a(0, 2) == p(8, "red") || a(0, 4) == p(6, "red") || a(0, 6) == p(4, "red")) ? str.append(" u' u' b'") 
				: (n == 2 && (a(0, 2) == p(4, "red") || a(0, 4) == p(8, "red") || a(0, 8) == p(6, "red")) ? str.append(" u' b'") 
				: (n == 2 ? str.append(" b'") : str.append("")))));

				n == 4 && (a(0, 4) == p(8, "red") || a(0, 6) == p(2, "red") || a(0, 8) == p(6, "red")) ? str.append(" b'") 
				: (n == 4 && (a(0, 2) == p(2, "red") || a(0, 6) == p(6, "red") || a(0, 8) == p(8, "red")) ? str.append(" u b'") 
				: (n == 4 && (a(0, 2) == p(6, "red") || a(0, 4) == p(2, "red") || a(0, 6) == p(8, "red")) ? str.append(" u' u' b'") 
				: (n == 4 && (a(0, 2) == p(8, "red") || a(0, 4) == p(6, "red") || a(0, 8) == p(2, "red")) ? str.append(" u' b'") 
				: (n == 4 ? str.append(" b'") : str.append("")))));

				n == 6 && (a(0, 4) == p(2, "red") || a(0, 6) == p(8, "red") || a(0, 8) == p(2, "red")) ? str.append(" b'") 
				: (n == 6 && (a(0, 2) == p(8, "red") || a(0, 6) == p(4, "red") || a(0, 8) == p(2, "red")) ? str.append(" u b'") 
				: (n == 6 && (a(0, 2) == p(4, "red") || a(0, 4) == p(8, "red") || a(0, 6) == p(2, "red")) ? str.append(" u' u' b'") 
				: (n == 6 && (a(0, 2) == p(2, "red") || a(0, 4) == p(4, "red") || a(0, 8) == p(8, "red")) ? str.append(" u' b'") 
				: (n == 6 ? str.append(" b'") : str.append("")))));

				n == 8 && (a(0, 4) == p(6, "red") || a(0, 6) == p(4, "red") || a(0, 8) == p(2, "red")) ? str.append(" b'") 
				: (n == 8 && (a(0, 2) == p(5, "red") || a(0, 6) == p(2, "red") || a(0, 8) == p(6, "red")) ? str.append(" u b'") 
				: (n == 8 && (a(0, 2) == p(2, "red") || a(0, 4) == p(4, "red") || a(0, 6) == p(6, "red")) ? str.append(" u' u' b'") 
				: (n == 8 && (a(0, 2) == p(6, "red") || a(0, 4) == p(2, "red") || a(0, 8) == p(4, "red")) ? str.append(" u' b'") 
				: (n == 8 ? str.append(" b'") : str.append("")))));
			}
			if(pos.position == 6)
			{
				n == 2 && (a(0, 2) == p(8, "red") || a(0, 4) == p(6, "red") || a(0, 6) == p(4, "red")) ? str.append(" f") 
				: (n == 2 && (a(0, 2) == p(4, "red") || a(0, 4) == p(8, "red") || a(0, 8) == p(6, "red")) ? str.append(" u f") 
				: (n == 2 && (a(0, 4) == p(4, "red") || a(0, 6) == p(6, "red") || a(0, 8) == p(8, "red")) ? str.append(" u u f") 
				: (n == 2 && (a(0, 2) == p(6, "red") || a(0, 6) == p(8, "red") || a(0, 8) == p(4, "red")) ? str.append(" u' f") 
				: (n == 2 ? str.append(" f") : str.append("")))));

				n == 4 && (a(0, 2) == p(6, "red") || a(0, 4) == p(2, "red") || a(0, 6) == p(6, "red")) ? str.append(" f") 
				: (n == 4 && (a(0, 2) == p(8, "red") || a(0, 4) == p(6, "red") || a(0, 8) == p(2, "red")) ? str.append(" u f") 
				: (n == 4 && (a(0, 4) == p(8, "red") || a(0, 4) == p(2, "red") || a(0, 6) == p(6, "red")) ? str.append(" u u f") 
				: (n == 4 && (a(0, 2) == p(2, "red") || a(0, 6) == p(6, "red") || a(0, 8) == p(8, "red")) ? str.append(" u' f") 
				: (n == 4 ? str.append(" f") : str.append("")))));

				n == 6 && (a(0, 2) == p(6, "red") || a(0, 4) == p(8, "red") || a(0, 6) == p(2, "red")) ? str.append(" f") 
				: (n == 6 && (a(0, 2) == p(2, "red") || a(0, 4) == p(4, "red") || a(0, 8) == p(8, "red")) ? str.append(" u f") 
				: (n == 6 && (a(0, 4) == p(2, "red") || a(0, 4) == p(8, "red") || a(0, 6) == p(4, "red")) ? str.append(" u u f") 
				: (n == 6 && (a(0, 2) == p(8, "red") || a(0, 6) == p(4, "red") || a(0, 8) == p(2, "red")) ? str.append(" u' f") 
				: (n == 6 ? str.append(" f") : str.append("")))));

				n == 8 && (a(0, 2) == p(2, "red") || a(0, 4) == p(4, "red") || a(0, 6) == p(6, "red")) ? str.append(" f") 
				: (n == 8 && (a(0, 2) == p(6, "red") || a(0, 4) == p(2, "red") || a(0, 8) == p(4, "red")) ? str.append(" u f") 
				: (n == 8 && (a(0, 4) == p(6, "red") || a(0, 4) == p(4, "red") || a(0, 6) == p(2, "red")) ? str.append(" u u f") 
				: (n == 8 && (a(0, 2) == p(4, "red") || a(0, 6) == p(2, "red") || a(0, 8) == p(6, "red")) ? str.append(" u' f") 
				: (n == 8 ? str.append(" f") : str.append("")))));
			}
			if(pos.position == 8)
			{
				n == 2 && (a(0, 2) == p(6, "red") || a(0, 6) == p(8, "red") || a(0, 8) == p(4, "red")) ? str.append(" l u b'") 
				: (n == 2 && (a(0, 2) == p(8, "red") || a(0, 4) == p(6, "red") || a(0, 6) == p(4, "red")) ? str.append(a(0, 4) == "red" ? " l' f l" : " l' f")
				: (n == 2 && (a(0, 2) == p(4, "red") || a(0, 4) == p(8, "red") || a(0, 8) == p(6, "red")) ? str.append(a(0, 8) == "red" ? " d f' r f" : " d f' r") 
				: (n == 2 && (a(0, 4) == p(4, "red") || a(0, 6) == p(6, "red") || a(0, 8) == p(8, "red")) ? str.append(a(0, 4) == "red" ? " l b' l'" : " l b'") 
				: (n == 2 ? str.append(" l b'") : str.append("")))));

				n == 4 && (a(0, 2) == p(2, "red") || a(0, 6) == p(6, "red") || a(0, 8) == p(8, "red")) ? str.append(" l u b'") 
				: (n == 4 && (a(0, 2) == p(6, "red") || a(0, 4) == p(2, "red") || a(0, 6) == p(8, "red")) ? str.append(a(0, 4) == "red" ? " l' f l" : " l' f")
				: (n == 4 && (a(0, 2) == p(8, "red") || a(0, 4) == p(6, "red") || a(0, 8) == p(2, "red")) ? str.append(a(0, 8) == "red" ? " d f' r f" : " d f' r") 
				: (n == 4 && (a(0, 4) == p(8, "red") || a(0, 6) == p(2, "red") || a(0, 8) == p(6, "red")) ? str.append(a(0, 4) == "red" ? " l b' l'" : " l b'") 
				: (n == 4 ? str.append(" l b'") : str.append("")))));

				n == 6 && (a(0, 2) == p(8, "red") || a(0, 6) == p(4, "red") || a(0, 8) == p(2, "red")) ? str.append(" l u b'") 
				: (n == 6 && (a(0, 2) == p(4, "red") || a(0, 4) == p(8, "red") || a(0, 6) == p(2, "red")) ? str.append(a(0, 4) == "red" ? " l' f l" : " l' f")
				: (n == 6 && (a(0, 2) == p(2, "red") || a(0, 4) == p(4, "red") || a(0, 8) == p(8, "red")) ? str.append(a(0, 8) == "red" ? " d f' r f" : " d f' r") 
				: (n == 6 && (a(0, 4) == p(2, "red") || a(0, 6) == p(8, "red") || a(0, 8) == p(4, "red")) ? str.append(a(0, 4) == "red" ? " l b' l'" : " l b'") 
				: (n == 6 ? str.append(" l b'") : str.append("")))));

				n == 8 && (a(0, 2) == p(4, "red") || a(0, 6) == p(2, "red") || a(0, 8) == p(6, "red")) ? str.append(" l' u' f") 
				: (n == 8 && (a(0, 2) == p(2, "red") || a(0, 4) == p(4, "red") || a(0, 6) == p(6, "red")) ? str.append(a(0, 4) == "red" ? " l' f l" : " l' f")
				: (n == 8 && (a(0, 2) == p(6, "red") || a(0, 4) == p(2, "red") || a(0, 8) == p(4, "red")) ? str.append(a(0, 8) == "red" ? " d f' r f" : " d f' r") 
				: (n == 8 && (a(0, 4) == p(6, "red") || a(0, 6) == p(4, "red") || a(0, 8) == p(2, "red")) ? str.append(a(0, 4) == "red" ? " l b' l'" : " l b'") 
				: (n == 8 ? str.append(" l' f") : str.append("")))));
			}
		}
		if(pos.facet == 3)
		{
			if(pos.position == 2)
			{
				n == 2 && (a(0, 4) == p(4, "red") || a(0, 6) == p(6, "red") || a(0, 8) == p(8, "red")) ? str.append(" b' u' l") 
				: (n == 2 && (a(0, 2) == p(4, "red") || a(0, 4) == p(8, "red") || a(0, 8) == p(6, "red")) ? str.append(a(0, 2) == "red" ? " b r' b'" : " b r'")
				: (n == 2 && (a(0, 2) == p(8, "red") || a(0, 4) == p(6, "red") || a(0, 6) == p(4, "red")) ? str.append(a(0, 4) == "red" ? " d l' f l" : " d l' f") 
				: (n == 2 && (a(0, 2) == p(6, "red") || a(0, 6) == p(8, "red") || a(0, 8) == p(4, "red")) ? str.append(a(0, 2) == "red" ? " b' l b" : " b' l") 
				: (n == 2 ? str.append(" b' l") : str.append("")))));

				n == 4 && (a(0, 4) == p(8, "red") || a(0, 6) == p(2, "red") || a(0, 8) == p(6, "red")) ? str.append(" b' u' l") 
				: (n == 4 && (a(0, 2) == p(8, "red") || a(0, 4) == p(6, "red") || a(0, 8) == p(2, "red")) ? str.append(a(0, 2) == "red" ? " b r' b'" : " b r'")
				: (n == 4 && (a(0, 2) == p(6, "red") || a(0, 4) == p(2, "red") || a(0, 6) == p(8, "red")) ? str.append(a(0, 4) == "red" ? " d l' f l" : " d l' f") 
				: (n == 4 && (a(0, 2) == p(2, "red") || a(0, 6) == p(6, "red") || a(0, 8) == p(8, "red")) ? str.append(a(0, 2) == "red" ? " b' l b" : " b' l") 
				: (n == 4 ? str.append(" b' l") : str.append("")))));

				n == 6 && (a(0, 4) == p(2, "red") || a(0, 6) == p(8, "red") || a(0, 8) == p(4, "red")) ? str.append(" b u r'") 
				: (n == 6 && (a(0, 2) == p(2, "red") || a(0, 4) == p(4, "red") || a(0, 8) == p(8, "red")) ? str.append(a(0, 2) == "red" ? " b r' b'" : " b r'")
				: (n == 6 && (a(0, 2) == p(4, "red") || a(0, 4) == p(8, "red") || a(0, 6) == p(2, "red")) ? str.append(a(0, 4) == "red" ? " d l' f l" : " d l' f") 
				: (n == 6 && (a(0, 2) == p(8, "red") || a(0, 6) == p(4, "red") || a(0, 8) == p(2, "red")) ? str.append(a(0, 2) == "red" ? " b' l b" : " b' l") 
				: (n == 6 ? str.append(" b r'") : str.append("")))));

				n == 8 && (a(0, 4) == p(46, "red") || a(0, 6) == p(4, "red") || a(0, 8) == p(2, "red")) ? str.append(" b' u' l") 
				: (n == 8 && (a(0, 2) == p(6, "red") || a(0, 4) == p(2, "red") || a(0, 8) == p(4, "red")) ? str.append(a(0, 2) == "red" ? " b r' b'" : " b r'")
				: (n == 8 && (a(0, 2) == p(2, "red") || a(0, 4) == p(4, "red") || a(0, 6) == p(6, "red")) ? str.append(a(0, 4) == "red" ? " d l' f l" : " d l' f") 
				: (n == 8 && (a(0, 2) == p(4, "red") || a(0, 6) == p(2, "red") || a(0, 8) == p(6, "red")) ? str.append(a(0, 2) == "red" ? " b' l b" : " b' l") 
				: (n == 8 ? str.append(" b' l") : str.append("")))));
			}
			if(pos.position == 4)
			{
				n == 2 && (a(0, 2) == p(6, "red") || a(0, 6) == p(8, "red") || a(0, 8) == p(4, "red")) ? str.append(" l") 
				: (n == 2 && (a(0, 2) == p(8, "red") || a(0, 4) == p(6, "red") || a(0, 6) == p(4, "red")) ? str.append(" u l") 
				: (n == 2 && (a(0, 2) == p(4, "red") || a(0, 4) == p(8, "red") || a(0, 8) == p(6, "red")) ? str.append(" u2 l") 
				: (n == 2 && (a(0, 4) == p(4, "red") || a(0, 6) == p(6, "red") || a(0, 8) == p(8, "red")) ? str.append(" u' l") 
				: (n == 2 ? str.append(" l") : str.append("")))));

				n == 4 && (a(0, 2) == p(2, "red") || a(0, 6) == p(6, "red") || a(0, 8) == p(8, "red")) ? str.append(" l") 
				: (n == 4 && (a(0, 2) == p(6, "red") || a(0, 4) == p(2, "red") || a(0, 6) == p(8, "red")) ? str.append(" u l") 
				: (n == 4 && (a(0, 2) == p(8, "red") || a(0, 4) == p(6, "red") || a(0, 8) == p(2, "red")) ? str.append(" u2 l") 
				: (n == 4 && (a(0, 4) == p(8, "red") || a(0, 6) == p(2, "red") || a(0, 8) == p(6, "red")) ? str.append(" u' l") 
				: (n == 4 ? str.append(" l") : str.append("")))));

				n == 6 && (a(0, 2) == p(8, "red") || a(0, 6) == p(4, "red") || a(0, 8) == p(2, "red")) ? str.append(" l") 
				: (n == 6 && (a(0, 2) == p(4, "red") || a(0, 4) == p(8, "red") || a(0, 6) == p(2, "red")) ? str.append(" u l") 
				: (n == 6 && (a(0, 2) == p(2, "red") || a(0, 4) == p(4, "red") || a(0, 8) == p(8, "red")) ? str.append(" u2 l") 
				: (n == 6 && (a(0, 4) == p(2, "red") || a(0, 6) == p(8, "red") || a(0, 8) == p(4, "red")) ? str.append(" u' l") 
				: (n == 6 ? str.append(" l") : str.append("")))));

				n == 8 && (a(0, 2) == p(4, "red") || a(0, 6) == p(2, "red") || a(0, 8) == p(6, "red")) ? str.append(" l") 
				: (n == 8 && (a(0, 2) == p(2, "red") || a(0, 4) == p(4, "red") || a(0, 6) == p(6, "red")) ? str.append(" u l") 
				: (n == 8 && (a(0, 2) == p(6, "red") || a(0, 4) == p(2, "red") || a(0, 8) == p(4, "red")) ? str.append(" u2 l") 
				: (n == 8 && (a(0, 4) == p(6, "red") || a(0, 6) == p(4, "red") || a(0, 8) == p(2, "red")) ? str.append(" u' l") 
				: (n == 8 ? str.append(" l") : str.append("")))));
			}
			if(pos.position == 6)
			{
				n == 2 && (a(0, 2) == p(4, "red") || a(0, 4) == p(8, "red") || a(0, 8) == p(6, "red")) ? str.append(" r'") 
				: (n == 2 && (a(0, 2) == p(8, "red") || a(0, 4) == p(6, "red") || a(0, 6) == p(4, "red")) ? str.append(" u' r'") 
				: (n == 2 && (a(0, 2) == p(6, "red") || a(0, 6) == p(8, "red") || a(0, 8) == p(4, "red")) ? str.append(" u2 r'") 
				: (n == 2 && (a(0, 4) == p(4, "red") || a(0, 6) == p(6, "red") || a(0, 8) == p(8, "red")) ? str.append(" u r'") 
				: (n == 2 ? str.append(" r'") : str.append("")))));

				n == 4 && (a(0, 2) == p(8, "red") || a(0, 4) == p(6, "red") || a(0, 8) == p(2, "red")) ? str.append(" r'") 
				: (n == 4 && (a(0, 2) == p(6, "red") || a(0, 4) == p(2, "red") || a(0, 6) == p(8, "red")) ? str.append(" u' r'") 
				: (n == 4 && (a(0, 2) == p(2, "red") || a(0, 6) == p(6, "red") || a(0, 8) == p(8, "red")) ? str.append(" u2 r'") 
				: (n == 4 && (a(0, 4) == p(8, "red") || a(0, 6) == p(2, "red") || a(0, 8) == p(6, "red")) ? str.append(" u r'") 
				: (n == 4 ? str.append(" r'") : str.append("")))));

				n == 6 && (a(0, 2) == p(2, "red") || a(0, 4) == p(4, "red") || a(0, 8) == p(8, "red")) ? str.append(" r'") 
				: (n == 6 && (a(0, 2) == p(4, "red") || a(0, 4) == p(8, "red") || a(0, 6) == p(2, "red")) ? str.append(" u' r'") 
				: (n == 6 && (a(0, 2) == p(8, "red") || a(0, 6) == p(4, "red") || a(0, 8) == p(2, "red")) ? str.append(" u u r'") 
				: (n == 6 && (a(0, 4) == p(2, "red") || a(0, 6) == p(8, "red") || a(0, 8) == p(4, "red")) ? str.append(" u r'") 
				: (n == 6 ? str.append(" r'") : str.append("")))));

				n == 8 && (a(0, 2) == p(6, "red") || a(0, 4) == p(2, "red") || a(0, 8) == p(4, "red")) ? str.append(" r'") 
				: (n == 8 && (a(0, 2) == p(2, "red") || a(0, 4) == p(4, "red") || a(0, 6) == p(6, "red")) ? str.append(" u' r'") 
				: (n == 8 && (a(0, 2) == p(4, "red") || a(0, 6) == p(2, "red") || a(0, 8) == p(6, "red")) ? str.append(" u u r'") 
				: (n == 8 && (a(0, 4) == p(6, "red") || a(0, 6) == p(4, "red") || a(0, 8) == p(2, "red")) ? str.append(" u r'") 
				: (n == 8 ? str.append(" r'") : str.append("")))));
			}
			if(pos.position == 8)
			{
				n == 2 && (a(0, 4) == p(4, "red") || a(0, 6) == p(6, "red") || a(0, 8) == p(8, "red")) ? str.append(" b u' l") 
				: (n == 2 && (a(0, 4) == p(8, "red") || a(0, 8) == p(6, "red")) ? str.append(" b' r'") 
				: (n == 2 && (a(0, 6) == p(8, "red") || a(0, 8) == p(4, "red")) ? str.append(" b l") 
				: (n == 2 && (a(0, 4) == p(6, "red") || a(0, 6) == p(4, "red")) ? str.append(" b' u' r'") 
				: (n == 2 ? str.append(" b l") : str.append("")))));

				n == 4 && (a(0, 4) == p(8, "red") || a(0, 6) == p(2, "red") || a(0, 8) == p(6, "red")) ? str.append(" b u' l") 
				: (n == 4 && (a(0, 4) == p(6, "red") || a(0, 8) == p(2, "red")) ? str.append(" b' r'") 
				: (n == 4 && (a(0, 6) == p(6, "red") || a(0, 8) == p(8, "red")) ? str.append(" b l") 
				: (n == 4 && (a(0, 4) == p(2, "red") || a(0, 6) == p(8, "red")) ? str.append(" b u l") 
				: (n == 4 ? str.append(" b l") : str.append("")))));

				n == 6 && (a(0, 4) == p(2, "red") || a(0, 6) == p(8, "red") || a(0, 8) == p(4, "red")) ? str.append(" b' u r'") 
				: (n == 6 && (a(0, 4) == p(4, "red") || a(0, 8) == p(8, "red")) ? str.append(" b' r'") 
				: (n == 6 && (a(0, 6) == p(4, "red") || a(0, 8) == p(2, "red")) ? str.append(" b l") 
				: (n == 6 && (a(0, 4) == p(8, "red") || a(0, 6) == p(2, "red")) ? str.append(" b' u' r'") 
				: (n == 6 ? str.append(" b' r'") : str.append("")))));

				n == 8 && (a(0, 4) == p(6, "red") || a(0, 6) == p(4, "red") || a(0, 8) == p(2, "red")) ? str.append(" b u' l") 
				: (n == 8 && (a(0, 4) == p(2, "red") || a(0, 8) == p(4, "red")) ? str.append(" b' r'") 
				: (n == 8 && (a(0, 6) == p(2, "red") || a(0, 8) == p(6, "red")) ? str.append(" b l") 
				: (n == 8 && (a(0, 4) == p(4, "red") || a(0, 6) == p(6, "red")) ? str.append(" b u l")
				: (n == 8 ? str.append(" b l") : str.append("")))));
			}
		}
		if(pos.facet == 4)
		{
			if(pos.position == 2)
			{
				n == 2 && (a(0, 2) == p(4, "red") || a(0, 4) == p(8, "red") || a(0, 8) == p(6, "red")) ? str.append(" r u' b") 
				: (n == 2 && (a(0, 2) == p(8, "red") || a(0, 4) == p(6, "red")) ? str.append(" r' f'") 
				: (n == 2 && (a(0, 2) == p(6, "red") || a(0, 8) == p(6, "red")) ? str.append(" r u b") 
				: (n == 2 && (a(0, 4) == p(4, "red") || a(0, 8) == p(8, "red")) ? str.append(" r b") 
				: (n == 2 ? str.append(" r b") : str.append("")))));

				n == 4 && (a(0, 2) == p(8, "red") || a(0, 4) == p(6, "red") || a(0, 8) == p(2, "red")) ? str.append(" r u' b") 
				: (n == 4 && (a(0, 2) == p(6, "red") || a(0, 4) == p(2, "red")) ? str.append(" r' f'") 
				: (n == 4 && (a(0, 2) == p(2, "red") || a(0, 8) == p(8, "red")) ? str.append(" r' u' f'") 
				: (n == 4 && (a(0, 4) == p(8, "red") || a(0, 8) == p(6, "red")) ? str.append(" r b") 
				: (n == 4 ? str.append(" r b") : str.append("")))));

				n == 6 && (a(0, 2) == p(2, "red") || a(0, 4) == p(4, "red") || a(0, 8) == p(8, "red")) ? str.append(" r u' b") 
				: (n == 6 && (a(0, 2) == p(4, "red") || a(0, 4) == p(8, "red")) ? str.append(" r' f'") 
				: (n == 6 && (a(0, 2) == p(8, "red") || a(0, 8) == p(2, "red")) ? str.append(" r u b") 
				: (n == 6 && (a(0, 4) == p(2, "red") || a(0, 8) == p(4, "red")) ? str.append(" r b") 
				: (n == 6 ? str.append(" r b") : str.append("")))));

				n == 8 && (a(0, 2) == p(6, "red") || a(0, 4) == p(8, "red") || a(0, 8) == p(4, "red")) ? str.append(" r' u f'") 
				: (n == 8 && (a(0, 2) == p(2, "red") || a(0, 4) == p(4, "red")) ? str.append(" r' f'") 
				: (n == 8 && (a(0, 2) == p(4, "red") || a(0, 8) == p(6, "red")) ? str.append(" r' u' f'") 
				: (n == 8 && (a(0, 4) == p(6, "red") || a(0, 8) == p(2, "red")) ? str.append(" r b") 
				: (n == 8 ? str.append(" r' f'") : str.append("")))));
			}
			if(pos.position == 4)
			{
				n == 2 && (a(0, 2) == p(8, "red") || a(0, 4) == p(6, "red") || a(0, 6) == p(4, "red")) ? str.append(" f'") 
				: (n == 2 && (a(0, 2) == p(6, "red") || a(0, 6) == p(8, "red") || a(0, 8) == p(4, "red")) ? str.append(" u' f'") 
				: (n == 2 && (a(0, 4) == p(4, "red") || a(0, 6) == p(6, "red") || a(0, 8) == p(8, "red")) ? str.append(" u' u' f'") 
				: (n == 2 && (a(0, 2) == p(4, "red") || a(0, 4) == p(8, "red") || a(0, 8) == p(6, "red")) ? str.append(" u f'") 
				: (n == 2 ? str.append(" f'") : str.append("")))));

				n == 4 && (a(0, 2) == p(6, "red") || a(0, 4) == p(2, "red") || a(0, 6) == p(8, "red")) ? str.append(" f'") 
				: (n == 4 && (a(0, 2) == p(2, "red") || a(0, 6) == p(6, "red") || a(0, 8) == p(8, "red")) ? str.append(" u' f'") 
				: (n == 4 && (a(0, 4) == p(8, "red") || a(0, 6) == p(2, "red") || a(0, 8) == p(6, "red")) ? str.append(" u' u' f'") 
				: (n == 4 && (a(0, 2) == p(8, "red") || a(0, 4) == p(6, "red") || a(0, 8) == p(2, "red")) ? str.append(" u f'") 
				: (n == 4 ? str.append(" f'") : str.append("")))));

				n == 6 && (a(0, 2) == p(4, "red") || a(0, 4) == p(8, "red") || a(0, 6) == p(2, "red")) ? str.append(" f'") 
				: (n == 6 && (a(0, 2) == p(8, "red") || a(0, 6) == p(4, "red") || a(0, 8) == p(2, "red")) ? str.append(" u' f'") 
				: (n == 6 && (a(0, 4) == p(2, "red") || a(0, 6) == p(8, "red") || a(0, 8) == p(4, "red")) ? str.append(" u' u' f'") 
				: (n == 6 && (a(0, 2) == p(2, "red") || a(0, 4) == p(4, "red") || a(0, 8) == p(8, "red")) ? str.append(" u f'") 
				: (n == 6 ? str.append(" f'") : str.append("")))));

				n == 8 && (a(0, 2) == p(2, "red") || a(0, 4) == p(4, "red") || a(0, 6) == p(6, "red")) ? str.append(" f'") 
				: (n == 8 && (a(0, 2) == p(5, "red") || a(0, 6) == p(2, "red") || a(0, 8) == p(6, "red")) ? str.append(" u' f'") 
				: (n == 8 && (a(0, 4) == p(6, "red") || a(0, 6) == p(4, "red") || a(0, 8) == p(2, "red")) ? str.append(" u' u' f'") 
				: (n == 8 && (a(0, 2) == p(6, "red") || a(0, 4) == p(2, "red") || a(0, 8) == p(4, "red")) ? str.append(" u f'") 
				: (n == 8 ? str.append(" f'") : str.append("")))));
			}
			if(pos.position == 6)
			{
				n == 2 && (a(0, 4) == p(4, "red") || a(0, 6) == p(6, "red") || a(0, 8) == p(8, "red")) ? str.append(" b") 
				: (n == 2 && (a(0, 2) == p(4, "red") || a(0, 4) == p(8, "red") || a(0, 8) == p(6, "red")) ? str.append(" u' b") 
				: (n == 2 && (a(0, 2) == p(8, "red") || a(0, 4) == p(6, "red") || a(0, 6) == p(4, "red")) ? str.append(" u' u' b") 
				: (n == 2 && (a(0, 2) == p(6, "red") || a(0, 6) == p(8, "red") || a(0, 8) == p(4, "red")) ? str.append(" u b") 
				: (n == 2 ? str.append(" b") : str.append("")))));

				n == 4 && (a(0, 4) == p(8, "red") || a(0, 6) == p(2, "red") || a(0, 8) == p(6, "red")) ? str.append(" b") 
				: (n == 4 && (a(0, 2) == p(8, "red") || a(0, 4) == p(6, "red") || a(0, 8) == p(2, "red")) ? str.append(" u' b") 
				: (n == 4 && (a(0, 2) == p(6, "red") || a(0, 4) == p(2, "red") || a(0, 6) == p(8, "red")) ? str.append(" u' u' b") 
				: (n == 4 && (a(0, 2) == p(2, "red") || a(0, 6) == p(6, "red") || a(0, 8) == p(8, "red")) ? str.append(" u b") 
				: (n == 4 ? str.append(" b") : str.append("")))));

				n == 6 && (a(0, 4) == p(2, "red") || a(0, 6) == p(8, "red") || a(0, 8) == p(6, "red")) ? str.append(" b") 
				: (n == 6 && (a(0, 2) == p(2, "red") || a(0, 4) == p(4, "red") || a(0, 8) == p(8, "red")) ? str.append(" u' b") 
				: (n == 6 && (a(0, 2) == p(4, "red") || a(0, 4) == p(8, "red") || a(0, 6) == p(2, "red")) ? str.append(" u' u' b") 
				: (n == 6 && (a(0, 2) == p(8, "red") || a(0, 6) == p(4, "red") || a(0, 8) == p(2, "red")) ? str.append(" u b") 
				: (n == 6 ? str.append(" b") : str.append("")))));

				n == 8 && (a(0, 4) == p(6, "red") || a(0, 6) == p(4, "red") || a(0, 8) == p(2, "red")) ? str.append(" b") 
				: (n == 8 && (a(0, 2) == p(6, "red") || a(0, 4) == p(2, "red") || a(0, 8) == p(4, "red")) ? str.append(" u' b") 
				: (n == 8 && (a(0, 2) == p(2, "red") || a(0, 4) == p(4, "red") || a(0, 6) == p(6, "red")) ? str.append(" u' u' b") 
				: (n == 8 && (a(0, 2) == p(4, "red") || a(0, 6) == p(2, "red") || a(0, 8) == p(6, "red")) ? str.append(" u b") 
				: (n == 8 ? str.append(" b") : str.append("")))));
			}
			if(pos.position == 8)
			{
				n == 2 && (a(0, 2) == p(4, "red") || a(0, 4) == p(8, "red") || a(0, 8) == p(6, "red")) ? str.append(" r' u' b") 
				: (n == 2 && (a(0, 2) == p(8, "red") || a(0, 4) == p(6, "red") || a(0, 6) == p(4, "red")) ? str.append(a(0, 6) == "red" ? " r f' r'" : " r f'")
				: (n == 2 && (a(0, 2) == p(6, "red") || a(0, 6) == p(8, "red") || a(0, 8) == p(4, "red")) ? str.append(a(0, 2) == "red" ? " d b' l b" : " d b' l") 
				: (n == 2 && (a(0, 4) == p(4, "red") || a(0, 6) == p(6, "red") || a(0, 8) == p(8, "red")) ? str.append(a(0, 6) == "red" ? " r' b r" : " r' b") 
				: (n == 2 ? str.append(" r' b") : str.append("")))));

				n == 4 && (a(0, 2) == p(8, "red") || a(0, 4) == p(6, "red") || a(0, 8) == p(2, "red")) ? str.append(" r' u' b") 
				: (n == 4 && (a(0, 2) == p(6, "red") || a(0, 4) == p(2, "red") || a(0, 6) == p(8, "red")) ? str.append(a(0, 6) == "red" ? " r f' r'" : " r f'")
				: (n == 4 && (a(0, 2) == p(2, "red") || a(0, 6) == p(6, "red") || a(0, 8) == p(8, "red")) ? str.append(a(0, 2) == "red" ? " d b' l b" : " d b' l") 
				: (n == 4 && (a(0, 4) == p(8, "red") || a(0, 6) == p(2, "red") || a(0, 8) == p(6, "red")) ? str.append(a(0, 6) == "red" ? " r' b r" : " r' b") 
				: (n == 4 ? str.append(" r' b") : str.append("")))));

				n == 6 && (a(0, 2) == p(2, "red") || a(0, 4) == p(4, "red") || a(0, 8) == p(8, "red")) ? str.append(" r' u' b") 
				: (n == 6 && (a(0, 2) == p(4, "red") || a(0, 4) == p(8, "red") || a(0, 6) == p(2, "red")) ? str.append(a(0, 6) == "red" ? " r f' r'" : " r f'")
				: (n == 6 && (a(0, 2) == p(8, "red") || a(0, 6) == p(4, "red") || a(0, 8) == p(2, "red")) ? str.append(a(0, 2) == "red" ? " d b' l b" : " d b' l") 
				: (n == 6 && (a(0, 4) == p(2, "red") || a(0, 6) == p(8, "red") || a(0, 8) == p(4, "red")) ? str.append(a(0, 6) == "red" ? " r' b r" : " r' b") 
				: (n == 6 ? str.append(" r' b") : str.append("")))));

				n == 8 && (a(0, 2) == p(6, "red") || a(0, 4) == p(2, "red") || a(0, 8) == p(4, "red")) ? str.append(" r u f'") 
				: (n == 8 && (a(0, 2) == p(2, "red") || a(0, 4) == p(4, "red") || a(0, 6) == p(6, "red")) ? str.append(a(0, 6) == "red" ? " r f' r'" : " r f'")
				: (n == 8 && (a(0, 2) == p(4, "red") || a(0, 6) == p(2, "red") || a(0, 8) == p(6, "red")) ? str.append(a(0, 2) == "red" ? " d b' l b" : " d b' l")  
				: (n == 8 && (a(0, 4) == p(6, "red") || a(0, 6) == p(4, "red") || a(0, 8) == p(2, "red")) ? str.append(a(0, 6) == "red" ? " r' b r" : " r' b") 
				: (n == 8 ? str.append(" r' b") : str.append("")))));
			}
		}
		if(pos.facet == 5)//need cheack, such as other facets this need if
		{
			a.Turn_up("red", a(0, 2) == "red" ? 2 : (a(0, 4) == "red" ? 4 : (a(0, 6) == "red" ? 6 : 8)), a(0, 2) == "red" ? 2 : (a(0, 4) == "red" ? 4 : (a(0, 6) == "red" ? 6 : 8)), str);
			moves.append(str); Search(a, str);
			n == 2 ? (a.Turn_down("red", 2, 8, str), str.append(" b2")) : (n == 4 ? 
			(a.Turn_down("red", 4, 4, str), str.append(" l2")) : (n == 6 ? (a.Turn_down("red", 6, 6, str), str.append(" r2")) :
			(a.Turn_down("red", 8, 2, str), str.append(" f2"))));
		}
		moves.append(str); Search(a, str);
	}
	a.Turn_up("red", 2, 2, str);
	moves.append(str); Search(a, str);
	return 0;
}

int F2l(Model& a, string& moves)
{
	int n, m;
	Col temp;
	string str;
	Position pos_corner, pos_middle;
	moves.append("\nF2l:\n");
	if(a.top_facet != 5){ moves.append(" z2"); str = " z2"; Search(a, str);}
	int ind[4] = {7, 9, 3, 1};
	Col *color = new Col[4]; color[0] = "white"; color[0] = 4; color[1] = "green"; color[1] = 4; color[2] = "yellow"; color[2] = 6; color[3] = "blue"; color[3] = 4;
	cout << "=================" << endl;
	for(int i = 0; i < 4; i++)
	{
		pos_corner = a.Sequence(color, ind, pos_middle, n, m);
		cout << m << "   Pos_corner: " << pos_corner << "  ||  Pos_middle: " << pos_middle << endl;
		m == 7 ? temp(4, "white"): (m == 9 ? temp(4, "green") : (m == 3 ? temp(6, "yellow") : temp(4, "blue")));
		if(pos_middle.facet != 5 && (pos_middle.position == 4 && pos_middle.facet != (m == 7 ? 1 : (m == 9 ? 4 : (m == 3 ? 3 : 2))) && pos_middle.facet != (m == 1 ? 3 : 5) || 
		pos_middle.position == 6 && pos_middle.facet != (m == 7 ? 2 : (m == 9 ? 1 : (m == 3 ? 4 : 5)))))
		{ if(pos_corner.facet != 0) a.Turn_corners(pos_corner, (pos_middle.position == 4 ? (pos_middle.facet == 1 ? 1 : (pos_middle.facet == 2 ? 7 : (pos_middle.facet == 3 ? 7 : 3))) 
		: (pos_middle.facet == 1 ? 3 : (pos_middle.facet == 2 ? 1 : (pos_middle.facet == 3 ? 9 : 9)))), str); 
		a.Turn(pos_middle.facet != 3 ? (pos_middle.position == 4 ? pos_middle.facet : (pos_middle.facet == 1 ? 4 : pos_middle.facet - 1)) :
		(pos_middle.position == 6 ? pos_middle.facet : (pos_middle.facet == 1 ? 4 : pos_middle.facet - 1)), str); 
		str.append(" hell r u' r'"); moves.append(str); Search(a, str); pos_corner = a.Find_part("red", m); pos_middle = a.Find_part(temp);}
		if(pos_corner.facet != 0 && pos_corner.facet != 5 && (pos_corner.position == (pos_corner.facet == 3 ? 9 : 1) && pos_corner.facet != (m == 7 ? 1 : (m == 9 ? 4 : (m == 3 ? 3 : 2))) || 
		pos_corner.position == (pos_corner.facet == 3 ? 7 : 3) && pos_corner.facet != (m == 7 ? 2 : (m == 9 ? 1 : (m == 3 ? 4 : 3)))))
		{ a.Turn_md(pos_middle, (pos_corner.facet == 4 ? 1 : pos_corner.facet + 1), str, 1); 
		a.Turn(pos_corner.position == (pos_corner.facet == 3 ? 9 : 1) ? pos_corner.facet : (pos_corner.facet == 1 ? 4 : pos_corner.facet - 1), str); 
		str.append(" hello f' u' f"); moves.append(str); Search(a, str); pos_corner = a.Find_part("red", m); pos_middle = a.Find_part(temp);}
		if(pos_corner.facet == 0 && pos_corner.position != (m == 7 ? 7 : (m == 9 ? 9 : (m == 3 ? 3 : 1))))
		{ a.Turn_md(pos_middle, pos_corner.position == 7 ? 2 : (pos_corner.position == 9 ? 1 : (pos_corner.position == 3 ? 4 : 3)), str, 1);
		a.Turn(pos_corner.position == 7 ? 1 : (pos_corner.position == 9 ? 4 : (pos_corner.position == 3 ? 3 : 2)), str); 
		str.append(" holo f' u' f"); moves.append(str); Search(a, str); pos_corner = a.Find_part("red", m); pos_middle = a.Find_part(temp);}
		if(pos_corner.facet != 5 && (pos_corner.facet != 3 ? (pos_corner.position == 3 || pos_corner.position == 1) : (pos_corner.position == 9 || pos_corner.position == 7)) || pos_corner.facet == 0)	
			a.Turn_md(pos_middle, pos_middle.facet != 5 ? (m == 1 ? 2 : (m == 3 ? 3 : (m == 7 ? 1 : 4))) : (m == 1 ? 3 : (m == 3 ? 4 : (m == 7 ? 2 : 1))), str, pos_middle.facet == 5 ? 2 : 0);
		if(pos_corner.facet == 5)
			a.Turn_md(pos_middle, pos_middle.facet != 5 ? (m == 1 ? 2 : (m == 3 ? 3 : (m == 7 ? 1 : 4))) : (m == 1 ? 3 : (m == 3 ? 4 : (m == 7 ? 2 : 1))), str, pos_middle.facet == 5 ? 2 : 0);
		else str = a.Turn_corners(pos_corner, pos_middle, m);
		a.Turn(n, str); moves.append(str); Search(a, str);
		pos_corner = a.Find_part("red", m);
		pos_middle = a.Find_part(temp);
		cout << m << "   Pos_corner: " << pos_corner << "  ||  Pos_middle: " << pos_middle << endl;
		if(pos_corner.facet != 5)
		{
			if(pos_corner.position == (pos_corner.facet == 3 ? 1 : 9) && pos_middle.facet == (pos_corner.facet == 1 ? 4 : pos_corner.facet - 1) && pos_middle.position == (pos_middle.facet == 3 ? 2 : 8))
			{ str = " f r' f' r";}
			if(pos_corner.position == (pos_corner.facet == 3 ? 3 : 7) && pos_middle.facet == 5 && pos_middle.position == (m == 7 ? 4 : (m == 9 ? 2 : (m == 3 ? 6 : 8))))
			{ str = " u r u' r'";}
			if(pos_corner.position == (pos_corner.facet == 3 ? 3 : 7) && pos_middle.facet == (pos_corner.facet == 1 ? 4 : pos_corner.facet - 1) && pos_middle.position == (pos_middle.facet == 3 ? 2 : 8))
			{ str = " f' u' f";}
			if(pos_corner.position == (pos_corner.facet == 3 ? 1 : 9) && pos_middle.facet == 5 && pos_middle.position == (m == 7 ? 8 : (m == 9 ? 4 : (m == 3 ? 2 : 6))))
			{ str = " r u r'";}
			if(pos_corner.position == (pos_corner.facet == 3 ? 1 : 9) && pos_middle.facet == (pos_corner.facet == 4 ? 2 : (pos_corner.facet == 3 ? 1 : pos_corner.facet + 2)) && pos_middle.position == (pos_middle.facet == 3 ? 2 : 8))
			{ str = " y' u r' u' r u r' u2 r";}
			if(pos_corner.position == (pos_corner.facet == 3 ? 3 : 7) && pos_middle.facet == 5 && pos_middle.position == (m == 7 ? 8 : (m == 9 ? 4 : (m == 3 ? 2 : 6))))
			{ str = " u' r u r' u2 r u' r'";}
			if(pos_corner.position == (pos_corner.facet == 3 ? 1 : 9) && pos_middle.facet == (pos_corner.facet == 4 ? 1 : pos_corner.facet + 1) && pos_middle.position == (pos_middle.facet == 3 ? 2 : 8))
			{ str = " y' u r' u2 r u r' u2 r";}
			if(pos_corner.position == (pos_corner.facet == 3 ? 3 : 7) && pos_middle.facet == 5 && pos_middle.position == (m == 7 ? 6 : (m == 9 ? 8 : (m == 3 ? 4 : 2))))
			{ str = " u' r u2 r' u2 r u' r'";}
			if(pos_corner.position == (pos_corner.facet == 3 ? 3 : 7) && pos_middle.facet == (pos_corner.facet == 4 ? 2 : (pos_corner.facet == 3 ? 1 : pos_corner.facet + 2)) && pos_middle.position == (pos_middle.facet == 3 ? 2 : 8))
			{ str = " u' r u' r' u f' u' f";}
			if(pos_corner.position == (pos_corner.facet == 3 ? 1 : 9) && pos_middle.facet == 5 && pos_middle.position == (m == 7 ? 6 : (m == 9 ? 8 : (m == 3 ? 4 : 2))))
			{ str = " u' r u r' u r u r'";}
			if(pos_corner.position == (pos_corner.facet == 3 ? 3 : 7) && pos_middle.facet == (pos_corner.facet == 4 ? 1 : pos_corner.facet + 1) && pos_middle.position == (pos_middle.facet == 3 ? 2 : 8))
			{ str = " y' r u2 r2 u' r2 u' r'";}
			if(pos_corner.position == (pos_corner.facet == 3 ? 1 : 9) && pos_middle.facet == 5 && pos_middle.position == (m == 7 ? 2 : (m == 9 ? 6 : (m == 3 ? 8 : 4))))
			{ str = " r' u2 r2 u r2 u r";}
			if(pos_corner.position == (pos_corner.facet == 3 ? 3 : 7) && pos_middle.facet == pos_corner.facet && pos_middle.position == (pos_middle.facet == 3 ? 2 : 8))
			{ str = " y' u r' u r u' r' u' r";}
			if(pos_corner.position == (pos_corner.facet == 3 ? 1 : 9) && pos_middle.facet == 5 && pos_middle.position == (m == 7 ? 4 : (m == 9 ? 2 : (m == 3 ? 6 : 8))))
			{ str = " u' r u' r' u r u r'";}
			if(pos_corner.position == (pos_corner.facet == 3 ? 1 : 9) && pos_middle.facet == pos_corner.facet && pos_middle.position == (pos_middle.facet == 3 ? 2 : 8))
			{ str = " u f u r u' r' f' r u r'";}
			if(pos_corner.position == (pos_corner.facet == 3 ? 3 : 7) && pos_middle.facet == 5 && pos_middle.position == (m == 7 ? 2 : (m == 9 ? 6 : (m == 3 ? 8 : 4))))
			{ str = " r u r' u2 r u' r' u r u' r'";}
			if(pos_corner.position == (pos_corner.facet == 3 ? 7 : 3) && pos_middle.facet == (pos_corner.facet == 1 ? 4 : pos_corner.facet - 1) && pos_middle.position == (pos_middle.facet == 3 ? 2 : 8))
			{ str = " r u r' u' f r' f' r";}
			if(pos_corner.position == (pos_corner.facet == 3 ? 9 : 1) && pos_middle.facet == 5 && pos_middle.position == (m == 7 ? 4 : (m == 9 ? 2 : (m == 3 ? 6 : 8))))
			{ str = " r u' r' u r u' r'";}
			if(pos_corner.position == (pos_corner.facet == 3 ? 9 : 1) && pos_middle.facet == pos_corner.facet && pos_middle.position == (pos_middle.facet == 3 ? 2 : 8))
			{ str = " y l' u' l u l' u' l";}
			if(pos_corner.position == (pos_corner.facet == 3 ? 7 : 3) && pos_middle.facet == 5 && pos_middle.position == (m == 7 ? 4 : (m == 9 ? 2 : (m == 3 ? 6 : 8))))
			{ str = " r u r' u' r u r'";}
			if(pos_corner.position == (pos_corner.facet == 3 ? 3 : 7) && pos_middle.facet == pos_corner.facet && pos_middle.position == (pos_middle.facet == 3 ? 6 : 4))
			{ str = " u' r u' r' u2 r u' r'";}
			if(pos_corner.position == (pos_corner.facet == 3 ? 1 : 9) && pos_middle.facet == (pos_corner.facet == 1 ? 4 : pos_corner.facet - 1) && pos_middle.position == (pos_middle.facet == 3 ? 6 : 4))
			{ str = " u' r u2 r' u r u r'";}
			if(pos_corner.position == (pos_corner.facet == 3 ? 3 : 7) && pos_middle.facet == (pos_corner.facet == 1 ? 4 : pos_corner.facet - 1) && pos_middle.position == (pos_middle.facet == 3 ? 4 : 6))
			{ str = " u2 r u r' y u' l' u l";}
			if(pos_corner.position == (pos_corner.facet == 3 ? 1 : 9) && pos_middle.facet == pos_corner.facet && pos_middle.position == (pos_middle.facet == 3 ? 4 : 6))
			{ str = " u f' u' f u' r u r'";}
			if(pos_corner.position == (pos_corner.facet == 3 ? 9 : 1) && pos_middle.facet == pos_corner.facet && pos_middle.position == (pos_middle.facet == 3 ? 6 : 4))
			{ str = " r u' r' u' r u r' u2 r u' r'";}
			if(pos_corner.position == (pos_corner.facet == 3 ? 7 : 3) && pos_middle.facet == (pos_corner.facet == 4 ? 1 : pos_corner.facet - 1) && pos_middle.position == (pos_middle.facet == 3 ? 6 : 4))
			{ str = " r u2 r u r' u r u2 r2";}
			if(pos_corner.position == (pos_corner.facet == 3 ? 9 : 1) && pos_middle.facet == (pos_corner.facet == 1 ? 4 : pos_corner.facet + 1) && pos_middle.position == (pos_middle.facet == 3 ? 4 : 6))
			{ str = " r f u r u' r' f' u' r'";}
			if(pos_corner.position == (pos_corner.facet == 3 ? 7 : 3) && pos_middle.facet == pos_corner.facet && pos_middle.position == (pos_middle.facet == 3 ? 4 : 6))
			{ str = " y f r u2 r' f' l' u' l";}
		}
		if(pos_corner.facet == 5)
		{
			if(pos_corner.position == (m == 7 ? 1 : (m == 9 ? 3 : (m == 3 ? 9 : 7))) && pos_middle.facet == (m == 7 ? 1 : (m == 9 ? 4 : (m == 3 ? 3 : 2))) && pos_middle.position == (pos_middle.facet == 3 ? 2 : 8))
			{ str = " y' r' u2 r u r' u' r";}
			if(pos_corner.position == (m == 7 ? 1 : (m == 9 ? 3 : (m == 3 ? 9 : 7))) && pos_middle.facet == 5 && pos_middle.position == (m == 7 ? 4 : (m == 9 ? 2 : (m == 3 ? 6 : 8))))
			{ str = " r u2 r' u' r u r'";}
			if(pos_corner.position == (m == 7 ? 7 : (m == 9 ? 1 : (m == 3 ? 3 : 9))) && pos_middle.facet == (m == 7 ? 1 : (m == 9 ? 4 : (m == 3 ? 3 : 2))) && pos_middle.position == (pos_middle.facet == 3 ? 2 : 8))
			{ str = " r u' r2 f r f' r u' r'";}
			if(pos_corner.position == (m == 7 ? 3 : (m == 9 ? 9 : (m == 3 ? 7 : 1))) && pos_middle.facet == 5 && pos_middle.position == (m == 7 ? 4 : (m == 9 ? 2 : (m == 3 ? 6 : 8))))
			{ str = " r u2 r' u r u' r'";}
			if(pos_corner.position == (m == 7 ? 9 : (m == 9 ? 7 : (m == 3 ? 1 : 3))) && pos_middle.facet == (m == 7 ? 1 : (m == 9 ? 4 : (m == 3 ? 3 : 2))) && pos_middle.position == (pos_middle.facet == 3 ? 2 : 8))
			{ str = " r u r' f' u' f";}
			if(pos_corner.position == (m == 7 ? 9 : (m == 9 ? 7 : (m == 3 ? 1 : 3))) && pos_middle.facet == 5 && pos_middle.position == (m == 7 ? 4 : (m == 9 ? 2 : (m == 3 ? 6 : 8))))
			{ str = " r u r' u r u' r'";}
			if(pos_corner.position == (m == 7 ? 1 : (m == 9 ? 3 : (m == 3 ? 9 : 7))) && pos_middle.facet == (m == 7 ? 2 : (m == 9 ? 1 : (m == 3 ? 4 : 3))) && pos_middle.position == (pos_middle.facet == 3 ? 2 : 8))
			{ str = " f u r u' r' f' r u' r'";}
			if(pos_corner.position == (m == 7 ? 1 : (m == 9 ? 3 : (m == 3 ? 9 : 7))) && pos_middle.facet == 5 && pos_middle.position == (m == 7 ? 2 : (m == 9 ? 6 : (m == 3 ? 8 : 4))))
			{ str = " r u' r' u r u2 r' u r u r'";}
			if(pos_corner.position == (m == 7 ? 1 : (m == 9 ? 3 : (m == 3 ? 9 : 7))) && pos_middle.facet == (m == 7 ? 1 : (m == 9 ? 4 : (m == 3 ? 3 : 2))) && pos_middle.position == (pos_middle.facet == 3 ? 6 : 4))
			{ str = " r u r' u' r u r' u' r u r'";}
			if(pos_corner.position == (m == 7 ? 1 : (m == 9 ? 3 : (m == 3 ? 9 : 7))) && pos_middle.facet == (m == 7 ? 2 : (m == 9 ? 1 : (m == 3 ? 4 : 3))) && pos_middle.position == (pos_middle.facet == 3 ? 4 : 6))
			{ str = " u r u2 r' f' u' f";}
		}
		if(pos_corner.facet == 0)
		{
			if(pos_middle.facet == (m == 7 ? 1 : (m == 9 ? 4 : (m == 3 ? 3 : 2))) && pos_middle.position == (pos_middle.facet == 3 ? 2 : 8))
			{ str = " u r u' r' f r' f' r";}
			if(pos_middle.facet == 5 && pos_middle.position == (m == 7 ? 4 : (m == 9 ? 2 : (m == 3 ? 6 : 8))))
			{ str = " r' f' r u r u' r' f";}
			if(pos_middle.facet == (m == 7 ? 2 : (m == 9 ? 1 : (m == 3 ? 4 : 3))) && pos_middle.position == (pos_middle.facet == 3 ? 4 : 6))
			{ str = " r u' r' u y' r' u2 r u2 r' u r";}
		}//40 + 1
		str.append(" ||");
		moves.append(str); Search(a, str);
	}
	return 0;
}

Position Model::Sequence(Col* color, int* ind, Position& pos, int& n, int& m)
{
	int facet[4] = {1, 4, 3, 2};
	Position pos_corner, pos_middle;
	for(int i = 0; i < 8;)
	{
		if(color[i] == 0)
			while(color[++i] == 0 && i < 4);
		if(i >= 4)
			for(int i = 0; i < 4; i++){ if(color[i].ind != 0 && Check_part("red", ind[i])){ pos = Find_part(color[i]); pos_corner = Find_part("red", ind[i]); color[i] = 0; m = ind[i]; n = facet[i]; return pos_corner;}}
		pos_middle = Find_part(color[i]);//change previous for() or add new if to check if() all are taught situations
		pos_corner = Find_part("red", ind[i]);
		if(pos_middle.position == 4 || pos_middle.position == 6 && (pos_corner.facet == 0 ? pos_corner.position == ind[i] : 1))
		{
			if(color[i].col == "white" && (pos_middle.position == 4 && pos_middle.facet == 1 || pos_middle.position == 6 && pos_middle.facet == 2) && Check_part("red", ind[i]))
			{ pos = pos_middle; color[i] = 0; m = ind[i]; n = facet[i]; return pos_corner;}
			if(color[i].col == "green" && (pos_middle.position == 6 && pos_middle.facet == 1 || pos_middle.position == 4 && pos_middle.facet == 4) && Check_part("red", ind[i]))
			{ pos = pos_middle; color[i] = 0; m = ind[i]; n = facet[i]; return pos_corner;}
			if(color[i].col == "yellow" && (pos_middle.position == 6 && pos_middle.facet == 3 || pos_middle.position == 6 && pos_middle.facet == 4) && Check_part("red", ind[i]))
			{ pos = pos_middle; color[i] = 0; m = ind[i]; n = facet[i]; return pos_corner;}
			if(color[i].col == "blue" && (pos_middle.position == 4 && pos_middle.facet == 2 || pos_middle.position == 4 && pos_middle.facet == 3) && Check_part("red", ind[i]))
			{ pos = pos_middle; color[i] = 0; m = ind[i]; n = facet[i]; return pos_corner;}
			if(pos_middle.facet == 5 && Check_part("red", ind[i]))
			{ pos = pos_middle; color[i] = 0; m = ind[i]; n = facet[i]; return pos_corner;}
		}
		if((pos_middle.position == 8 || pos_middle.position == 2) && Check_part("red", ind[i]))
		{ pos = pos_middle; color[i] = 0; m = ind[i]; n = facet[i]; return pos_corner;}
		i++;
	}
	return pos_corner;
}

bool Model::p(int i)
{
	return Matr[5].color[i - 1] != "orange";
}

int OLL(Model& a, string& moves)
{
	int i = 0;
	string str;
	vector<int> pos;
	moves.append("\nOll:\n");
	if(a.top_facet != 5){ moves.append(" z2"); str = " z2"; Search(a, str);}
	a.current_facet == 4 ? str = " y" : (a.current_facet == 3 ? str = " y2" : (a.current_facet == 2 ? str = " y'" : str = ""));
	moves.append(str); Search(a, str);
	for(int i = 1; i < 10; i++){ if(!(a(5, i) == "orange")) pos.push_back(i);}
	for(; i < 4 && str.empty(); i++)
	{
		if(pos.size() == 2)
		{
			if(a.p(7) && a.p(9) && a(3, 1) == "orange" && a(3, 3) == "orange") 
			{ str = " r2 d' r u2 r' d u2 r";}
			if(a.p(7) && a.p(9) && a(4, 9) == "orange" && a(2, 7) == "orange")
			{ str = " r u r d r' u' r d' r2";}
			if(a.p(3) && a.p(7) && a(3, 1) == "orange")
			{ str = " r2 d' r u' r' d r u r";}
			if(a.p(2) && a.p(8))
			{ str = " r u r' u' m' u r u' rw'";}
			if(a.p(2) && a.p(4))
			{ str = " rw u r' u' rw' r u r u' r'";}
		}
		if(pos.size() == 3)
		{
			if(a.p(1) && a.p(7) && a.p(9) && a(1, 7) == "orange" && a(2, 7) == "orange")
			{ str = " r u r' u r u2 r'";}
			if(a.p(3) && a.p(7) && a.p(9) && a(4, 9) == "orange" && a(1, 9) == "orange")
			{ str = " l' u' l u' l' u2 l";}
		}
		if(pos.size() == 4)
		{
			if(a.p(1) && a.p(3) && a.p(7) && a.p(9) && a(2, 7) == "orange" && a(4, 9) == "orange") 
			{ str = " r u r' u r u' r' u r u2 r'";}
			if(a.p(1) && a.p(3) && a.p(7) && a.p(9) && a(1, 7) == "orange" && a(4, 7) == "orange")
			{ str = " r u2 r2 u' r2 u' r2 u2 r";}
			if(a.p(2) && a.p(4) && a.p(6) && a.p(8))
			{ str = " rw u r' u' m2 u r u' r' u' m'";}
			if(a.p(2) && a.p(3) && a.p(8) && a.p(9) && a(4, 7) == "orange" && a(4, 9) == "orange")
			{ str = " f r u r' u' f'";}
			if(a.p(2) && a.p(3) && a.p(8) && a.p(9) && a(1, 9) == "orange" && a(3, 3) == "orange")
			{ str = " r u r' u' r' f r f'";}
			if(a.p(2) && a.p(7) && a.p(8) && a.p(9) && a(4, 9) == "orange" && a(2, 7) == "orange")
			{ str = " r u r2 u' r' f r u r u' f'";}
			if(a.p(2) && a.p(7) && a.p(8) && a.p(9) && a(3, 1) == "orange" && a(3, 3) == "orange")
			{ str = " y r' u' r' f r f' u r";}
			if(a.p(2) && a.p(3) && a.p(7) && a.p(8) && a(3, 1) == "orange" && a(3, 2) == "orange")
			{ str = " r' f r u r' u' f' u r";}
			if(a.p(1) && a.p(2) && a.p(8) && a.p(9) && a(3, 2) == "orange" && a(3, 3) == "orange")
			{ str = " l f' l' u' l u f u' l'";}
			if(a.p(1) && a.p(4) && a.p(7) && a.p(8) && a(2, 7) == "orange" && a(2, 9) == "orange")
			{ str = " b' u' r' u r b";}
			if(a.p(1) && a.p(4) && a.p(7) && a.p(8) && a(1, 7) == "orange" && a(3, 1) == "orange")
			{ str = " r' f r u r' u' f2 u f r";}
			if(a.p(3) && a.p(6) && a.p(8) && a.p(9) && a(4, 7) == "orange" && a(4, 9) == "orange")
			{ str = " fw r u r' u' fw'";}
			if(a.p(3) && a.p(6) && a.p(8) && a.p(9) && a(1, 9) == "orange" && a(3, 3) == "orange")
			{ str = " r u b' u' r' u r b r'";}
			if(a.p(1) && a.p(2) && a.p(4) && a.p(9) && a(3, 3) == "orange" && a(2, 9) == "orange")
			{ str = " r u r' u r u' r' u' r' f r f'";}
			if(a.p(2) && a.p(3) && a.p(6) && a.p(7) && a(3, 1) == "orange" && a(4, 7) == "orange")
			{ str = " l' u' l u' l' u l u rw u' rw' f";}
			if(a.p(2) && a.p(3) && a.p(4) && a.p(7) && a(3, 1) == "orange" && a(4, 7) == "orange")
			{ str = " y r' u' f r' f' r2 u' r' u2 r";}
			if(a.p(2) && a.p(3) && a.p(4) && a.p(7) && a(1, 9) == "orange" && a(2, 7) == "orange")
			{ str = " f r' f' r u r u' r'";}
			if(a.p(1) && a.p(3) && a.p(6) && a.p(8) && a(1, 7) == "orange" && a(1, 9) == "orange")
			{ str = " r u' r' u2 r u b u' b' u' r'";}
			if(a.p(1) && a.p(3) && a.p(6) && a.p(8) && a(4, 7) == "orange" && a(2, 9) == "orange")
			{ str = " fw r u r2 u' r' u r2 u' r' fw'";}
			if(a.p(1) && a.p(3) && a.p(4) && a.p(8) && a(1, 9) == "orange" && a(1, 9) == "orange")
			{ str = " r' u' r u' r' u2 r f r u r' u' f'";}
			if(a.p(1) && a.p(3) && a.p(4) && a.p(8) && a(4, 7) == "orange" && a(2, 9) == "orange")
			{ str = " m u r u r' u' r' f r f' m'";}
		}
		if(pos.size() == 5)
		{
			if(!a.p(4) && !a.p(6) && !a.p(7) && a(2, 9) == "orange" && a(4, 9) == "orange")
			{ str = " rw u rw' r u r' u' rw u' rw'";}
			if(!a.p(4) && !a.p(6) && !a.p(7) && a(1, 7) == "orange" && a(3, 3) == "orange") 
			{ str = " fw r u r2 u' r' u r u' fw'";}
			if(!a.p(4) && !a.p(6) && !a.p(9) && a(2, 7) == "orange" && a(4, 7) == "orange")
			{ str = " lw' u' lw l' u' l u r' f r";}
			if(!a.p(4) && !a.p(6) && !a.p(9) && a(1, 9) == "orange" && a(3, 1) == "orange")
			{ str = " rw' u rw u rw' u' rw b u' b'";}
			if(!a.p(4) && !a.p(7) && !a.p(8) && a(2, 9) == "orange" && a(4, 9) == "orange")
			{ str = " rw u2 r' u' r u' rw'";}
			if(!a.p(6) && !a.p(8) && !a.p(9) && a(2, 7) == "orange" && a(4, 7) == "orange")
			{ str = " r' f2 rw u rw' f r";}
			if(!a.p(3) && !a.p(4) && !a.p(8) && a(1, 7) == "orange" && a(2, 7) == "orange")
			{ str = " rw u r' u r u' r' u' rw' r u r u' r'";}
			if(!a.p(1) && !a.p(6) && !a.p(8) && a(3, 1) == "orange" && a(4, 9) == "orange")
			{ str = " r u r' u' f r2 u r' u' f'";}
			if(!a.p(3) && !a.p(6) && !a.p(8) && a(1, 7) == "orange" && a(3, 3) == "orange")
			{ str = " rw u r' u r u2 rw'";}
			if(!a.p(3) && !a.p(6) && !a.p(8) && a(2, 9) == "orange" && a(4, 9) == "orange")
			{ str = " y rw r2 u' r u' r' u2 r u' rw' r";}
			if(!a.p(1) && !a.p(4) && !a.p(8) && a(1, 9) == "orange" && a(4, 9) == "orange")
			{ str = " r u2 r' u2 r' f r f'";}
			if(!a.p(1) && !a.p(4) && !a.p(8) && a(2, 7) == "orange" && a(4, 7) == "orange")
			{ str = " rw r' u r u r' u r u2 r' u rw' r";}
		}
		if(pos.size() == 6)
		{
			if(!a.p(7) && !a.p(9) && a(2, 9) == "orange" && a(4, 7) == "orange")
			{ str = " rw' r u r u r' u' rw r2 f r f'";}
			if(!a.p(7) && !a.p(9) && a(1, 7) == "orange" && a(1, 9) == "orange")
			{ str = " rw u r' u r u2 rw2 u' r u' r' u2 rw";}
			if(!a.p(1) && !a.p(9) && a(5, 1) == "orange" && a(5, 9) == "orange")
			{ str = " r u r' u r' f r f' u2 r' f r f'";}
			if(!a.p(4) && !a.p(6) && a(3, 3) == "orange" && a(2, 7) == "orange")
			{ str = " f u r u' r' u r u' r' f'";}
			if(!a.p(4) && !a.p(6) && a(2, 7) == "orange" && a(4, 9) == "orange")
			{ str = " rw u rw' u r u' r' u r u' r' rw u' rw'";}
			if(!a.p(4) && !a.p(6) && a(3, 3) == "orange" && a(2, 9) == "orange")
			{ str = " f r u r' u y' r' u' r u' r'";}
			if(!a.p(4) && !a.p(6) && a(3, 1) == "orange" && a(1, 7) == "orange")
			{ str = " y r u2 r2 u' r u' r' u2 f r f'";}
			if(!a.p(4) && !a.p(8) && a(3, 3) == "orange" && a(3, 1) == "orange" && a(4, 7) == "orange")
			{ str = " y fw u r u' r' u r u' r' fw'";}
			if(!a.p(4) && !a.p(8) && a(3, 3) == "orange" && a(3, 1) == "orange" && a(1, 7) == "orange")
			{ str = " y rw' u' r u' r' u r u' r' u2 rw";}
			if(!a.p(4) && !a.p(8) && a(3, 3) == "orange" && a(2, 7) == "orange" && a(2, 9) == "orange")
			{ str = " f' l' u' l u l' u' l u f";}
			if(!a.p(4) && !a.p(8) && a(4, 7) == "orange" && a(2, 7) == "orange" && a(2, 9) == "orange")
			{ str = " rw u r' u r u' r' u r u2 rw'";}
			if(!a.p(4) && !a.p(8) && a(4, 7) == "orange" && a(3, 1) == "orange" && a(1, 7) == "orange")
			{ str = " rw u' rw2 u rw2 u rw2 u' rw";}
			if(!a.p(4) && !a.p(8) && a(4, 9) == "orange" && a(2, 7) == "orange" && a(1, 7) == "orange")
			{ str = " f' r u2 r' u2 r' f2 r f'";}
		}
		if(pos.size() == 7)
		{
			if(!a.p(3) && a(1, 7) == "orange" && a(2, 7) == "orange")
			{ str = " rw' r u r' f2 r u l' u l rw r'";}
			if(!a.p(1) && a(4, 9) == "orange" && a(1, 9) == "orange")
			{ str = " rw' r u' rw u2 rw' u' r u' r2 rw";}
		}
		if(pos.size() == 8)
		{ 
			if(a(2, 9) == "orange" && a(4, 7) == "orange")
			{ str = " r u b' r b r2 u' r' f r f'";}
			if(a(1, 7) == "orange" && a(4, 9) == "orange" && a(3, 1) == "orange")
			{ str = " rw' u' rw r' u' r u' r' u r u2 rw' u rw";}
		}
		if(str.empty()){ str = "u"; Search(a, str);}
		else break;
	}
	i == 4 ? moves.append("") : (i == 3 ? moves.append(" u'") : (i == 2 ? moves.append(" u2") : (i == 1 ? moves.append(" u") : moves.append(""))));
	moves.append(str); Search(a, str);
	return 0;
}

int PLL(Model& a, string& moves)
{
	int pos;
	int count;
	string str;
	Data(a, pos, count);
	moves.append("\nPll:\n");
	if(a.top_facet != 5){ moves.append(" z2"); str = " z2"; Search(a, str);}
	pos % 2 == 0 ? a.Turn_up(pos, pos, str) : a.Turn_corners("orange", pos, pos, str);
	moves.append(str); Search(a, str);

	if(a.Check(9, 2, 3, 4, 5, 6, 1, 8, 7))
	{ a.Facet(" y", " y2", " y'", "", str); str.append(" lw' u r' d2 r u' r' d2 r2");}
	if(a.Check(1, 2, 9, 4, 5, 6, 3, 8, 7))
	{ a.Facet(" y2", " y'", "", " y", str); str.append(" lw' u r' d2 r u' r' d2 r2");}
	if(a.Check(3, 2, 9, 4, 5, 6, 7, 8, 1))
	{ a.Facet(" y'", "", " y", " y2", str); str.append(" lw' u r' d2 r u' r' d2 r2");}
	if(a.Check(3, 2, 7, 4, 5, 6, 1, 8, 9))
	{ a.Facet("", " y", " y2", " y'", str); str.append(" lw' u r' d2 r u' r' d2 r2");}
	
	if(a.Check(7, 2, 3, 4, 5, 6, 9, 8, 1))
	{ a.Facet(" y2", " y'", "", " y", str); str.append(" lw u' r d2 r' u r d2 r2");}
	if(a.Check(1, 2, 7, 4, 5, 6, 9, 8, 3))
	{ a.Facet(" y'", "", " y", " y2", str); str.append(" lw u' r d2 r' u r d2 r2");}
	if(a.Check(9, 2, 1, 4, 5, 6, 7, 8, 3))
	{ a.Facet("", " y", " y2", " y'", str); str.append(" lw u' r d2 r' u r d2 r2");}
	if(a.Check(7, 2, 1, 4, 5, 6, 3, 8, 9))
	{ a.Facet(" y", " y2", " y'", "", str); str.append(" lw u' r d2 r' u r d2 r2");}

	if(a.Check(7, 2, 9, 4, 5, 6, 1, 8, 3))
	{ a.Facet(" y", " y2", " y'", "", str); str.append(" r' u' r' d' r u' r' d r u r' d' r u r' d r2");}
	if(a.Check(3, 2, 1, 4, 5, 6, 9, 8, 7))
	{ a.Facet(" y2", " y'", "", " y", str); str.append(" r' u' r' d' r u' r' d r u r' d' r u r' d r2");}

	if(a.Check(1, 4, 3, 2, 5, 8, 7, 6, 9))
	{ a.Facet(" y", " y2", " y'", "", str); str.append(" u' m' u m2 u m2 u m' u2 m2");}
	if(a.Check(1, 6, 3, 8, 5, 2, 7, 4, 9))
	{ a.Facet(" y2", " y'", "", " y", str); str.append(" u' m' u m2 u m2 u m' u2 m2");}

	if(a.Check(1, 8, 3, 6, 5, 4, 7, 2, 9))
	{ a.Facet(" y", " y2", " y'", "", str); str.append(" m2 u' m2 u2 m2 u' m2");}

	if(a.Check(1, 4, 3, 6, 5, 2, 7, 8, 9))
	{ a.Facet(" y", " y2", " y'", "", str); str.append(" m2 u m u2 m' u m2");}
	if(a.Check(1, 4, 3, 8, 5, 6, 7, 1, 9))
	{ a.Facet(" y2", " y'", "", " y", str); str.append(" m2 u m u2 m' u m2");}
	if(a.Check(1, 2, 3, 8, 5, 4, 7, 6, 9))
	{ a.Facet(" y'", "", " y", " y2", str); str.append(" m2 u m u2 m' u m2");}
	if(a.Check(1, 8, 3, 4, 5, 2, 7, 6, 9))
	{ a.Facet("", " y", " y2", " y'", str); str.append(" m2 u m u2 m' u m2");}

	if(a.Check(1, 6, 3, 2, 5, 4, 7, 8, 9))
	{ a.Facet(" y", " y2", " y'", "", str); str.append(" m2 u' m u2 m' u' m2");}
	if(a.Check(1, 8, 3, 2, 5, 6, 7, 4, 9))
	{ a.Facet(" y2", " y'", "", " y", str); str.append(" m2 u' m u2 m' u' m2");}
	if(a.Check(1, 2, 3, 6, 5, 8, 7, 4, 9))
	{ a.Facet(" y'", "", " y", " y2", str); str.append(" m2 u' m u2 m' u' m2");}
	if(a.Check(1, 6, 3, 4, 5, 8, 7, 2, 9))
	{ a.Facet("", " y", " y2", " y'", str); str.append(" m2 u' m u2 m' u' m2");}

	if(a.Check(7, 4, 3, 2, 5, 6, 1, 8, 9))
	{ a.Facet(" y", " y2", " y'", "", str); str.append(" r u2 r' u' r u2 l' u r' u' l");}
	if(a.Check(1, 2, 3, 8, 5, 6, 9, 4, 7))
	{ a.Facet(" y2", " y'", "", " y", str); str.append(" r u2 r' u' r u2 l' u r' u' l");}
	if(a.Check(1, 2, 9, 4, 5, 8, 7, 6, 3))
	{ a.Facet(" y'", "", " y", " y2", str); str.append(" r u2 r' u' r u2 l' u r' u' l");}
	if(a.Check(3, 6, 1, 4, 5, 2, 7, 8, 9))
	{ a.Facet("", " y", " y2", " y'", str); str.append(" r u2 r' u' r u2 l' u r' u' l");}

	if(a.Check(7, 2, 3, 8, 5, 6, 1, 4, 9))
	{ a.Facet(" y", " y2", " y'", "", str); str.append(" l u' r' u l' u2 r u' r' u2 r");}
	if(a.Check(1, 2, 3, 4, 5, 8, 9, 6, 7))
	{ a.Facet(" y2", " y'", "", " y", str); str.append(" l u' r' u l' u2 r u' r' u2 r");}
	if(a.Check(1, 6, 9, 4, 5, 2, 7, 8, 3))
	{ a.Facet(" y'", "", " y", " y2", str); str.append(" l u' r' u l' u2 r u' r' u2 r");}
	if(a.Check(3, 4, 1, 2, 5, 6, 7, 8, 9))
	{ a.Facet("", " y", " y2", " y'", str); str.append(" l u' r' u l' u2 r u' r' u2 r");}

	if(a.Check(1, 4, 3, 2, 5, 6, 9, 8, 7))
	{ a.Facet(" y", " y2", " y'", "", str); str.append(" u r2 f r u r u' r' f' r u2 r' u2 r");}
	if(a.Check(1, 2, 9, 8, 5, 6, 7, 4, 3))
	{ a.Facet(" y2", " y'", "", " y", str); str.append(" u r2 f r u r u' r' f' r u2 r' u2 r");}
	if(a.Check(3, 2, 1, 4, 5, 8, 7, 6, 9))
	{ a.Facet(" y'", "", " y", " y2", str); str.append(" u r2 f r u r u' r' f' r u2 r' u2 r");}
	if(a.Check(7, 6, 3, 4, 5, 2, 1, 8, 9))
	{ a.Facet("", " y", " y2", " y'", str); str.append(" u r2 f r u r u' r' f' r u2 r' u2 r");}

	if(a.Check(1, 6, 3, 4, 5, 2, 9, 8, 7))
	{ a.Facet(" y", " y2", " y'", "", str); str.append(" l u2 l' u2 l f' l' u' l u l f l2 u");}
	if(a.Check(1, 4, 9, 2, 5, 6, 7, 8, 3))
	{ a.Facet(" y2", " y'", "", " y", str); str.append(" l u2 l' u2 l f' l' u' l u l f l2 u");}
	if(a.Check(3, 2, 1, 8, 5, 6, 7, 4, 9))
	{ a.Facet(" y'", "", " y", " y2", str); str.append(" l u2 l' u2 l f' l' u' l u l f l2 u");}
	if(a.Check(7, 2, 3, 4, 5, 8, 1, 6, 9))
	{ a.Facet("", " y", " y2", " y'", str); str.append(" l u2 l' u2 l f' l' u' l u l f l2 u");}

	if(a.Check(7, 2, 3, 6, 5, 4, 1, 8, 9))
	{ a.Facet(" y", " y2", " y'", "", str); str.append(" r u r' u' r' f r2 u' r' u' r u r' f'");}
	if(a.Check(1, 8, 2, 4, 5, 6, 9, 2, 7))
	{ a.Facet(" y2", " y'", "", " y", str); str.append(" r u r' u' r' f r2 u' r' u' r u r' f'");}
	if(a.Check(1, 2, 9, 6, 5, 4, 7, 8, 3))
	{ a.Facet(" y", " y2", " y'", "", str); str.append(" l' u' l u l f' l2 u l u l' u' l f");}
	if(a.Check(3, 8, 1, 4, 5, 6, 7, 2, 9))
	{ a.Facet("", " y", " y2", " y'", str); str.append(" r u r' u' r' f r2 u' r' u' r u r' f'");}

	if(a.Check(9, 2, 3, 4, 5, 8, 7, 6, 1))
	{ a.Facet(" y", " y2", " y'", "", str); str.append(" f r u' r' u' r u r' f' r u r' u' r' f r f'");}
	if(a.Check(1, 6, 7, 4, 5, 2, 3, 8, 9))
	{ a.Facet(" y2", " y'", "", " y", str); str.append(" f r u' r' u' r u r' f' r u r' u' r' f r f'");}
	if(a.Check(9, 4, 3, 2, 5, 6, 7, 8, 1))
	{ a.Facet(" y'", "", " y", " y2", str); str.append(" f r u' r' u' r u r' f' r u r' u' r' f r f'");}
	if(a.Check(1, 2, 7, 8, 5, 6, 3, 4, 9))
	{ a.Facet("", " y", " y2", " y'", str); str.append(" f r u' r' u' r u r' f' r u r' u' r' f r f'");}

	if(a.Check(7, 8, 3, 4, 5, 6, 1, 2, 9))
	{ a.Facet(" y", " y2", " y'", "", str); str.append(" u' r' u r u' r2 f' u' f u r f r' f' r2");}
	if(a.Check(1, 2, 3, 6, 5, 4, 9, 8, 7))
	{ a.Facet(" y2", " y'", "", " y", str); str.append(" u' r' u r u' r2 f' u' f u r f r' f' r2");}
	if(a.Check(1, 8, 9, 4, 5, 6, 7, 2, 3))
	{ a.Facet(" y", " y2", " y'", "", str); str.append(" f' u2 f' u' r' f' r2 u' r' u r' f r u' f");}
	if(a.Check(3, 2, 1, 6, 5, 4, 7, 8, 9))
	{ a.Facet("", " y", " y2", " y'", str); str.append(" u' r' u r u' r2 f' u' f u r f r' f' r2");}
	
	if(a.Check(9, 2, 3, 8, 5, 6, 7, 4, 1))
	{ a.Facet(" y", " y2", " y'", "", str); str.append(" r' u r' u' y r' f' r2 u' r' u r' f r f");}
	if(a.Check(1, 2, 7, 4, 5, 8, 3, 6, 9))
	{ a.Facet(" y2", " y'", "", " y", str); str.append(" r' u r' u' y r' f' r2 u' r' u r' f r f");}
	if(a.Check(9, 6, 3, 4, 5, 2, 7, 8, 1))
	{ a.Facet(" y'", "", " y", " y2", str); str.append(" r' u r' u' y r' f' r2 u' r' u r' f r f");}
	if(a.Check(1, 4, 7, 2, 5, 6, 3, 8, 9))
	{ a.Facet("", " y", " y2", " y'", str); str.append(" r' u r' u' y r' f' r2 u' r' u r' f r f");}

	if(a.Check(1, 2, 7, 6, 5, 4, 3, 8, 9))
	{ a.Facet(" y", " y2", " y'", "", str); str.append(" r u' l u2 r' u l' r u' l u2 r' u l' u'");}
	if(a.Check(9, 8, 3, 4, 5, 6, 7, 2, 1))
	{ a.Facet(" y2", " y'", "", " y", str); str.append(" r u' l u2 r' u l' r u' l u2 r' u l' u'");}

	if(a.Check(9, 2, 3, 6, 5, 4, 7, 8, 1))
	{ a.Facet(" y", " y2", " y'", "", str); str.append(" r' u l' u2 r u' r' l u l' u2 r u' l u");}
	if(a.Check(1, 8, 7, 4, 5, 6, 3, 2, 9))
	{ a.Facet(" y2", " y'", "", " y", str); str.append(" r' u l' u2 r u' r' l u l' u2 r u' l u");}

	if(a.Check(7, 2, 3, 6, 5, 8, 9, 4, 1))
	{ a.Facet(" y", " y2", " y'", "", str); str.append(" r2 f2 r u2 r u2 r' f r u r' u' r' f r2");}
	if(a.Check(1, 6, 7, 4, 5, 8, 9, 2, 3))
	{ a.Facet(" y2", " y'", "", " y", str); str.append(" r2 f2 r u2 r u2 r' f r u r' u' r' f r2");}
	if(a.Check(9, 6, 1, 2, 5, 4, 7, 8, 3))
	{ a.Facet(" y'", "", " y", " y2", str); str.append(" r2 f2 r u2 r u2 r' f r u r' u' r' f r2");}
	if(a.Check(7, 8, 1, 2, 5, 6, 3, 4, 9))
	{ a.Facet("", " y", " y2", " y'", str); str.append(" r2 f2 r u2 r u2 r' f r u r' u' r' f r2");}

	if(a.Check(9, 2, 3, 8, 5, 4, 1, 6, 7))
	{ a.Facet(" y", " y2", " y'", "", str); str.append(" r2 f' r u r u' r' f' r u2 r' u2 r' f2 r2");}
	if(a.Check(1, 8, 9, 4, 5, 2, 3, 6, 7))
	{ a.Facet(" y2", " y'", "", " y", str); str.append(" r2 f' r u r u' r' f' r u2 r' u2 r' f2 r2");}
	if(a.Check(3, 4, 9, 6, 5, 2, 7, 8, 1))
	{ a.Facet(" y'", "", " y", " y2", str); str.append(" r2 f' r u r u' r' f' r u2 r' u2 r' f2 r2");}
	if(a.Check(3, 4, 7, 8, 5, 6, 1, 2, 9))
	{ a.Facet("", " y", " y2", " y'", str); str.append(" r2 f' r u r u' r' f' r u2 r' u2 r' f2 r2");}

	if(a.Check(1, 2, 9, 8, 5, 4, 3, 6, 7))
	{ a.Facet(" y", " y2", " y'", "", str); str.append(" l2 f2 l' u2 l' u2 l f' l' u' l u l f' l2");}
	if(a.Check(3, 8, 9, 4, 5, 2, 7, 6, 1))
	{ a.Facet(" y2", " y'", "", " y", str); str.append(" l2 f2 l' u2 l' u2 l f' l' u' l u l f' l2");}
	if(a.Check(3, 4, 7, 6, 5, 2, 1, 8, 9))
	{ a.Facet(" y'", "", " y", " y2", str); str.append(" l2 f2 l' u2 l' u2 l f' l' u' l u l f' l2");}
	if(a.Check(9, 4, 3, 8, 5, 6, 1, 2, 7))
	{ a.Facet("", " y", " y2", " y'", str); str.append(" l2 f2 l' u2 l' u2 l f' l' u' l u l f' l2");}

	if(a.Check(1, 2, 7, 6, 5, 8, 9, 4, 3))
	{ a.Facet(" y", " y2", " y'", "", str); str.append(" u' d r' u' r u d' r2 u r' u r u' r u' r2");}
	if(a.Check(9, 6, 1, 4, 5, 8, 7, 2, 3))
	{ a.Facet(" y2", " y'", "", " y", str); str.append(" u' d r' u' r u d' r2 u r' u r u' r u' r2");}
	if(a.Check(7, 6, 1, 2, 5, 4, 3, 8, 9))
	{ a.Facet(" y'", "", " y", " y2", str); str.append(" u' d r' u' r u d' r2 u r' u r u' r u' r2");}
	if(a.Check(7, 8, 3, 2, 5, 6, 9, 4, 1))
	{ a.Facet("", " y", " y2", " y'", str); str.append(" u' d r' u' r u d' r2 u r' u r u' r u' r2");}
	moves.append(str); Search(a, str);
	return 0;
}

void Model::Facet(string str1, string str2, string str3, string str4, string& str)
{
	current_facet == 4 ? str = str1 : (current_facet == 3 ? str = str2 : (current_facet == 2 ? str = str3 : str = str4));
}

bool Model::Check(int a, int b, int c, int d, int e, int f, int g, int h, int i)
{
	return Matr[5].index[0] == a && Matr[5].index[1] == b && Matr[5].index[2] == c && Matr[5].index[3] == d && 
	Matr[5].index[4] == e && Matr[5].index[5] == f && Matr[5].index[6] == g && Matr[5].index[7] == h && Matr[5].index[8] == i;
}

int Intersection_slow(Model& a, string& moves)
{
	string str;
	Position pos;
	for(int i = 2, j = 2; i < 9; i = j * 2, j++)
	{
		pos = a.Find_part("red", i);
		if(pos.facet == 0){ a.Turn_up("red", i, i, str); moves.append(str); Search(a, str);}
		if(pos.facet == 1) 
		{
			if(pos.position == 2) 
			{
				i == 4 ? (str = "f'", pos.position = 4) : (str = "f" , pos.position = 6);
				moves.append(str); Search(a, str);
			}
			if(pos.position == 8) 
			{
				i == 4 ? (str = "f", pos.position = 4) : (str = "f'" , pos.position = 6);
				moves.append(str); Search(a, str);
			}
			if(pos.position == 4)
			{
				a.Turn_up("red", Between(i, "left")[0], 8, str);
				moves.append(str); Search(a, str);
				a.Turn_up("red", Between(i, "left")[1], 6, str); 
				moves.append(str); Search(a, str);
				a.Turn_up("red", Between(i, "left")[2], 2, str); 
				str.append(" l'");
				moves.append(str); Search(a, str);
				a.Turn_up("red", i, i, str);
				moves.append(str); Search(a, str);
			}
			if(pos.position == 6) 
			{
				a.Turn_up("red", Between(i, "right")[0], 8, str);
				moves.append(str); Search(a, str);
				a.Turn_up("red", Between(i, "right")[1], 4, str);
				moves.append(str); Search(a, str);
				a.Turn_up("red", Between(i, "right")[2], 2, str);
				str.append(" r");
				moves.append(str); Search(a, str);
				a.Turn_up("red", i, i, str);
				moves.append(str); Search(a, str);
			}
		}
		if(pos.facet == 2) 
		{ 
			if(pos.position == 2) 
			{
				i == 2 ? (str = "l'", pos.position = 4) : (str = "l" , pos.position = 6);
				moves.append(str); Search(a, str);
			}
			if(pos.position == 8) 
			{
				i == 2 ? (str = "l", pos.position = 4) : (str = "l'" , pos.position = 6);
				moves.append(str); Search(a, str);
			}
			if(pos.position == 4)
			{
				a.Turn_up("red", Between(i, "left")[0], 4, str);
				moves.append(str); Search(a, str);
				a.Turn_up("red", Between(i, "left")[1], 8, str);
				moves.append(str); Search(a, str);
				a.Turn_up("red", Between(i, "left")[2], 6, str);
				str.append(" b'");
				moves.append(str); Search(a, str);
				a.Turn_up("red", i, i, str);
				moves.append(str); Search(a, str);
			}
			if(pos.position == 6) 
			{
				a.Turn_up("red", Between(i, "right")[0], 4, str);
				moves.append(str); Search(a, str);
				a.Turn_up("red", Between(i, "right")[1], 2, str);
				moves.append(str); Search(a, str);
				a.Turn_up("red", Between(i, "right")[2], 6, str);
				str.append(" f");
				moves.append(str); Search(a, str);
				a.Turn_up("red", i, i, str);
				moves.append(str); Search(a, str);
			}
		}
		if(pos.facet == 3) 
		{ 
			if(pos.position == 2) 
			{
				i == 6 ? (str = "b'", pos.position = 4) : (str = "b" , pos.position = 6);
				moves.append(str); Search(a, str);
			}
			if(pos.position == 8) 
			{
				i == 6 ? (str = "b", pos.position = 4) : (str = "b'" , pos.position = 6);
				moves.append(str); Search(a, str);
			}
			if(pos.position == 4)
			{
				a.Turn_up("red", Between(i, "left")[0], 8, str);
				moves.append(str); Search(a, str);
				a.Turn_up("red", Between(i, "left")[1], 6, str);
				moves.append(str); Search(a, str);
				a.Turn_up("red", Between(i, "left")[2], 2, str);
				str.append(" l");
				moves.append(str); Search(a, str);
				a.Turn_up("red", i, i, str);
				moves.append(str); Search(a, str);
			}
			if(pos.position == 6) 
			{
				a.Turn_up("red", Between(i, "right")[0], 8, str);
				moves.append(str); Search(a, str);
				a.Turn_up("red", Between(i, "right")[1], 4, str);
				moves.append(str); Search(a, str);
				a.Turn_up("red", Between(i, "right")[2], 2, str);
				str.append(" r'");
				moves.append(str); Search(a, str);
				a.Turn_up("red", i, i, str);
				moves.append(str); Search(a, str);
			}
		}
		if(pos.facet == 4) 
		{ 
			if(pos.position == 2) 
			{
				i == 8 ? (str = "r'", pos.position = 4) : (str = "r" , pos.position = 6);
				moves.append(str); Search(a, str);
			}
			if(pos.position == 8) 
			{
				i == 8 ? (str = "r", pos.position = 4) : (str = "r'" , pos.position = 6);
				moves.append(str); Search(a, str);
			}
			if(pos.position == 4)
			{
				a.Turn_up("red", Between(i, "left")[0], 6, str);
				moves.append(str); Search(a, str);
				a.Turn_up("red", Between(i, "left")[1], 2, str);
				moves.append(str); Search(a, str);
				a.Turn_up("red", Between(i, "left")[2], 4, str);
				str.append(" f'");
				moves.append(str); Search(a, str);
				a.Turn_up("red", i, i, str);
				moves.append(str); Search(a, str);
			}
			if(pos.position == 6) 
			{
				a.Turn_up("red", Between(i, "right")[0], 6, str);
				moves.append(str); Search(a, str);
				a.Turn_up("red", Between(i, "right")[1], 8, str);
				moves.append(str); Search(a, str);
				a.Turn_up("red", Between(i, "right")[2], 4, str);
				str.append(" b");
				moves.append(str); Search(a, str);
				a.Turn_up("red", i, i, str);
				moves.append(str); Search(a, str);
			}
		}
		if(pos.facet == 5)
		{ 
			a.Turn_down("red", i, i, str);
			moves.append(str); Search(a, str);
			a.Turn_up("red", 4, 4, str);
			moves.append(str); Search(a, str);
			a.Turn_up("red", 6, 6, str);
			moves.append(str); Search(a, str);
			a.Turn_up("red", 8, 8, str);
			if(i == 4 || i == 6) i == 6 ? str.append(" r r") : str.append(" l' l'");
			else i == 8 ? str.append(" f f") : str.append(" b b");
			moves.append(str); Search(a, str);
			a.Turn_up("red", i, i, str);
			moves.append(str); Search(a, str);
		}
	}
	return 0;
}

int Corners_slow(Model& a, string& moves)
{
	int b[4];
	string str;
	Position pos;
	int ind[4] = {1, 3, 7, 9};
	moves.append("\nCorners:\n");
	string color[4] = {"yellow", "green", "blue", "white"};
	for(int i = 1, j = 0; i < 10;)
	{
		pos = a.Find_part("red", i);
		if(pos.facet == 0 && pos.position != i) 
		{
			if(pos.facet == 0 && pos.position == 1)
			{
				i == 3 ? str.append(" l' d' l") : str.append(""); pos.facet = 4; pos.position = 9;
				i == 7 ? str.append(" b d b'") : str.append(""); pos.facet = 1; pos.position = 7;
				i == 9 ? str.append(" l' d' l") : str.append(""); pos.facet = 4; pos.position = 9;
				moves.append(str); Search(a, str);
			}
			if(pos.facet ==0 && pos.position == 3)
			{
				i == 1 ? str.append(" r d r'") : str.append(""); pos.facet = 2; pos.position = 7;
				i == 7 ? str.append(" r d r'") : str.append(""); pos.facet = 2; pos.position = 7;
				i == 9 ? str.append(" b' d' b") : str.append(""); pos.facet = 1; pos.position = 9;
				moves.append(str); Search(a, str);
			}
			if(pos.facet == 0 && pos.position == 7)
			{
				i == 1 ? str.append(" f' d' f") : str.append(""); pos.facet = 3; pos.position = 1;
				i == 3 ? str.append(" l d l'") : str.append(""); pos.facet = 4; pos.position = 7;
				i == 9 ? str.append(" l d l'") : str.append(""); pos.facet = 4; pos.position = 7;
				moves.append(str); Search(a, str);
			}
			if(pos.facet == 0 && pos.position == 9)
			{
				i == 1 ? str.append(" r d' r'") : str.append(""); pos.facet = 2; pos.position = 9;
				i == 3 ? str.append(" f d f'") : str.append(""); pos.facet = 3; pos.position = 3;
				i == 7 ? str.append(" r' d' r") : str.append(""); pos.facet = 2; pos.position = 9;
				moves.append(str); Search(a, str);
			}
		}
		if(pos.facet == 0 && pos.position == i)
		{	i == 3 ? i +=4 : i += 2; j++;}
		if(pos.facet == 1) 
		{
			if(pos.facet == 1 && pos.position == 1)
			{
				str = "f' d' f";
				moves.append(str); Search(a, str);
				pos.facet = 3; pos.position = 1;
			}
			if(pos.facet == 1 && pos.position == 3)
			{
				str = "f d f'";
				moves.append(str); Search(a, str);
				pos.facet = 3; pos.position = 3;
			}
			if(pos.facet == 1 && pos.position == 7)
			{
				if(a.Find_part(color[j], color[j] != "yellow" ? 6 : 4).facet != 2 
				&& a.Find_part(color[j], color[j] != "yellow" ? 6 : 4).position != 8)
				{
					i == 1 ? str.append(" b d' b'") : str.append("");
					i == 3 ? str.append(" d' r d' r'") : str.append("");
					i == 7 ? str.append(" f' d' f") : str.append("");
					i == 9 ? str.append(" d r' d' r") : str.append("");
					moves.append(str); Search(a, str);
				}
				else
				{
					i == 1 ? str.append(" b d' b'") : str.append("");
					i == 3 ? str.append(" d' r d' r'") : str.append("");
					i == 7 ? str.append(" d l d' l'") : str.append("");
					i == 9 ? str.append(" d d f d' d") : str.append("");
					moves.append(str); Search(a, str);
				}
			}
			if(pos.facet == 1 && pos.position == 9)
			{
				if(a.Find_part(color[j], color[j] != "yellow" ? 6 : 4).facet != 5 
				&& a.Find_part(color[j], color[j] != "yellow" ? 6 : 4).position != 6)
				{
					i == 1 ? str.append(" d l' d l") : str.append("");
					i == 3 ? str.append(" b' d b") : str.append("");
					i == 7 ? str.append(" d' l d l'") : str.append("");
					i == 9 ? str.append(" f d f'") : str.append("");
					moves.append(str); Search(a, str);
				}
				else
				{
					i == 1 ? str.append(" d l' d l") : str.append("");
					i == 3 ? str.append(" b' d b") : str.append("");
					i == 7 ? str.append(" d' d' f' d f") : str.append("");
					i == 9 ? str.append(" d' r' d r") : str.append("");
					moves.append(str); Search(a, str);
				}
			}
		}
		if(pos.facet == 2)//=============================
		{ 
			if(pos.facet == 2 && pos.position == 1)
			{
				str = "l' d' l";
				moves.append(str); Search(a, str);
				pos.facet = 3; pos.position = 3;
			}
			if(pos.facet == 2 && pos.position == 3)
			{
				str = "l d l'";
				moves.append(str); Search(a, str);
				pos.facet = 4; pos.position = 7;
			}
			if(pos.facet == 2 && pos.position == 7)
			{
				if(a.Find_part(color[j], color[j] != "yellow" ? 6 : 4).facet != 3 
				&& a.Find_part(color[j], color[j] != "yellow" ? 6 : 4).position != 2)
				{
					i == 1 ? str.append(" l' d' l") : str.append("");
					i == 3 ? str.append(" r d' r'") : str.append("");
					i == 7 ? str.append(" d f' d' f") : str.append("");
					i == 9 ? str.append(" d' f d' f'") : str.append("");
					moves.append(str); Search(a, str);
				}
				else
				{
					i == 1 ? str.append(" d b d' b'") : str.append("");
					i == 3 ? str.append(" r d' r'") : str.append("");
					i == 7 ? str.append(" d d l d' l'") : str.append("");
					i == 9 ? str.append(" d' f d' f'") : str.append("");
					moves.append(str); Search(a, str);
				}
			}
			if(pos.facet == 2 && pos.position == 9)
			{
				if(a.Find_part(color[j], color[j] != "yellow" ? 6 : 4).facet != 5 
				&& a.Find_part(color[j], color[j] != "yellow" ? 6 : 4).position != 2)
				{
					i == 1 ? str.append(" d' b d b'") : str.append("");
					i == 3 ? str.append(" d b' d b") : str.append("");
					i == 7 ? str.append(" l d' l'") : str.append("");
					i == 9 ? str.append(" r' d r") : str.append("");
					moves.append(str); Search(a, str);
				}
				else
				{
					i == 1 ? str.append(" d d l' d l") : str.append("");
					i == 3 ? str.append(" d b' d b") : str.append("");
					i == 7 ? str.append(" d' f' d f") : str.append("");
					i == 9 ? str.append(" r' d r") : str.append("");
					moves.append(str); Search(a, str);
				}
			}
		}
		if(pos.facet == 3) //===========================
		{ 
			if(pos.facet == 3 && pos.position == 7)
			{
				str = "b d b'";
				moves.append(str); Search(a, str);
				pos.facet = 2; pos.position = 9;
			}
			if(pos.facet == 3 && pos.position == 9)
			{
				str = "b' d' b";
				moves.append(str); Search(a, str);
				pos.facet = 4; pos.position = 7;
			}
			if(pos.facet == 3 && pos.position == 1)
			{
				if(a.Find_part(color[j], color[j] != "yellow" ? 6 : 4).facet != 5 
				&& a.Find_part(color[j], color[j] != "yellow" ? 6 : 4).position != 4)
				{
					i == 1 ? str.append(" b d b'") : str.append("");
					i == 3 ? str.append(" d' r d r'") : str.append("");
					i == 7 ? str.append(" f' d f") : str.append("");
					i == 9 ? str.append(" d r' d r") : str.append("");
					moves.append(str); Search(a, str);
				}
				else
				{
					i == 1 ? str.append(" d' l' d l") : str.append("");
					i == 3 ? str.append(" d' d' b' d b") : str.append("");
					i == 7 ? str.append(" f' d f") : str.append("");
					i == 9 ? str.append(" d r' d r") : str.append("");
					moves.append(str); Search(a, str);
				}
			}
			if(pos.facet == 3 && pos.position == 3)
			{
				if(a.Find_part(color[j], color[j] != "yellow" ? 6 : 4).facet !=  4
				&& a.Find_part(color[j], color[j] != "yellow" ? 6 : 4).position != 8)
				{
					i == 1 ? str.append(" d l' d' l") : str.append("");
					i == 3 ? str.append(" b' d' b") : str.append("");
					i == 7 ? str.append(" d' l d' l'") : str.append("");
					i == 9 ? str.append(" f d' f'") : str.append("");
					moves.append(str); Search(a, str);
				}
				else
				{
					i == 1 ? str.append(" d' d' b d' b'") : str.append("");
					i == 3 ? str.append(" d r d' r'") : str.append("");
					i == 7 ? str.append(" d' l d' l'") : str.append("");
					i == 9 ? str.append(" f d' f'") : str.append("");
					moves.append(str); Search(a, str);
				}
			}
		}
		if(pos.facet == 4) //=========================
		{ 
			if(pos.facet == 4 && pos.position == 1)
			{
				str = "r' d' r";
				moves.append(str); Search(a, str);
				pos.facet = 1; pos.position = 7;
			}
			if(pos.facet == 4 && pos.position == 3)
			{
				str = "r d r'";
				moves.append(str); Search(a, str);
				pos.facet = 3; pos.position = 1;
			}
			if(pos.facet == 4 && pos.position == 7)
			{
				if(a.Find_part(color[j], color[j] != "yellow" ? 6 : 4).facet != 1 
				&& a.Find_part(color[j], color[j] != "yellow" ? 6 : 4).position != 8)
				{
					i == 1 ? str.append(" d' b d' b'") : str.append("");
					i == 3 ? str.append(" d b' d' b") : str.append("");
					i == 7 ? str.append(" l d' l'") : str.append("");
					i == 9 ? str.append(" r' d' r") : str.append("");
					moves.append(str); Search(a, str);
				}
				else
				{
					i == 1 ? str.append(" d' b d' b'") : str.append("");
					i == 3 ? str.append(" d d r d' r'") : str.append("");
					i == 7 ? str.append(" l d' l'") : str.append("");
					i == 9 ? str.append(" d f d' f'") : str.append("");
					moves.append(str); Search(a, str);
				}
			}
			if(pos.facet == 4 && pos.position == 9)
			{
				if(a.Find_part(color[j], color[j] != "yellow" ? 6 : 4).facet != 5 
				&& a.Find_part(color[j], color[j] != "yellow" ? 6 : 4).position != 8)
				{
					i == 1 ? str.append(" l' d l") : str.append("");
					i == 3 ? str.append(" r d r'") : str.append("");
					i == 7 ? str.append(" d f' d f") : str.append("");
					i == 9 ? str.append(" d' f d f'") : str.append("");
					moves.append(str); Search(a, str);
				}
				else
				{
					i == 1 ? str.append(" l' d l") : str.append("");
					i == 3 ? str.append(" d' b' d b") : str.append("");
					i == 7 ? str.append(" d f' d f") : str.append("");
					i == 9 ? str.append(" d' d' r' d r") : str.append("");
					moves.append(str); Search(a, str);
				}
			}
		}
		if(pos.facet == 5) //==========================
		{ 
			if(pos.facet == 5 && pos.position == 1)
			{
				i == 1 ? str.append(" d' l' d l") : str.append(""); pos.facet = 4; pos.position = 7;
				i == 3 ? str.append(" d d r d' r'") : str.append(""); pos.facet = 2; pos.position = 9;
				i == 7 ? str.append(" l d' l'") : str.append(""); pos.facet = 4; pos.position = 9;
				i == 9 ? str.append(" d r' d r") : str.append(""); pos.facet = 2; pos.position = 7;
				moves.append(str); Search(a, str);
			}
			if(pos.facet == 5 && pos.position == 3)
			{
				i == 1 ? str.append(" d d l' d l") : str.append(""); pos.facet = 4; pos.position = 7;
				i == 3 ? str.append(" d r d' r'") : str.append(""); pos.facet = 2; pos.position = 9;
				i == 7 ? str.append(" d' l d' l'") : str.append(""); pos.facet = 4; pos.position = 9;
				i == 9 ? str.append(" r' d r") : str.append(""); pos.facet = 2; pos.position = 7;
				moves.append(str); Search(a, str);
			}
			if(pos.facet == 5 && pos.position == 7)
			{
				i == 1 ? str.append(" l' d l") : str.append(""); pos.facet = 4; pos.position = 7;
				i == 3 ? str.append(" d' r d' r'") : str.append(""); pos.facet = 2; pos.position = 9;
				i == 7 ? str.append(" d l d' l'") : str.append(""); pos.facet = 4; pos.position = 9;
				i == 9 ? str.append(" d d r' d r") : str.append(""); pos.facet = 2; pos.position = 7;
				moves.append(str); Search(a, str);
			}
			if(pos.facet == 5 && pos.position == 9)
			{
				i == 1 ? str.append(" d l' d l") : str.append(""); pos.facet = 4; pos.position = 7;
				i == 3 ? str.append(" r d' r'") : str.append(""); pos.facet = 2; pos.position = 9;
				i == 7 ? str.append(" d d l d' l'") : str.append(""); pos.facet = 4; pos.position = 9;
				i == 9 ? str.append(" d' r' d r") : str.append(""); pos.facet = 2; pos.position = 7;
				moves.append(str); Search(a, str);
			}
		}
	}
	return 0;
}

int Middles_slow(Model& a, string& moves)
{
	string str;
	Position pos;
	moves.append("\nMiddles:\n");
	string color[8] = {"white", "blue", "yellow", "green", "blue", "yellow", "green", "white"};
	for(int i = 0, j = 0; i < 4; i++)
	{
		pos = a.Combination(color);
		if(pos.facet == 1)
		{
			if(pos.position == 8) 
			{
				if(a.Matr[pos.facet].color[pos.position - 1] == "green" && a.Matr[5].color[1] == "yellow")
					str.append(" b' d b d r d' r'");
				if(a.Matr[pos.facet].color[pos.position - 1] == "yellow" && a.Matr[5].color[1] == "green")
					str.append(" d' r d' r' d' b' d b");
				if(a.Matr[pos.facet].color[pos.position - 1] == "green" && a.Matr[5].color[1] == "white")
					str.append(" d d f d' f' d' r' d r");
				if(a.Matr[pos.facet].color[pos.position - 1] == "white" && a.Matr[5].color[1] == "green")
					str.append(" d' r' d r d f d' f'");
				if(a.Matr[pos.facet].color[pos.position - 1] == "blue" && a.Matr[5].color[1] == "white")
					str.append(" d d f' d f d l d' l'");
				if(a.Matr[pos.facet].color[pos.position - 1] == "white" && a.Matr[5].color[1] == "blue")
					str.append(" d l d' l' d' f' d f");
				if(a.Matr[pos.facet].color[pos.position - 1] == "blue" && a.Matr[5].color[1] == "yellow")
					str.append(" b d' b' d' l' d l");
				if(a.Matr[pos.facet].color[pos.position - 1] == "yellow" && a.Matr[5].color[1] == "blue")
					str.append(" d l' d l d b d' b'");
				moves.append(str); Search(a, str);
			}
		}
		if(pos.facet == 2)
		{
			if(pos.position == 8) 
			{
				if(a.Matr[pos.facet].color[pos.position - 1] == "green" && a.Matr[5].color[3] == "yellow")
					str.append(" d b' d b d r d' r'");
				if(a.Matr[pos.facet].color[pos.position - 1] == "yellow" && a.Matr[5].color[3] == "green")
					str.append(" r d' r' d' b' d b");
				if(a.Matr[pos.facet].color[pos.position - 1] == "green" && a.Matr[5].color[3] == "white")
					str.append(" d' f d' f' d' r' d r");
				if(a.Matr[pos.facet].color[pos.position - 1] == "white" && a.Matr[5].color[3] == "green")
					str.append(" r' d r d f d' f'");
				if(a.Matr[pos.facet].color[pos.position - 1] == "blue" && a.Matr[5].color[3] == "white")
					str.append(" d' f' d f d l d' l'");
				if(a.Matr[pos.facet].color[pos.position - 1] == "white" && a.Matr[5].color[3] == "blue")
					str.append(" d d l d' l' d' f' d f");
				if(a.Matr[pos.facet].color[pos.position - 1] == "blue" && a.Matr[5].color[3] == "yellow")
					str.append(" d b d' b' d' l' d l");
				if(a.Matr[pos.facet].color[pos.position - 1] == "yellow" && a.Matr[5].color[3] == "blue")
					str.append(" d d l' d l d b d' b'");
				moves.append(str); Search(a, str);
			}
		}
		if(pos.facet == 3)
		{
			if(pos.position == 2) 
			{
				if(a.Matr[pos.facet].color[pos.position - 1] == "green" && a.Matr[5].color[7] == "yellow")
					str.append(" d d b' d b d r d' r'");
				if(a.Matr[pos.facet].color[pos.position - 1] == "yellow" && a.Matr[5].color[7] == "green")
					str.append(" d r d' r' d' b' d b");
				if(a.Matr[pos.facet].color[pos.position - 1] == "green" && a.Matr[5].color[7] == "white")
					str.append(" f d' f' d' r' d r");
				if(a.Matr[pos.facet].color[pos.position - 1] == "white" && a.Matr[5].color[7] == "green")
					str.append(" d r' d r d f d' f'");
				if(a.Matr[pos.facet].color[pos.position - 1] == "blue" && a.Matr[5].color[7] == "white")
					str.append(" f' d f d l d' l'");
				if(a.Matr[pos.facet].color[pos.position - 1] == "white" && a.Matr[5].color[7] == "blue")
					str.append(" d' l d' l' d' f' d f");
				if(a.Matr[pos.facet].color[pos.position - 1] == "blue" && a.Matr[5].color[7] == "yellow")
					str.append(" d d b d' b' d' l' d l");
				if(a.Matr[pos.facet].color[pos.position - 1] == "yellow" && a.Matr[5].color[7] == "blue")
					str.append(" d' l' d l d b d' b'");
				moves.append(str); Search(a, str);
			}
		}
		if(pos.facet == 4)
		{
			if(pos.position == 8) 
			{
				if(a.Matr[pos.facet].color[pos.position - 1] == "green" && a.Matr[5].color[5] == "yellow")
					str.append(" d' b' d b d r d' r'");
				if(a.Matr[pos.facet].color[pos.position - 1] == "yellow" && a.Matr[5].color[5] == "green")
					str.append(" d d r d' r' d' b' d b");
				if(a.Matr[pos.facet].color[pos.position - 1] == "green" && a.Matr[5].color[5] == "white")
					str.append(" d f d' f' d' r' d r");
				if(a.Matr[pos.facet].color[pos.position - 1] == "white" && a.Matr[5].color[5] == "green")
					str.append(" d' d' r' d r d f d' f'");
				if(a.Matr[pos.facet].color[pos.position - 1] == "blue" && a.Matr[5].color[5] == "white")
					str.append(" d f' d f d l d' l'");
				if(a.Matr[pos.facet].color[pos.position - 1] == "white" && a.Matr[5].color[5] == "blue")
					str.append(" l d' l' d' f' d f");
				if(a.Matr[pos.facet].color[pos.position - 1] == "blue" && a.Matr[5].color[5] == "yellow")
					str.append(" d' b d' b' d' l' d l");
				if(a.Matr[pos.facet].color[pos.position - 1] == "yellow" && a.Matr[5].color[5] == "blue")
					str.append(" l' d l d b d' b'");
				moves.append(str); Search(a, str);
			}
		}
	}
	return 0;
}

int Down_intersection_slow(Model& a, string& moves)
{
	int b[4];
	string str;
	Position pos;
	for(int i = 2, j = 0; i < 9; i += 2)
	{
		b[j++] = a.Check_part("orange", i, 5);
	}
	if(b[0] == 0 && b[1] == 0 && b[2] ==0 && b[3] == 0)
	{	str.append(" f l d l' d' f'"); b[0] = 1; b[1] = 1; b[2] = 0; b[3] = 0;}
	if(b[0] != 0 && b[1] == 0 && b[2] != 0 && b[3] == 0)
	{	str.append(" d"); b[0] = 0; b[1] = 0; b[2] = 1; b[3] = 1;}
	if(b[0] == 0 && b[1] != 0 && b[2] == 0 && b[3] != 0)
	{	str.append(" d'"); b[0] = 0; b[1] = 0; b[2] = 1; b[3] = 1;}
	if(b[0] != 0 && b[1] == 0 && b[2] == 0 && b[3] != 0)
	{	str.append(" d"); b[0] = 0; b[1] = 1; b[2] = 1; b[3] = 0;}
	if(b[0] == 0 && b[1] == 0 && b[2] != 0 && b[3] != 0)
		str.append(" f l d l' d' l d l' d' f'");
	if(b[0] == 0 && b[1] != 0 && b[2] != 0 && b[3] == 0)
		str.append(" b r d r' d' b'");
	if(b[0] != 0 && b[1] != 0 && b[2] == 0 && b[3] == 0)
		str.append(" b r d r' d' r d r' d' b'");
	moves.append(str); Search(a, str);
	pos = a.Find_part("orange", 2, 5);
	for(int j = 0, i = pos.position - 1; j < 4; i == 1 ? i += 4 : (i == 3 ? i -= 2 : (i == 5 ? i += 2 : (i == 7 ? i -= 4 : i))))
	{ b[j++] = a.Matr[5].index[i];}
	// if(b[1] != 6 && b[2] != 8 && b[3] != 4)
	// {
	// 	if(b[1] == 6)
	// 		str.append(" ");
	// }
	moves.append(str); Search(a, str);
	return 0;
}

Position Model::Combination(int* ind, int* b)
{
	Position pos;
	for(int i = 0, j = 0, k = 0;;)
	{
		if(ind[0] != 0 && ind[1] != 0 && ind[2] != 0 && ind[3] != 0)
		{
			if(ind[i] == 0)
				i++;
			pos = Find_part("red", ind[i]);
			if(pos.facet != 0 && pos.facet != 5)
			{
				ind[i] = 0; return pos;
			}
			if(pos.facet == 0 || pos.facet == 5)
			{	b[j++] = ind[i]; ind[i] = 0; i++;}
		}
		else
		{
			if(b[k]){ pos = Find_part("red", b[k]); b[k] = 0; return pos;}
			else k++;
		}
	}
	return pos;
}

Position Model::Combination(string* color)
{
	Position pos;
	for(int i = 0;;)
	{
		if(color[i] == "")
			while(!color[++i].size() && i < 4);
		pos = Find_part(color[i], color[i] == "yellow" ? 6 : 4);
		if(pos.facet == 5)
		{	pos = Find_part(color[i + 4], color[i + 4] == "yellow" ? 4 : 6); color[i].clear(); color[i + 4].clear(); return pos;}
		if(pos.facet != 5 && pos.facet != 0 && (pos.position != 4 && pos.position != 6))
		{	color[i].clear(); color[i + 4].clear(); return pos;}
		if(pos.facet != 5 && (pos.position == 4 || pos.position == 6))
			i++;
		if(i > 3)
		{ 
			for(int i = 0; i < 4; i++)
			{
				if(color[i].size())
				{ pos = Find_part(color[i], color[i] == "yellow" ? 6 : 4); color[i].clear(); color[i + 4].clear(); return pos;}
			}
		}
	}
	return pos;
}

Position Model::Pos(int* ind, int& n)
{
	Position pos;
	for(int i = 0;;)
	{
		if(ind[i] == 0)
			while(!ind[++i] && i < 4);
		pos = Find_part("red", ind[i]);
		if(pos.facet != 5 && pos.facet != 0 && pos.position == 4)
		{
			if(Check_part("red", pos.facet == 2 ? 6 : 4, pos.facet != 4 ? (pos.facet + 1) : 1))
			{	pos.facet = (pos.facet != 4 ? (pos.facet + 1) : 1); pos.position = pos.facet == 3 ? 6 : 4; n = Matr[pos.facet].index[pos.facet == 3 ? 5 : 3]; ind[(n / 2) - 1] = 0; return pos;}
			if(Check_part("red", 6, 2))
			{	pos.facet = 2; pos.position = 6; n = Matr[2].index[5]; ind[(n / 2) - 1] = 0; return pos;}
			else
				n = ind[i]; ind[i] = 0; return pos;
		}
		if(pos.facet != 5 && pos.facet != 0 && pos.position == 6)
		{ 
			if(Check_part("red", pos.facet == 4 ? 4 : 6, pos.facet != 1 ? (pos.facet - 1) : 4)) 
			{	pos.facet = (pos.facet != 1 ? (pos.facet - 1) : 4); pos.position = pos.facet == 3 ? 4 : 6; n = Matr[pos.facet].index[pos.facet == 3 ? 3 : 5]; ind[(n / 2) - 1] = 0; return pos;}
			if(Check_part("red", 4, 4))
			{	pos.facet = 4; pos.position = 4; n = Matr[4].index[3]; ind[(n / 2) - 1] = 0; return pos;}
			else
				n = ind[i]; ind[i] = 0; return pos;
		}
		if(pos.facet == 5 || pos.facet == 0 || pos.position == 2 || pos.position == 8)
			i++;
		if(i > 3)
		{ 
			for(int i = 0; i < 4; i++){ if(ind[i]){ pos = Find_part("red", ind[i]); if(pos.facet != 5){ n = ind[i]; ind[i] = 0; return pos;}}}
			for(int i = 0; i < 4; i++){ if(ind[i]){ pos = Find_part("red", ind[i]); n = ind[i]; ind[i] = 0; return pos;}}
		}
	}
	return pos;
}

void Model::Up_color()
{
	int j = 0, k = 0;
	string a[12] = {Matr[1].color[0], Matr[1].color[1], Matr[1].color[2], Matr[2].color[2], Matr[2].color[1], Matr[2].color[0],
	Matr[3].color[8], Matr[3].color[7], Matr[3].color[6], Matr[4].color[0], Matr[4].color[1], Matr[4].color[2]};
	int b[12] = {Matr[1].index[0], Matr[1].index[1], Matr[1].index[2], Matr[2].index[2], Matr[2].index[1], Matr[2].index[0],
	Matr[3].index[8], Matr[3].index[7], Matr[3].index[6], Matr[4].index[0], Matr[4].index[1], Matr[4].index[2]};
	for(int i = 0; i < 3; i++){ Matr[2].color[i] = a[j++]; Matr[2].index[i] = b[k++];}
	for(int i = 6; i < 9; i++){ Matr[3].color[i] = a[j++]; Matr[3].index[i] = b[k++];}
	for(int i = 0; i < 3; i++){ Matr[4].color[i] = a[j++]; Matr[4].index[i] = b[k++];}
	for(int i = 0; i < 3; i++){ Matr[1].color[i] = a[j++]; Matr[1].index[i] = b[k++];}
}

void Model::Up_color_stroke()
{
	int j = 0, k = 0;
	string a[12] = {Matr[1].color[0], Matr[1].color[1], Matr[1].color[2], Matr[2].color[0], Matr[2].color[1], Matr[2].color[2],
	Matr[3].color[8], Matr[3].color[7], Matr[3].color[6], Matr[4].color[2], Matr[4].color[1], Matr[4].color[0]};
	int b[12] = {Matr[1].index[0], Matr[1].index[1], Matr[1].index[2], Matr[2].index[0], Matr[2].index[1], Matr[2].index[2],
	Matr[3].index[8], Matr[3].index[7], Matr[3].index[6], Matr[4].index[2], Matr[4].index[1], Matr[4].index[0]};
	for(int i = 0; i < 3; i++){ Matr[4].color[i] = a[j++]; Matr[4].index[i] = b[k++];}
	for(int i = 0; i < 3; i++){ Matr[1].color[i] = a[j++]; Matr[1].index[i] = b[k++];}
	for(int i = 0; i < 3; i++){ Matr[2].color[i] = a[j++]; Matr[2].index[i] = b[k++];}
	for(int i = 6; i < 9; i++){ Matr[3].color[i] = a[j++]; Matr[3].index[i] = b[k++];}
}

void Model::Down_color()
{
	int j = 0, k = 0;
	string a[12] = {Matr[1].color[6], Matr[1].color[7], Matr[1].color[8], Matr[2].color[6], Matr[2].color[7], Matr[2].color[8],
	Matr[3].color[2], Matr[3].color[1], Matr[3].color[0], Matr[4].color[8], Matr[4].color[7], Matr[4].color[6]};
	int b[12] = {Matr[1].index[6], Matr[1].index[7], Matr[1].index[8], Matr[2].index[6], Matr[2].index[7], Matr[2].index[8],
	Matr[3].index[2], Matr[3].index[1], Matr[3].index[0], Matr[4].index[8], Matr[4].index[7], Matr[4].index[6]};
	for(int i = 6; i < 9; i++){ Matr[4].color[i] = a[j++]; Matr[4].index[i] = b[k++];}
	for(int i = 6; i < 9; i++){ Matr[1].color[i] = a[j++]; Matr[1].index[i] = b[k++];}
	for(int i = 6; i < 9; i++){ Matr[2].color[i] = a[j++]; Matr[2].index[i] = b[k++];}
	for(int i = 0; i < 3; i++){ Matr[3].color[i] = a[j++]; Matr[3].index[i] = b[k++];}
}

void Model::Down_color_stroke()
{
    int j = 0, k = 0;
	string a[12] = {Matr[1].color[6], Matr[1].color[7], Matr[1].color[8], Matr[2].color[8], Matr[2].color[7], Matr[2].color[6],
	Matr[3].color[2], Matr[3].color[1], Matr[3].color[0], Matr[4].color[6], Matr[4].color[7], Matr[4].color[8]};
	int b[12] = {Matr[1].index[6], Matr[1].index[7], Matr[1].index[8], Matr[2].index[8], Matr[2].index[7], Matr[2].index[6],
	Matr[3].index[2], Matr[3].index[1], Matr[3].index[0], Matr[4].index[6], Matr[4].index[7], Matr[4].index[8]};
	for(int i = 6; i < 9; i++){ Matr[2].color[i] = a[j++]; Matr[2].index[i] = b[k++];}
	for(int i = 0; i < 3; i++){ Matr[3].color[i] = a[j++]; Matr[3].index[i] = b[k++];}
	for(int i = 6; i < 9; i++){ Matr[4].color[i] = a[j++]; Matr[4].index[i] = b[k++];}
	for(int i = 6; i < 9; i++){ Matr[1].color[i] = a[j++]; Matr[1].index[i] = b[k++];}
}

void Model::Second_color()
{
	int k = 0;
	string a[12] = {Matr[0].color[3], Matr[0].color[4], Matr[0].color[5], Matr[4].color[7], Matr[4].color[4], Matr[4].color[1],
	Matr[5].color[3], Matr[5].color[4], Matr[5].color[5], Matr[2].color[7], Matr[2].color[4], Matr[2].color[1]};
	int b[12] = {Matr[0].index[3], Matr[0].index[4], Matr[0].index[5], Matr[4].index[7], Matr[4].index[4], Matr[4].index[1],
	Matr[5].index[3], Matr[5].index[4], Matr[5].index[5], Matr[2].index[7], Matr[2].index[4], Matr[2].index[1]};
	for(int i = 1; i <= 7; i += 3){ Matr[4].color[i] = a[k]; Matr[4].index[i] = b[k++];}
	for(int i = 3; i < 6; i++){ Matr[5].color[i] = a[k]; Matr[5].index[i] = b[k++];}
	for(int i = 1; i <= 7; i += 3){ Matr[2].color[i] = a[k]; Matr[2].index[i] = b[k++];} 
	for(int i = 3; i < 6; i++){ Matr[0].color[i] = a[k]; Matr[0].index[i] = b[k++];}
}

void Model::Second_color_stroke()
{
	int k = 0;
	string a[12] = {Matr[0].color[5], Matr[0].color[4], Matr[0].color[3], Matr[4].color[1], Matr[4].color[4], Matr[4].color[7],
	Matr[5].color[5], Matr[5].color[4], Matr[5].color[3], Matr[2].color[1], Matr[2].color[4], Matr[2].color[7]};
	int b[12] = {Matr[0].index[5], Matr[0].index[4], Matr[0].index[3], Matr[4].index[1], Matr[4].index[4], Matr[4].index[7],
	Matr[5].index[5], Matr[5].index[4], Matr[5].index[3], Matr[2].index[1], Matr[2].index[4], Matr[2].index[7]};
	for(int i = 1; i <= 7; i += 3){ Matr[2].color[i] = a[k]; Matr[2].index[i] = b[k++];} 
	for(int i = 3; i < 6; i++){ Matr[0].color[i] = a[k]; Matr[0].index[i] = b[k++];}
	for(int i = 1; i <= 7; i += 3){ Matr[4].color[i] = a[k]; Matr[4].index[i] = b[k++];}
	for(int i = 3; i < 6; i++){ Matr[5].color[i] = a[k]; Matr[5].index[i] = b[k++];}
}

void Model::Middle_color()
{
	int j = 0, k = 0;
	string a[12] = {Matr[0].color[1], Matr[0].color[4], Matr[0].color[7], Matr[3].color[1], Matr[3].color[4], Matr[3].color[7],
	Matr[5].color[1], Matr[5].color[4], Matr[5].color[7], Matr[1].color[1], Matr[1].color[4], Matr[1].color[7]};
	int b[12] = {Matr[0].index[1], Matr[0].index[4], Matr[0].index[7], Matr[3].index[1], Matr[3].index[4], Matr[3].index[7],
	Matr[5].index[1], Matr[5].index[4], Matr[5].index[7], Matr[1].index[1], Matr[1].index[4], Matr[1].index[7]};
	for(int i = 1; i <= 7; i += 3){ Matr[1].color[i] = a[j++]; Matr[1].index[i] = b[k++];}
	for(int i = 1; i <= 7; i += 3){ Matr[0].color[i] = a[j++]; Matr[0].index[i] = b[k++];}
	for(int i = 1; i <= 7; i += 3){ Matr[3].color[i] = a[j++]; Matr[3].index[i] = b[k++];}
	for(int i = 1; i <= 7; i += 3){ Matr[5].color[i] = a[j++]; Matr[5].index[i] = b[k++];}
}

void Model::Middle_color_stroke()
{
	int j = 0, k = 0;
	string a[12] = {Matr[0].color[1], Matr[0].color[4], Matr[0].color[7], Matr[3].color[1], Matr[3].color[4], Matr[3].color[7],
	Matr[5].color[1], Matr[5].color[4], Matr[5].color[7], Matr[1].color[1], Matr[1].color[4], Matr[1].color[7]};
	int b[12] = {Matr[0].index[1], Matr[0].index[4], Matr[0].index[7], Matr[3].index[1], Matr[3].index[4], Matr[3].index[7],
	Matr[5].index[1], Matr[5].index[4], Matr[5].index[7], Matr[1].index[1], Matr[1].index[4], Matr[1].index[7]};
	for(int i = 1; i <= 7; i += 3){ Matr[3].color[i] = a[j++]; Matr[3].index[i] = b[k++];}
	for(int i = 1; i <= 7; i += 3){ Matr[5].color[i] = a[j++]; Matr[5].index[i] = b[k++];}
	for(int i = 1; i <= 7; i += 3){ Matr[1].color[i] = a[j++]; Matr[1].index[i] = b[k++];}
	for(int i = 1; i <= 7; i += 3){ Matr[0].color[i] = a[j++]; Matr[0].index[i] = b[k++];}
}

void Model::Rw_color()
{
	int j = 0, k = 0;
	string a[12] = {Matr[0].color[2], Matr[0].color[5], Matr[0].color[8], Matr[3].color[2], Matr[3].color[5], Matr[3].color[8],
	Matr[5].color[2], Matr[5].color[5], Matr[5].color[8], Matr[1].color[2], Matr[1].color[5], Matr[1].color[8]};
	int b[12] = {Matr[0].index[2], Matr[0].index[5], Matr[0].index[8], Matr[3].index[2], Matr[3].index[5], Matr[3].index[8],
	Matr[5].index[2], Matr[5].index[5], Matr[5].index[8], Matr[1].index[2], Matr[1].index[5], Matr[1].index[8]};
	string c[12] = {Matr[0].color[1], Matr[0].color[4], Matr[0].color[7], Matr[3].color[1], Matr[3].color[4], Matr[3].color[7],
	Matr[5].color[1], Matr[5].color[4], Matr[5].color[7], Matr[1].color[1], Matr[1].color[4], Matr[1].color[7]};
	int d[12] = {Matr[0].index[1], Matr[0].index[4], Matr[0].index[7], Matr[3].index[1], Matr[3].index[4], Matr[3].index[7],
	Matr[5].index[1], Matr[5].index[4], Matr[5].index[7], Matr[1].index[1], Matr[1].index[4], Matr[1].index[7]};
	for(int i = 2, z = 1; i <= 8; i += 3, z += 3){ Matr[3].color[i] = a[j]; Matr[3].index[i] = b[j++]; Matr[3].color[z] = c[k]; Matr[3].index[z] = d[k++];}
	for(int i = 2, z = 1; i <= 8; i += 3, z += 3){ Matr[5].color[i] = a[j]; Matr[5].index[i] = b[j++]; Matr[5].color[z] = c[k]; Matr[5].index[z] = d[k++];}
	for(int i = 2, z = 1; i <= 8; i += 3, z += 3){ Matr[1].color[i] = a[j]; Matr[1].index[i] = b[j++]; Matr[1].color[z] = c[k]; Matr[1].index[z] = d[k++];}
	for(int i = 2, z = 1; i <= 8; i += 3, z += 3){ Matr[0].color[i] = a[j]; Matr[0].index[i] = b[j++]; Matr[0].color[z] = c[k]; Matr[0].index[z] = d[k++];}
}

void Model::Rw_color_stroke()
{
    int j = 0, k = 0;
	string a[12] = {Matr[0].color[2], Matr[0].color[5], Matr[0].color[8], Matr[3].color[2], Matr[3].color[5], Matr[3].color[8],
	Matr[5].color[2], Matr[5].color[5], Matr[5].color[8], Matr[1].color[2], Matr[1].color[5], Matr[1].color[8]};
	int b[12] = {Matr[0].index[2], Matr[0].index[5], Matr[0].index[8], Matr[3].index[2], Matr[3].index[5], Matr[3].index[8],
	Matr[5].index[2], Matr[5].index[5], Matr[5].index[8], Matr[1].index[2], Matr[1].index[5], Matr[1].index[8]};
	string c[12] = {Matr[0].color[1], Matr[0].color[4], Matr[0].color[7], Matr[3].color[1], Matr[3].color[4], Matr[3].color[7],
	Matr[5].color[1], Matr[5].color[4], Matr[5].color[7], Matr[1].color[1], Matr[1].color[4], Matr[1].color[7]};
	int d[12] = {Matr[0].index[1], Matr[0].index[4], Matr[0].index[7], Matr[3].index[1], Matr[3].index[4], Matr[3].index[7],
	Matr[5].index[1], Matr[5].index[4], Matr[5].index[7], Matr[1].index[1], Matr[1].index[4], Matr[1].index[7]};
	for(int i = 2, z = 1; i <= 8; i += 3, z += 3){ Matr[1].color[i] = a[j]; Matr[1].index[i] = b[j++]; Matr[1].color[z] = c[k]; Matr[1].index[z] = d[k++];}
	for(int i = 2, z = 1; i <= 8; i += 3, z += 3){ Matr[0].color[i] = a[j]; Matr[0].index[i] = b[j++]; Matr[0].color[z] = c[k]; Matr[0].index[z] = d[k++];}
	for(int i = 2, z = 1; i <= 8; i += 3, z += 3){ Matr[3].color[i] = a[j]; Matr[3].index[i] = b[j++]; Matr[3].color[z] = c[k]; Matr[3].index[z] = d[k++];}
	for(int i = 2, z = 1; i <= 8; i += 3, z += 3){ Matr[5].color[i] = a[j]; Matr[5].index[i] = b[j++]; Matr[5].color[z] = c[k]; Matr[5].index[z] = d[k++];}
}

void Model::Right_color()
{
	int j = 0, k = 0;
	string a[12] = {Matr[0].color[2], Matr[0].color[5], Matr[0].color[8], Matr[3].color[2], Matr[3].color[5], Matr[3].color[8],
	Matr[5].color[2], Matr[5].color[5], Matr[5].color[8], Matr[1].color[2], Matr[1].color[5], Matr[1].color[8]};
	int b[12] = {Matr[0].index[2], Matr[0].index[5], Matr[0].index[8], Matr[3].index[2], Matr[3].index[5], Matr[3].index[8],
	Matr[5].index[2], Matr[5].index[5], Matr[5].index[8], Matr[1].index[2], Matr[1].index[5], Matr[1].index[8]};
	for(int i = 2; i <= 8; i += 3){ Matr[3].color[i] = a[j++]; Matr[3].index[i] = b[k++];}
	for(int i = 2; i <= 8; i += 3){ Matr[5].color[i] = a[j++]; Matr[5].index[i] = b[k++];}
	for(int i = 2; i <= 8; i += 3){ Matr[1].color[i] = a[j++]; Matr[1].index[i] = b[k++];}
	for(int i = 2; i <= 8; i += 3){ Matr[0].color[i] = a[j++]; Matr[0].index[i] = b[k++];}
}

void Model::Right_color_stroke()
{
    int j = 0, k = 0;
	string a[12] = {Matr[0].color[2], Matr[0].color[5], Matr[0].color[8], Matr[3].color[2], Matr[3].color[5], Matr[3].color[8],
	Matr[5].color[2], Matr[5].color[5], Matr[5].color[8], Matr[1].color[2], Matr[1].color[5], Matr[1].color[8]};
	int b[12] = {Matr[0].index[2], Matr[0].index[5], Matr[0].index[8], Matr[3].index[2], Matr[3].index[5], Matr[3].index[8],
	Matr[5].index[2], Matr[5].index[5], Matr[5].index[8], Matr[1].index[2], Matr[1].index[5], Matr[1].index[8]};
	for(int i = 2; i <= 8; i += 3){ Matr[1].color[i] = a[j++]; Matr[1].index[i] = b[k++];}
	for(int i = 2; i <= 8; i += 3){ Matr[0].color[i] = a[j++]; Matr[0].index[i] = b[k++];}
	for(int i = 2; i <= 8; i += 3){ Matr[3].color[i] = a[j++]; Matr[3].index[i] = b[k++];}
	for(int i = 2; i <= 8; i += 3){ Matr[5].color[i] = a[j++]; Matr[5].index[i] = b[k++];}
}

void Model::Lw_color()
{
	int j = 0, k = 0;
	string a[12] = {Matr[0].color[0], Matr[0].color[3], Matr[0].color[6], Matr[3].color[0], Matr[3].color[3], Matr[3].color[6],
	Matr[5].color[0], Matr[5].color[3], Matr[5].color[6], Matr[1].color[0], Matr[1].color[3], Matr[1].color[6]};
	int b[12] = {Matr[0].index[0], Matr[0].index[3], Matr[0].index[6], Matr[3].index[0], Matr[3].index[3], Matr[3].index[6],
	Matr[5].index[0], Matr[5].index[3], Matr[5].index[6], Matr[1].index[0], Matr[1].index[3], Matr[1].index[6]};
	string c[12] = {Matr[0].color[1], Matr[0].color[4], Matr[0].color[7], Matr[3].color[1], Matr[3].color[4], Matr[3].color[7],
	Matr[5].color[1], Matr[5].color[4], Matr[5].color[7], Matr[1].color[1], Matr[1].color[4], Matr[1].color[7]};
	int d[12] = {Matr[0].index[1], Matr[0].index[4], Matr[0].index[7], Matr[3].index[1], Matr[3].index[4], Matr[3].index[7],
	Matr[5].index[1], Matr[5].index[4], Matr[5].index[7], Matr[1].index[1], Matr[1].index[4], Matr[1].index[7]};
	for(int i = 0, z = 1; i <= 6; i += 3, z += 3){ Matr[1].color[i] = a[j]; Matr[1].index[i] = b[j++]; Matr[1].color[z] = c[k]; Matr[1].index[z] = d[k++];}
	for(int i = 0, z = 1; i <= 6; i += 3, z += 3){ Matr[0].color[i] = a[j]; Matr[0].index[i] = b[j++]; Matr[0].color[z] = c[k]; Matr[0].index[z] = d[k++];}
	for(int i = 0, z = 1; i <= 6; i += 3, z += 3){ Matr[3].color[i] = a[j]; Matr[3].index[i] = b[j++]; Matr[3].color[z] = c[k]; Matr[3].index[z] = d[k++];}
	for(int i = 0, z = 1; i <= 6; i += 3, z += 3){ Matr[5].color[i] = a[j]; Matr[5].index[i] = b[j++]; Matr[5].color[z] = c[k]; Matr[5].index[z] = d[k++];}
}

void Model::Lw_color_stroke()
{
    int j = 0, k = 0;
	string a[12] = {Matr[0].color[0], Matr[0].color[3], Matr[0].color[6], Matr[3].color[0], Matr[3].color[3], Matr[3].color[6],
	Matr[5].color[0], Matr[5].color[3], Matr[5].color[6], Matr[1].color[0], Matr[1].color[3], Matr[1].color[6]};
	int b[12] = {Matr[0].index[0], Matr[0].index[3], Matr[0].index[6], Matr[3].index[0], Matr[3].index[3], Matr[3].index[6],
	Matr[5].index[0], Matr[5].index[3], Matr[5].index[6], Matr[1].index[0], Matr[1].index[3], Matr[1].index[6]};
	string c[12] = {Matr[0].color[1], Matr[0].color[4], Matr[0].color[7], Matr[3].color[1], Matr[3].color[4], Matr[3].color[7],
	Matr[5].color[1], Matr[5].color[4], Matr[5].color[7], Matr[1].color[1], Matr[1].color[4], Matr[1].color[7]};
	int d[12] = {Matr[0].index[1], Matr[0].index[4], Matr[0].index[7], Matr[3].index[1], Matr[3].index[4], Matr[3].index[7],
	Matr[5].index[1], Matr[5].index[4], Matr[5].index[7], Matr[1].index[1], Matr[1].index[4], Matr[1].index[7]};
	for(int i = 0, z = 1; i <= 6; i += 3, z += 3){ Matr[3].color[i] = a[j]; Matr[3].index[i] = b[j++]; Matr[3].color[z] = c[k]; Matr[3].index[z] = d[k++];}
	for(int i = 0, z = 1; i <= 6; i += 3, z += 3){ Matr[5].color[i] = a[j]; Matr[5].index[i] = b[j++]; Matr[5].color[z] = c[k]; Matr[5].index[z] = d[k++];}
	for(int i = 0, z = 1; i <= 6; i += 3, z += 3){ Matr[1].color[i] = a[j]; Matr[1].index[i] = b[j++]; Matr[1].color[z] = c[k]; Matr[1].index[z] = d[k++];}
	for(int i = 0, z = 1; i <= 6; i += 3, z += 3){ Matr[0].color[i] = a[j]; Matr[0].index[i] = b[j++]; Matr[0].color[z] = c[k]; Matr[0].index[z] = d[k++];}
}

void Model::Left_color()
{
	int j = 0, k = 0;
	string a[12] = {Matr[0].color[0], Matr[0].color[3], Matr[0].color[6], Matr[3].color[0], Matr[3].color[3], Matr[3].color[6],
	Matr[5].color[0], Matr[5].color[3], Matr[5].color[6], Matr[1].color[0], Matr[1].color[3], Matr[1].color[6]};
	int b[12] = {Matr[0].index[0], Matr[0].index[3], Matr[0].index[6], Matr[3].index[0], Matr[3].index[3], Matr[3].index[6],
	Matr[5].index[0], Matr[5].index[3], Matr[5].index[6], Matr[1].index[0], Matr[1].index[3], Matr[1].index[6]};
	for(int i = 0; i <= 6; i += 3){ Matr[1].color[i] = a[j++]; Matr[1].index[i] = b[k++];}
	for(int i = 0; i <= 6; i += 3){ Matr[0].color[i] = a[j++]; Matr[0].index[i] = b[k++];}
	for(int i = 0; i <= 6; i += 3){ Matr[3].color[i] = a[j++]; Matr[3].index[i] = b[k++];}
	for(int i = 0; i <= 6; i += 3){ Matr[5].color[i] = a[j++]; Matr[5].index[i] = b[k++];}
}

void Model::Left_color_stroke()
{
    int j = 0, k = 0;
	string a[12] = {Matr[0].color[0], Matr[0].color[3], Matr[0].color[6], Matr[3].color[0], Matr[3].color[3], Matr[3].color[6],
	Matr[5].color[0], Matr[5].color[3], Matr[5].color[6], Matr[1].color[0], Matr[1].color[3], Matr[1].color[6]};
	int b[12] = {Matr[0].index[0], Matr[0].index[3], Matr[0].index[6], Matr[3].index[0], Matr[3].index[3], Matr[3].index[6],
	Matr[5].index[0], Matr[5].index[3], Matr[5].index[6], Matr[1].index[0], Matr[1].index[3], Matr[1].index[6]};
	for(int i = 0; i <= 6; i += 3){ Matr[3].color[i] = a[j++]; Matr[3].index[i] = b[k++];}
	for(int i = 0; i <= 6; i += 3){ Matr[5].color[i] = a[j++]; Matr[5].index[i] = b[k++];}
	for(int i = 0; i <= 6; i += 3){ Matr[1].color[i] = a[j++]; Matr[1].index[i] = b[k++];}
	for(int i = 0; i <= 6; i += 3){ Matr[0].color[i] = a[j++]; Matr[0].index[i] = b[k++];}
}

void Model::Fw_color()
{
	int j = 0, k = 0;
	string a[12] = {Matr[0].color[6], Matr[0].color[7], Matr[0].color[8], Matr[4].color[6], Matr[4].color[3], Matr[4].color[0],
	Matr[5].color[0], Matr[5].color[1], Matr[5].color[2], Matr[2].color[8], Matr[2].color[5], Matr[2].color[2]};
	int b[12] = {Matr[0].index[6], Matr[0].index[7], Matr[0].index[8], Matr[4].index[6], Matr[4].index[3], Matr[4].index[0],
	Matr[5].index[0], Matr[5].index[1], Matr[5].index[2], Matr[2].index[8], Matr[2].index[5], Matr[2].index[2]};
	string c[12] = {Matr[0].color[3], Matr[0].color[4], Matr[0].color[5], Matr[4].color[7], Matr[4].color[4], Matr[4].color[1],
	Matr[5].color[3], Matr[5].color[4], Matr[5].color[5], Matr[2].color[7], Matr[2].color[4], Matr[2].color[1]};
	int d[12] = {Matr[0].index[3], Matr[0].index[4], Matr[0].index[5], Matr[4].index[7], Matr[4].index[4], Matr[4].index[1],
	Matr[5].index[3], Matr[5].index[4], Matr[5].index[5], Matr[2].index[7], Matr[2].index[4], Matr[2].index[1]};
	for(int i = 0, z = 1; i <= 6; i += 3, z += 3){ Matr[4].color[i] = a[j]; Matr[4].index[i] = b[j++]; Matr[4].color[z] = c[k]; Matr[4].index[z] = d[k++];}
	for(int i = 0, z = 3; i < 3; i++, z++){ Matr[5].color[i] = a[j]; Matr[5].index[i] = b[j++]; Matr[5].color[z] = c[k]; Matr[5].index[z] = d[k++];}
	for(int i = 2, z = 1; i <= 8; i += 3, z += 3){ Matr[2].color[i] = a[j]; Matr[2].index[i] = b[j++]; Matr[2].color[z] = c[k]; Matr[2].index[z] = d[k++];} 
	for(int i = 6, z = 3; i < 9; i++, z++){ Matr[0].color[i] = a[j]; Matr[0].index[i] = b[j++]; Matr[0].color[z] = c[k]; Matr[0].index[z] = d[k++];}
}

void Model::Fw_color_stroke()
{
    int j = 0, k = 0;
	string a[12] = {Matr[0].color[8], Matr[0].color[7], Matr[0].color[6], Matr[4].color[0], Matr[4].color[3], Matr[4].color[6],
	Matr[5].color[2], Matr[5].color[1], Matr[5].color[0], Matr[2].color[2], Matr[2].color[5], Matr[2].color[8]};
	int b[12] = {Matr[0].index[8], Matr[0].index[7], Matr[0].index[6], Matr[4].index[0], Matr[4].index[3], Matr[4].index[6],
	Matr[5].index[2], Matr[5].index[1], Matr[5].index[0], Matr[2].index[2], Matr[2].index[5], Matr[2].index[8]};
	string c[12] = {Matr[0].color[5], Matr[0].color[4], Matr[0].color[3], Matr[4].color[1], Matr[4].color[4], Matr[4].color[7],
	Matr[5].color[5], Matr[5].color[4], Matr[5].color[3], Matr[2].color[1], Matr[2].color[4], Matr[2].color[7]};
	int d[12] = {Matr[0].index[5], Matr[0].index[4], Matr[0].index[3], Matr[4].index[1], Matr[4].index[4], Matr[4].index[7],
	Matr[5].index[5], Matr[5].index[4], Matr[5].index[3], Matr[2].index[1], Matr[2].index[4], Matr[2].index[7]};
	for(int i = 2, z = 1; i <= 8; i += 3, z += 3){ Matr[2].color[i] = a[j]; Matr[2].index[i] = b[j++]; Matr[2].color[z] = c[k]; Matr[2].index[z] = d[k++];} 
	for(int i = 6, z = 3; i < 9; i++, z++){ Matr[0].color[i] = a[j]; Matr[0].index[i] = b[j++]; Matr[0].color[z] = c[k]; Matr[0].index[z] = d[k++];}
	for(int i = 0, z = 1; i <= 6; i += 3, z += 3){ Matr[4].color[i] = a[j]; Matr[4].index[i] = b[j++]; Matr[4].color[z] = c[k]; Matr[4].index[z] = d[k++];}
	for(int i = 0, z = 3; i < 3; i++, z++){ Matr[5].color[i] = a[j]; Matr[5].index[i] = b[j++]; Matr[5].color[z] = c[k]; Matr[5].index[z] = d[k++];}
}

void Model::Front_color()
{
	int j = 0, k = 0;
	string a[12] = {Matr[0].color[6], Matr[0].color[7], Matr[0].color[8], Matr[4].color[6], Matr[4].color[3], Matr[4].color[0],
	Matr[5].color[0], Matr[5].color[1], Matr[5].color[2], Matr[2].color[8], Matr[2].color[5], Matr[2].color[2]};
	int b[12] = {Matr[0].index[6], Matr[0].index[7], Matr[0].index[8], Matr[4].index[6], Matr[4].index[3], Matr[4].index[0],
	Matr[5].index[0], Matr[5].index[1], Matr[5].index[2], Matr[2].index[8], Matr[2].index[5], Matr[2].index[2]};
	for(int i = 0; i <= 6; i += 3){ Matr[4].color[i] = a[j++]; Matr[4].index[i] = b[k++];}
	for(int i = 0; i < 3; i++){ Matr[5].color[i] = a[j++]; Matr[5].index[i] = b[k++];}
	for(int i = 2; i <= 8; i += 3){ Matr[2].color[i] = a[j++]; Matr[2].index[i] = b[k++];}
	for(int i = 6; i < 9; i++){ Matr[0].color[i] = a[j++]; Matr[0].index[i] = b[k++];}
}

void Model::Front_color_stroke()
{
    int j = 0, k = 0;
	string a[12] = {Matr[0].color[8], Matr[0].color[7], Matr[0].color[6], Matr[4].color[0], Matr[4].color[3], Matr[4].color[6],
	Matr[5].color[2], Matr[5].color[1], Matr[5].color[0], Matr[2].color[2], Matr[2].color[5], Matr[2].color[8]};
	int b[12] = {Matr[0].index[8], Matr[0].index[7], Matr[0].index[6], Matr[4].index[0], Matr[4].index[3], Matr[4].index[6],
	Matr[5].index[2], Matr[5].index[1], Matr[5].index[0], Matr[2].index[2], Matr[2].index[5], Matr[2].index[8]};
	for(int i = 2; i <= 8; i += 3){ Matr[2].color[i] = a[j++]; Matr[2].index[i] = b[k++];}
	for(int i = 6; i < 9; i++){ Matr[0].color[i] = a[j++]; Matr[0].index[i] = b[k++];}
	for(int i = 0; i <= 6; i += 3){ Matr[4].color[i] = a[j++]; Matr[4].index[i] = b[k++];}
	for(int i = 0; i < 3; i++){ Matr[5].color[i] = a[j++]; Matr[5].index[i] = b[k++];}
}

void Model::Bw_color()
{
	int j = 0, k = 0;
	string a[12] = {Matr[0].color[2], Matr[0].color[1], Matr[0].color[0], Matr[4].color[2], Matr[4].color[5], Matr[4].color[8],
	Matr[5].color[8], Matr[5].color[7], Matr[5].color[6], Matr[2].color[0], Matr[2].color[3], Matr[2].color[6]};
	int b[12] = {Matr[0].index[2], Matr[0].index[1], Matr[0].index[0], Matr[4].index[2], Matr[4].index[5], Matr[4].index[8],
	Matr[5].index[8], Matr[5].index[7], Matr[5].index[6], Matr[2].index[0], Matr[2].index[3], Matr[2].index[6]};
	string c[12] = {Matr[0].color[5], Matr[0].color[4], Matr[0].color[3], Matr[4].color[1], Matr[4].color[4], Matr[4].color[7],
	Matr[5].color[5], Matr[5].color[4], Matr[5].color[3], Matr[2].color[1], Matr[2].color[4], Matr[2].color[7]};
	int d[12] = {Matr[0].index[5], Matr[0].index[4], Matr[0].index[3], Matr[4].index[1], Matr[4].index[4], Matr[4].index[7],
	Matr[5].index[5], Matr[5].index[4], Matr[5].index[3], Matr[2].index[1], Matr[2].index[4], Matr[2].index[7]};
	for(int i = 0, z = 1; i <= 6; i += 3, z += 3){ Matr[2].color[i] = a[j]; Matr[2].index[i] = b[j++]; Matr[2].color[z] = c[k]; Matr[2].index[z] = d[k++];}
	for(int i = 0, z = 3; i < 3; i++, z++){ Matr[0].color[i] = a[j]; Matr[0].index[i] = b[j++]; Matr[0].color[z] = c[k]; Matr[0].index[z] = d[k++];}
	for(int i = 2, z = 1; i <= 8; i += 3, z += 3){ Matr[4].color[i] = a[j]; Matr[4].index[i] = b[j++]; Matr[4].color[z] = c[k]; Matr[4].index[z] = d[k++];}
	for(int i = 6, z = 3; i < 9; i++, z++){ Matr[5].color[i] = a[j]; Matr[5].index[i] = b[j++]; Matr[5].color[z] = c[k]; Matr[5].index[z] = d[k++];}
}

void Model::Bw_color_stroke()
{
    int j = 0, k = 0;
	string a[12] = {Matr[0].color[0], Matr[0].color[1], Matr[0].color[2], Matr[4].color[8], Matr[4].color[5], Matr[4].color[2],
	Matr[5].color[6], Matr[5].color[7], Matr[5].color[8], Matr[2].color[6], Matr[2].color[3], Matr[2].color[0]};
	int b[12] = {Matr[0].index[0], Matr[0].index[1], Matr[0].index[2], Matr[4].index[8], Matr[4].index[5], Matr[4].index[2],
	Matr[5].index[6], Matr[5].index[7], Matr[5].index[8], Matr[2].index[6], Matr[2].index[3], Matr[2].index[0]};
	string c[12] = {Matr[0].color[3], Matr[0].color[4], Matr[0].color[5], Matr[4].color[7], Matr[4].color[4], Matr[4].color[1],
	Matr[5].color[3], Matr[5].color[4], Matr[5].color[5], Matr[2].color[7], Matr[2].color[4], Matr[2].color[1]};
	int d[12] = {Matr[0].index[3], Matr[0].index[4], Matr[0].index[5], Matr[4].index[7], Matr[4].index[4], Matr[4].index[1],
	Matr[5].index[3], Matr[5].index[4], Matr[5].index[5], Matr[2].index[7], Matr[2].index[4], Matr[2].index[1]};
	for(int i = 2, z = 1; i <= 8; i += 3, z += 3){ Matr[4].color[i] = a[j]; Matr[4].index[i] = b[j++]; Matr[4].color[z] = c[k]; Matr[4].index[z] = d[k++];}
	for(int i = 6, z = 3; i < 9; i++, z++){ Matr[5].color[i] = a[j]; Matr[5].index[i] = b[j++]; Matr[5].color[z] = c[k]; Matr[5].index[z] = d[k++];}
	for(int i = 0, z = 1; i <= 6; i += 3, z += 3){ Matr[2].color[i] = a[j]; Matr[2].index[i] = b[j++]; Matr[2].color[z] = c[k]; Matr[2].index[z] = d[k++];}
	for(int i = 0, z = 3; i < 3; i++, z++){ Matr[0].color[i] = a[j]; Matr[0].index[i] = b[j++]; Matr[0].color[z] = c[k]; Matr[0].index[z] = d[k++];}
}

void Model::Back_color()
{
	int j = 0, k = 0;
	string a[12] = {Matr[0].color[2], Matr[0].color[1], Matr[0].color[0], Matr[4].color[2], Matr[4].color[5], Matr[4].color[8],
	Matr[5].color[8], Matr[5].color[7], Matr[5].color[6], Matr[2].color[0], Matr[2].color[3], Matr[2].color[6]};
	int b[12] = {Matr[0].index[2], Matr[0].index[1], Matr[0].index[0], Matr[4].index[2], Matr[4].index[5], Matr[4].index[8],
	Matr[5].index[8], Matr[5].index[7], Matr[5].index[6], Matr[2].index[0], Matr[2].index[3], Matr[2].index[6]};
	for(int i = 0; i <= 6; i += 3){ Matr[2].color[i] = a[j++]; Matr[2].index[i] = b[k++];}
	for(int i = 0; i < 3; i++){ Matr[0].color[i] = a[j++]; Matr[0].index[i] = b[k++];}
	for(int i = 2; i <= 8; i += 3){ Matr[4].color[i] = a[j++]; Matr[4].index[i] = b[k++];}
	for(int i = 6; i < 9; i++){ Matr[5].color[i] = a[j++]; Matr[5].index[i] = b[k++];}
}

void Model::Back_color_stroke()
{
    int j = 0, k = 0;
	string a[12] = {Matr[0].color[0], Matr[0].color[1], Matr[0].color[2], Matr[4].color[8], Matr[4].color[5], Matr[4].color[2],
	Matr[5].color[6], Matr[5].color[7], Matr[5].color[8], Matr[2].color[6], Matr[2].color[3], Matr[2].color[0]};
	int b[12] = {Matr[0].index[0], Matr[0].index[1], Matr[0].index[2], Matr[4].index[8], Matr[4].index[5], Matr[4].index[2],
	Matr[5].index[6], Matr[5].index[7], Matr[5].index[8], Matr[2].index[6], Matr[2].index[3], Matr[2].index[0]};
	for(int i = 2; i <= 8; i += 3){ Matr[4].color[i] = a[j++]; Matr[4].index[i] = b[k++];}
	for(int i = 6; i < 9; i++){ Matr[5].color[i] = a[j++]; Matr[5].index[i] = b[k++];}
	for(int i = 0; i <= 6; i += 3){ Matr[2].color[i] = a[j++]; Matr[2].index[i] = b[k++];}
	for(int i = 0; i < 3; i++){ Matr[0].color[i] = a[j++]; Matr[0].index[i] = b[k++];}
}

int Model::Turn(int facet, string& str)
{
	if(facet == current_facet)
		return 0;
	if((current_facet == 1 && facet == 3) || (current_facet == 3 && facet == 1) ||
	(current_facet == 2 && facet == 4) || (current_facet == 4 && facet == 2))
	{	str.append(" y2"); return 0;}
	if(facet == 1)
		current_facet == 4 ? str.append(" y") : str.append(" y'");
	if(facet == 4)
		current_facet == 3 ? str.append(" y") : str.append(" y'");
	if(facet == 3)
		current_facet == 2 ? str.append(" y") : str.append(" y'");
	if(facet == 2)
		current_facet == 1 ? str.append(" y") : str.append(" y'");
	return 0;
}

int Model::Turn_md(Position x, int facet, string& str, int flag)
{
	if(x.facet == 5 && flag == 2)
	{
		if((x.position == 8 && facet == 3) || (x.position == 6 && facet == 4) || 
		(x.position == 2 && facet == 1) || (x.position == 4 && facet == 2))
			return 0;
		if((x.position == 4 && facet == 4) || (x.position == 8 && facet == 1) || 
		(x.position == 6 && facet == 2) || (x.position == 2 && facet == 3))
		{	str.append(" u2"); return 0;}
		if(facet == 1)
			x.position == 4 ? str.append(" u") : str.append(" u'");
		if(facet == 2)
			x.position == 2 ? str.append(" u'") : str.append(" u");
		if(facet == 3)
			x.position == 6 ? str.append(" u") : str.append(" u'");
		if(facet == 4)
			x.position == 8 ? str.append(" u'") : str.append(" u");
		return 0;
	}
	if(x.facet == 5 && flag)
	{
		if((x.position == 6 && facet == 3) || (x.position == 2 && facet == 4) || 
		(x.position == 4 && facet == 1) || (x.position == 8 && facet == 2))
			return 0;
		if((x.position == 4 && facet == 4) || (x.position == 8 && facet == 1) || 
		(x.position == 6 && facet == 2) || (x.position == 2 && facet == 3))
		{	str.append(" u2"); return 0;}
		if(facet == 1)
			x.position == 8 ? str.append(" u") : str.append(" u'");
		if(facet == 2)
			x.position == 4 ? str.append(" u'") : str.append(" u");
		if(facet == 3)
			x.position == 2 ? str.append(" u") : str.append(" u'");
		if(facet == 4)
			x.position == 6 ? str.append(" u'") : str.append(" u");
		return 0;
	}
	if(x.facet == facet)
		return 0;
	if((x.facet == 1 && facet == 3) || (x.facet == 2 && facet == 4) || 
	(x.facet == 3 && facet == 1) || (x.facet == 4 && facet == 2))
	{	str.append(" u2"); return 0;}
	if(facet == 1)
		x.facet == 2 ? str.append(" u") : str.append(" u'");
	if(facet == 2)
		x.facet == 1 ? str.append(" u'") : str.append(" u");
	if(facet == 3)
		x.facet == 4 ? str.append(" u") : str.append(" u'");
	if(facet == 4)
		x.facet == 3 ? str.append(" u'") : str.append(" u");
	return 0;
}

int Model::Turn_up(string col, int ind, int pos, string& str)
{
	Position x = Find_part(col, ind);
	if(x.facet != 0)
		return 0;
	if(x.position == pos)
		return 0;
	if((x.position == 2 && pos == 8) || (x.position == 8 && pos == 2) || 
	(x.position == 4 && pos == 6) || (x.position == 6 && pos == 4))
	{	str.append(" u2"); return 0;}
	if(pos == 2)
		x.position == 4 ? str.append(" u") : str.append(" u'");
	if(pos == 4)
		x.position == 2 ? str.append(" u'") : str.append(" u");
	if(pos == 6)
		x.position == 2 ? str.append(" u") : str.append(" u'");
	if(pos == 8)
		x.position == 4 ? str.append(" u'") : str.append(" u");
	return 0;
}

int Model::Turn_up(Position x, int pos, string& str)
{
	if(x.facet != 5)
		return 0;
	if(x.position == pos)
		return 0;
	if((x.position == 2 && pos == 8) || (x.position == 8 && pos == 2) || 
	(x.position == 4 && pos == 6) || (x.position == 6 && pos == 4))
	{	str.append(" u2"); return 0;}
	if(pos == 2)
		x.position == 4 ? str.append(" u") : str.append(" u'");
	if(pos == 4)
		x.position == 2 ? str.append(" u'") : str.append(" u");
	if(pos == 6)
		x.position == 2 ? str.append(" u") : str.append(" u'");
	if(pos == 8)
		x.position == 4 ? str.append(" u'") : str.append(" u");
	return 0;
}

int Model::Turn_up(int ind, int pos, string& str)
{
	Position x = Find_part("orange", ind);
	if(x.facet != 5)
		return 0;
	if(x.position == pos)
		return 0;
	if((x.position == 2 && pos == 8) || (x.position == 8 && pos == 2) || 
	(x.position == 4 && pos == 6) || (x.position == 6 && pos == 4))
	{	str.append(" u2"); return 0;}
	if(pos == 2)
		x.position == 4 ? str.append(" u") : str.append(" u'");
	if(pos == 4)
		x.position == 2 ? str.append(" u'") : str.append(" u");
	if(pos == 6)
		x.position == 2 ? str.append(" u") : str.append(" u'");
	if(pos == 8)
		x.position == 4 ? str.append(" u'") : str.append(" u");
	return 0;
}

int Model::Turn_down(string col, int ind, int pos, string& str)
{
	Position x = Find_part(col, ind);
	if(x.facet != 5)
		return 0;
	if(x.position == pos)
		return 0;
	if((x.position == 2 && pos == 8) || (x.position == 8 && pos == 2) || 
	(x.position == 4 && pos == 6) || (x.position == 6 && pos == 4))
	{	str = " d2"; return 0;}
	if(pos == 2)
		x.position == 4 ? str = " d'" : str = " d";
	if(pos == 4)
		x.position == 2 ? str = " d'" : str = " d";
	if(pos == 6)
		x.position == 2 ? str = " d" : str = " d'";
	if(pos == 8)
		x.position == 4 ? str = " d" : str = " d'";
	return 0;
}

string Model::Turn_corners(Position x, Position y, int pos)
{
	string str;
	if(x.facet == 5 && y.facet == 5 && (y.position == 2 ? x.position == 3 : (y.position == 4 ? x.position == 1 : (y.position == 6 ? x.position == 9 : x.position == 7))))
	{
		Turn_up(y, pos == 1 ? 8 : (pos == 3 ? 6 : (pos == 7 ? 4 : 2)), str);
		return str;
	}
	if(x.facet == 5 && y.facet == 5 && (y.position == 2 ? x.position == 7 : (y.position == 4 ? x.position == 9 : (y.position == 6 ? x.position == 1 : x.position == 3))))
	{
		Turn_up(y, pos == 1 ? 8 : (pos == 3 ? 6 : (pos == 7 ? 4 : 2)), str);
		return str;
	}
	if(x.facet == 5 && y.facet != 5 && (y.facet == 1 ? x.position == 7 : (y.facet == 2 ? x.position == 9 : (y.facet == 3 ? x.position == 3 : x.position == 1))))
	{
		Turn_md(y, pos == 1 ? 2 : (pos == 3 ? 3 : (pos == 7 ? 1 : 4)), str);
		return str;
	}
	if(x.facet == 5 && y.facet != 5 && (y.facet == 1 ? x.position == 9 : (y.facet == 2 ? x.position == 3 : (y.facet == 3 ? x.position == 1 : x.position == 7))))
	{
		Turn_md(y, pos == 1 ? 2 : (pos == 3 ? 3 : (pos == 7 ? 1 : 4)), str);
		return str;
	}
	if(x.facet == 5)
	{
		if(x.position == pos - 6 || x.position == pos + 6)
			return "";
		if((x.position == 1 && pos == 3) || (x.position == 3 && pos == 1) || 
		(x.position == 7 && pos == 9) || (x.position == 9 && pos == 7))
		{	return " u2";}
		if(pos == 1)
			x.position == 9 ? str = " u" : str = " u'";
		if(pos == 3)
			x.position == 3 ? str = " u" : str = " u'";
		if(pos == 7)
			x.position == 3 ? str = " u'" : str = " u";
		if(pos == 9)
			x.position == 9 ? str = " u'" : str = " u";
		return str;
	}
	if(x.position == (x.facet == 3 ? 3 : 7))
	{
		if((x.facet == 3 && pos == 3) || (x.facet == 4 && pos == 9) || 
		(x.facet == 1 && pos == 7) || (x.facet == 2 && pos == 1))
			return "";
		if((x.facet == 1 && pos == 3) || (x.facet == 2 && pos == 9) || 
		(x.facet == 3 && pos == 7) || (x.facet == 4 && pos == 1))
		{	return " u2";}
		if(pos == 1)
			x.facet == 3 ? str = " u" : str = " u'";
		if(pos == 3)
			x.facet == 4 ? str = " u" : str = " u'";
		if(pos == 7)
			x.facet == 4 ? str = " u'" : str = " u";
		if(pos == 9)
			x.facet == 3 ? str = " u'" : str = " u";
		return str;
	}
	if(x.position == (x.facet == 3 ? 1 : 9))
	{
		if((x.facet == 4 && pos == 3) || (x.facet == 1 && pos == 9) || 
		(x.facet == 2 && pos == 7) || (x.facet == 3 && pos == 1))
			return "";
		if((x.facet == 1 && pos == 1) || (x.facet == 2 && pos == 3) || 
		(x.facet == 3 && pos == 9) || (x.facet == 4 && pos == 7))
		{	return " u2";}
		if(pos == 1)
			x.facet == 4 ? str = " u" : str = " u'";
		if(pos == 3)
			x.facet == 1 ? str = " u" : str = " u'";
		if(pos == 7)
			x.facet == 1 ? str = " u'" : str = " u";
		if(pos == 9)
			x.facet == 4 ? str = " u'" : str = " u";
		return str;
	}
	return "";
}

int Model::Turn_corners(Position x, int pos, string& str)
{
	if(x.position == pos)
		return 0;
	if((x.position == 1 && pos == 9) || (x.position == 9 && pos == 1) || 
	(x.position == 3 && pos == 7) || (x.position == 7 && pos == 3))
	{	str = " u2"; return 0;}
	if(pos == 1)
		x.position == 7 ? str = " u" : str = " u'";
	if(pos == 3)
		x.position == 1 ? str = " u" : str = " u'";
	if(pos == 7)
		x.position == 1 ? str = " u'" : str = " u";
	if(pos == 9)
		x.position == 7 ? str = " u'" : str = " u";
	return 0;
}

int Model::Turn_corners(string col, int ind, int pos, string& str)
{
	Position x = Find_part(col, ind);
	if(x.position == pos)
		return 0;
	if((x.position == 9 && pos == 1) || (x.position == 7 && pos == 3) || 
	(x.position == 7 && pos == 3) || (x.position == 1 && pos == 9))
	{	str = " u2"; return 0;}
	if(pos == 1)
		x.position == 7 ? str = " u" : str = " u'";
	if(pos == 3)
		x.position == 1 ? str = " u" : str = " u'";
	if(pos == 7)
		x.position == 1 ? str = " u'" : str = " u";
	if(pos == 9)
		x.position == 7 ? str = " u'" : str = " u";
	return 0;
}

Position Model::Find_part(Col pos)
{
	Position k;
	for(int i = 0; i < 6; i++)
	{
		for(int j = 0; j < 9; j++)
		{
			k.position = j + 1; k.facet = i;
			if(Matr[i].color[j] == pos.col && Matr[i].index[j] == pos.ind)
				return k;
		}
	}
	k.position = 0; k.facet = 0;
	return k;
}

Position Model::Find_part(string str, int ind)
{
	Position k;
	for(int i = 0; i < 6; i++)
	{
		for(int j = 0; j < 9; j++)
		{
			k.position = j + 1; k.facet = i;
			if(Matr[i].color[j] == str && Matr[i].index[j] == ind)
				return k;
		}
	}
	k.position = 0; k.facet = 0;
	return k;
}

Position Model::Find_part(string str, int ind, int facet)
{
	Position k;
	for(int j = 0; j < 9; j++)
	{
		k.position = j + 1; k.facet = facet;
		if(Matr[facet].color[j] == str && Matr[facet].index[j] == ind)
			return k;
	}
	k.position = 0; k.facet = 0;
	return k;
}

bool Model::Check_part(string str, int ind)
{
	if(ind == 1)
	{
		if(Matr[0].color[2] == str)
			if(Matr[0].index[2] == ind)
				return 0;
		if(Matr[0].color[6] == str)
			if(Matr[0].index[6] == ind)
				return 0;
		if(Matr[0].color[8] == str)
			if(Matr[0].index[8] == ind)
				return 0;
		if(Matr[3].color[8] == str)
			if(Matr[3].index[8] == ind)
				return 0;
		if(Matr[4].color[0] == str)
			if(Matr[4].index[0] == ind)
				return 0;
		if(Matr[1].color[0] == str)
			if(Matr[1].index[0] == ind)
				return 0;
		if(Matr[4].color[2] == str)
			if(Matr[4].index[2] == ind)
				return 0;
		if(Matr[1].color[2] == str)
			if(Matr[1].index[2] == ind)
				return 0;
		if(Matr[2].color[2] == str)
			if(Matr[2].index[2] == ind)
				return 0;
		return 1;
	}	
	if(ind == 3)
	{
		if(Matr[0].color[0] == str)
			if(Matr[0].index[0] == ind)
				return 0;
		if(Matr[0].color[6] == str)
			if(Matr[0].index[6] == ind)
				return 0;
		if(Matr[0].color[8] == str)
			if(Matr[0].index[8] == ind)
				return 0;
		if(Matr[3].color[6] == str)
			if(Matr[3].index[6] == ind)
				return 0;
		if(Matr[4].color[0] == str)
			if(Matr[4].index[0] == ind)
				return 0;
		if(Matr[1].color[0] == str)
			if(Matr[1].index[0] == ind)
				return 0;
		if(Matr[2].color[0] == str)
			if(Matr[2].index[0] == ind)
				return 0;
		if(Matr[1].color[2] == str)
			if(Matr[1].index[2] == ind)
				return 0;
		if(Matr[2].color[2] == str)
			if(Matr[2].index[2] == ind)
				return 0;
		return 1;
	}
	if(ind == 7)
	{
		if(Matr[0].color[2] == str)
			if(Matr[0].index[2] == ind)
				return 0;
		if(Matr[0].color[0] == str)
			if(Matr[0].index[0] == ind)
				return 0;
		if(Matr[0].color[8] == str)
			if(Matr[0].index[8] == ind)
				return 0;
		if(Matr[3].color[8] == str)
			if(Matr[3].index[8] == ind)
				return 0;
		if(Matr[4].color[0] == str)
			if(Matr[4].index[0] == ind)
				return 0;
		if(Matr[3].color[6] == str)
			if(Matr[3].index[6] == ind)
				return 0;
		if(Matr[4].color[2] == str)
			if(Matr[4].index[2] == ind)
				return 0;
		if(Matr[1].color[2] == str)
			if(Matr[1].index[2] == ind)
				return 0;
		if(Matr[2].color[0] == str)
			if(Matr[2].index[0] == ind)
				return 0;
		return 1;
	}
	if(ind == 9)
	{
		if(Matr[0].color[2] == str)
			if(Matr[0].index[2] == ind)
				return 0;
		if(Matr[0].color[6] == str)
			if(Matr[0].index[6] == ind)
				return 0;
		if(Matr[0].color[0] == str)
			if(Matr[0].index[0] == ind)
				return 0;
		if(Matr[3].color[8] == str)
			if(Matr[3].index[8] == ind)
				return 0;
		if(Matr[3].color[6] == str)
			if(Matr[3].index[6] == ind)
				return 0;
		if(Matr[1].color[0] == str)
			if(Matr[1].index[0] == ind)
				return 0;
		if(Matr[4].color[2] == str)
			if(Matr[4].index[2] == ind)
				return 0;
		if(Matr[2].color[0] == str)
			if(Matr[2].index[0] == ind)
				return 0;
		if(Matr[2].color[2] == str)
			if(Matr[2].index[2] == ind)
				return 0;
		return 1;
	}
	return 0;
}

bool Model::Check_part(string str, int ind, int facet)
{
	return Matr[facet].color[--ind] == str;
}

// bool Model::checkNum(const int num)
// {
// 	return (num / 10000 == 0 && num / 1000 != 0) && !((num / 1000 == num / 100 % 10) 
// 			&& (num / 100 % 10 == num / 10 % 10) && (num / 10 % 10 == num % 10));
// }

// void Model::Sort(int num, int &num_min, int &num_max)
// {
// 	int digit;
// 	int digits[4];
// 	for (int i = 0; i < 4; i++) 
// 	{
// 		digit = num / (int(pow(10, i))) % 10;
// 		digits[i] = digit;
// 	}
// 	for (int i = 0; i < 3; i++) 
// 	{
// 		for (int j = 0; j < 3 - i; j++) 
// 		{
// 			if (digits[j] < digits[j + 1]) 
// 				swap(digits[j], digits[j + 1]);
// 		}
// 	}
// 	num_max = digits[0] * 1000 + digits[1] * 100 + digits[2] * 10 + digits[3];
// 	num_min = digits[3] * 1000 + digits[2] * 100 + digits[1] * 10 + digits[0];
// }

// int Model::Kaprek(int num, int &num_min, int &num_max)
// {
// 	Sort(num, num_min, num_max);
// 	num = num_max - num_min;
// 	return num;
// }

// void Model::getMatr()
// {
// 	int num = 0, num_min = 0, num_max = 0, j = 0, m = 0;
// 	for(int i = 0; i < n; i++)
// 	{
// 		if(checkNum(a[i]))
// 		{
// 			num = a[i];
// 			while(num != 6174)
// 			{
// 				num = Kaprek(num, num_min, num_max);
// 				Matr[i][++j] = num_max;
// 				Matr[i][++j] = num_min;
// 				m++;
// 			}
// 			Matr[i][++j] = num;
// 			Matr[i][0] = m;
// 			j = 0;
// 			m = 0;
// 		}
// 	}
// }

ostream& operator << (ostream& out, const Model& m)
{
	for (int i = 0; i < 6; i++) 
	{
        out << m.Matr[i] << " ";
		out << endl;
	}
	return out;
}