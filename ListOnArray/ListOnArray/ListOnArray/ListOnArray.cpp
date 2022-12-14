// ListOnArray.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "KListOnArray.h"

int main()
  {
   // KListOnArray lx = 7;  // Если у конструктора убрать explicit, 
                            // то эта странная инициализация будет допустимой
   KListOnArray lx(1);
   lx.PushBack(31);
   lx.PushBack(12);
   lx.PushFront(44);
   lx.PushBack(20);
   lx.PushBack(30);
   lx.PushBack(40);
   cout << lx << endl;
   auto it = lx.CreateIterator();
   for (it.First(); !it.IsDone(); it.Next())
     cout << it.CurrentItem() << " ";
   cout << endl;
   cout << lx.Front() << " " << lx.Back() << endl;
   lx.Front() = 99;
   lx.Back() = 777;
   cout << lx.Front() << " " << lx.Back() << endl;

   while (!lx.IsEmpty())
     { cout << lx.Front() << " "; 
       lx.PopFront();
     }
   cout << endl;

   lx.PushBack(77);
   lx.PushFront(66);
   cout << lx << endl;

   return 0;
  }

