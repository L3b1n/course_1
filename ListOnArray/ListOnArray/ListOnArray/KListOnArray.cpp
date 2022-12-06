#include "stdafx.h"
#include "KListOnArray.h"


KListOnArray::KListOnArray(int n__)
  {
   fArr = new KNode[n = n__];
   // Создаем список свободных элементов
   for (int i = 0; i < n - 1; ++i)
     fArr[i].next = i + 1;
   fArr[n - 1].next = -1;
   bFree = 0;
  }

void KListOnArray::PushFront(int x)
  {
   if (IsEmptyFree())  // Нет свободных элементов
     { Extend(); /* Увеличить объём памяти */ }
   int i = PopFree();  // Получить элемент из списка свободных элементов
   fArr[i].info = x;
   fArr[i].next = b;
   b = i;
   if (fArr[b].next == -1) e = b;
  }

void KListOnArray::PushBack(int x)
  {
   if (IsEmptyFree())  // Нет свободных элементов
     { Extend(); /* Увеличить объём памяти */ }
   int i = PopFree();  // Получить элемент из списка свободных элементов  
   fArr[i].info = x;
   fArr[i].next = -1;
   if (b != -1)
     { fArr[e].next = i; }
   else
     b = i;
   e = i;
  }

ostream& operator << (ostream& os, KListOnArray const& lst)
{
 auto p = lst.b;
 while (p >= 0)
 {
  cout << lst.fArr[p].info << " ";
  p = lst.fArr[p].next;
 }
 return os;
}

void KListOnArray::Extend()
  {
   KNode * p = new KNode[2*n];
   // Копируем fArr в p
   memcpy_s(p, 2*n*sizeof(KNode), fArr, n*sizeof(KNode));
   for (int i = n; i < 2*n-1; ++i)
     { p[i].next = i + 1; }
   p[2*n-1].next = bFree;
   bFree = n;
   delete[]fArr;
   fArr = p;
   n = 2*n;
  }

KListOnArrayIterator KListOnArray::CreateIterator() { return KListOnArrayIterator(this, b); }

