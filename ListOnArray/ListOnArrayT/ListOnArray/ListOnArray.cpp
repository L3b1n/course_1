// ListOnArray.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "KListOnArray.h"

int main()
  {
   // KListOnArray lx = 7;  // Если у конструктора убрать explicit, 
                            // то эта странная инициализация будет допустимой
   KListOnArray<double> lx(1);
   lx.PushBack(31.6);
   lx.PushBack(12.7);
   lx.PushFront(44.1);
   lx.PushBack(20.3);
   lx.PushBack(30.8);
   lx.PushBack(40.6);
   cout << lx << endl;
   auto it = lx.CreateIterator();
   for (it.First(); !it.IsDone(); it.Next())
     cout << it.CurrentItem() << " ";
   cout << endl;
   while (!lx.IsEmpty())
     { cout << lx.Front() << " "; 
       lx.PopFront();
     }
   cout << endl;

   lx.PushBack(77.4);
   lx.PushFront(66.9);
   cout << lx << endl;

   return 0;
  }

