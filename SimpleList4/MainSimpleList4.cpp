#include <iostream>
#include <algorithm>
#include "SimpleList4.cpp"

using namespace std;


int main()
{
  int n;
  KSimpleList l, lst1, lst2;
  cout << "Enter n: ";
  cin >> n;
  l.Read(n);
  l.Print();
  cout << endl;
  l.Sort();
  l.Print();
  cout << endl;
  l.Invers(0, 2);
  l.Print();
  cout << endl;
  // for(int i = 0; i < l.Length(); i++)
  // {
  //   if(i % 2 != 0)
  //     lst2.PushBack(l[i]);
  //   else
  //     lst1.PushBack(l[i]);
  // }
  // int g = lst1.Length();
  // cout << g << endl;
  // lst1.Print();
  // cout << endl;
  // lst2.Print();
  // cout << endl;
  // int min = lst2[0];
  // for(int i = 0; i < lst1.Length(); i++)
  // {
  //   if(i % 2 == 0 && min < lst1[i])
  //     min = lst1[i];
  // }
  // cout << min << endl;
  // // 1 2 3 4 5 6 7 8 9
  // return 0;
}