//-----------------------------------------------------------
//  Добавлен итератор
//-----------------------------------------------------------

//#include "stdafx.h"
#include <iostream>
#include <algorithm>
//#include <queue>
//#include "windows.h"
#include "SimpleList4.cpp"

using namespace std;


int main()
  {
   //SetConsoleOutputCP(1251);
   //SetConsoleCP(1251);
   //queue<int> q;

   KSimpleList l;

  //  int n;
  //  cout << "Введите n: ";
  //  cin >> n;
  //  cout << "Введите " << n << " целых чисел:" << endl;
  //  for (int i = 0; i < n; ++i)
  //    {
  //     int x;
  //     cin >> x;
  //     l.PushBack(x);
  //    }
  //  l.PushFront(666);
  //  l.Print();
  //  cout << endl;
  //  cout << "l.Back()=" << l.Back() << endl;
  //  cout << "l.Front()=" << l.Front() << endl;
  //  l.Front() = 888;
  //  l.Back() = 999;
  //  cout << l << endl;
  //  cout << endl;
  //  l.Clear();
   cout << "***";
   l.Print();
   cout << "===" << endl;
   l.PushFront(11);
   l.PushFront(221);
   l.PushFront(21);
   l.PushFront(121);
   l.PushBack(1000);
   l.PushBack(817);
   l.PushBack(777);
   l.Print();
   l.Sort();
   cout << "\n" << l;
   l.Invers(3);
   cout << "\n" << l << endl;
   int i = l.Number(3);
   cout << i << endl;
  //  KSimpleList ls3(l);
  //  cout << "ls3 = " << ls3 << "***" << endl;
  //  KSimpleList ls4 = l;
  //  cout << "lst4 = " << ls4 << "***" << endl;
  //  //for (int x : ls4) cout << x << " ";
  //  cout << endl;
  //  while (!l.IsEmpty())
  //   {
  //     cout << l.Front() << endl;
  //     l.PopFront();
  //   }
  //  cout << "***";
  //  l.Print();
  //  cout << "===" << endl;

   //for (auto x : { 4,6, 7, 3,12,10 })
   //  l.PushBack(x);

   //auto[min_it, max_it](minmax_element(begin(l), end(l)));
   //cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << *min_it << " - " << *max_it << '\n';

   return 0;
  }



