#pragma once
#include <iostream>
#include <utility>
#include <memory.h>

using namespace std;

//----------------------------------------------------------

class KNode
  {public:
    explicit KNode(int aInfo = int(), int aNext = int()) {}
    int info;
    int next;
  };
//----------------------------------------------------------
constexpr int DEFAULT_MEMORY_SIZE = 100;

class KListOnArrayIterator;

class KListOnArray
  {
   public:
    friend class KListOnArrayIterator;
    explicit KListOnArray (int n__ = DEFAULT_MEMORY_SIZE);
            ~KListOnArray () { delete[] fArr; }

           void PushFront (int x);
           void PushBack (int x);
    inline void PopFront ();
           int& Front () const     { return fArr[b].info; }
           int& Back() const { return fArr[e].info; }
           bool IsEmpty () const { return b == -1; }
    inline void Swap (KListOnArray& aList);

           bool IsEmptyFree() const { return bFree == -1; }
    inline void PushFree (int ind);
    inline  int PopFree ();

    KListOnArrayIterator CreateIterator();

    friend ostream& operator << (ostream& os, KListOnArray const& lst);

   private:
    // Для случая расширения памяти при переполнении
    void Extend();

   private:
    KNode * fArr;
        int n;          // размер массива (памяти)
        int b = -1;     // Индекс первого элемента списка элементов
        int e = -1;     // Индекс последнего элемента списка элементов
        int bFree = -1; // Индекс первого элемента списка свободных элементов 
  };

inline void KListOnArray::PopFront()
  {
   auto k = b;
   b = fArr[b].next;
   PushFree(k);
  }

inline void KListOnArray::PushFree(int ind)
  {
   fArr[ind].next = bFree;
   bFree = ind;
  }

inline void KListOnArray::Swap(KListOnArray& aList)
  {
   swap(fArr, aList.fArr);
   swap(n, aList.n);
   swap(b, aList.b);
   swap(e, aList.e);
   swap(bFree, aList.bFree);
  }

inline int KListOnArray::PopFree()
  {
   int k = bFree;
   bFree = fArr[bFree].next;
   return k;
  }


//----------------------------------------------------------------------------

class KListOnArrayIterator
  {public:
     friend class KListOnArray;

     KListOnArrayIterator(): fList(nullptr) {}

     void First () { iCur = fList->b; }
     void Next () { iCur = fList->fArr[iCur].next; }
     bool IsDone () { return iCur == -1; }
      int CurrentItem () { return fList->fArr[iCur].info;  }

   private:
     KListOnArrayIterator (KListOnArray * aList, int i): fList(aList), iCur(i) {}
   private:
     KListOnArray * fList;
     mutable    int iCur;   // Индекс текущего элемента списка
  };
