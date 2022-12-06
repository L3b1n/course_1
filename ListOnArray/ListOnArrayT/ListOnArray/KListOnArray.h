#pragma once
#include <iostream>
#include <memory.h>

using namespace std;

//----------------------------------------------------------
template <typename T>
class KNode
  {public:
    explicit KNode(T aInfo = T(), int aNext = int()) {}
    T info;
    int next;
  };
//----------------------------------------------------------

constexpr int DEFAULT_MEMORY_SIZE = 100;

template <typename T>
class KListOnArray;

template <typename T>
ostream& operator << (ostream& os, KListOnArray<T> const& lst);

template <typename T>
class KListOnArrayIterator;

template <typename T>
class KListOnArray
  {
   public:
    friend class KListOnArrayIterator<T>;
    explicit KListOnArray (int n__ = DEFAULT_MEMORY_SIZE);
            ~KListOnArray () { delete[] fArr; }

           void PushFront (T x);
           void PushBack (T x);
    inline void PopFront ();
            T& Front () const     { return fArr[b].info; }
            T& Back ()  const     { return fArr[b].info; }
            bool IsEmpty () const { return b == -1; }
     inline void Swap(KListOnArray<T>& aList);

           bool IsEmptyFree() const { return bFree == -1; }
    inline void PushFree (int ind);
    inline  int PopFree ();

    KListOnArrayIterator<T> CreateIterator();

    friend ostream& ::operator << (ostream& os, KListOnArray<T> const& lst);  // !!!!!!!!!

   private:
    // Для случая расширения памяти при переполнении
    void Extend();

   private:
    KNode<T> *fArr;
        int n;          // размер массива (памяти)
        int b = -1;     // Индекс первого элемента списка элементов
        int e = -1;     // Индекс последнего элемента списка элементов
        int bFree = -1; // Индекс первого элемента списка свободных элементов 
  };
//-------------------------------------------------------------------------------------

template <typename T>
inline void KListOnArray<T>::PopFront()
  {
   auto k = b;
   b = fArr[b].next;
   PushFree(k);
  }

template <typename T>
inline void KListOnArray<T>::PushFree(int ind)
  {
   fArr[ind].next = bFree;
   bFree = ind;
  }
template <typename T>
inline void KListOnArray<T>::Swap(KListOnArray& aList)
  {
   swap(fArr, aList.fArr);
   swap(n, aList.n);
   swap(b, aList.b);
   swap(e, aList.e);
   swap(bFree, aList.bFree);
  }

template <typename T>
inline int KListOnArray<T>::PopFree()
  {
   int k = bFree;
   bFree = fArr[bFree].next;
   return k;
  }


//----------------------------------------------------------------------------

template <typename T>
KListOnArray<T>::KListOnArray(int n__)
  {
   fArr = new KNode<T>[n = n__];
   // Создаем список свободных элементов
   for (int i = 0; i < n - 1; ++i)
    fArr[i].next = i + 1;
   fArr[n - 1].next = -1;
   bFree = 0;
  }

template <typename T>
void KListOnArray<T>::PushFront(T x)
  {
   if (IsEmptyFree())  // Нет свободных элементов
     { Extend(); /* Увеличить объём памяти */ }
   int i = PopFree();  // Получить элемент из списка свободных элементов
   fArr[i].info = x;
   fArr[i].next = b;
   b = i;
   if (fArr[b].next == -1) e = b;
  }

template <typename T>
void KListOnArray<T>::PushBack(T x)
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

template <typename T>
ostream& operator << (ostream& os, KListOnArray<T> const& lst)
  {
   auto p = lst.b;
   while (p >= 0)
     { cout << lst.fArr[p].info << " ";
       p = lst.fArr[p].next;
     }
   return os;
  }

template <typename T>
void KListOnArray<T>::Extend()
  {
   KNode<T> * p = new KNode<T>[2*n];
   // Копируем fArr в p
   memcpy_s(p, 2*n*sizeof(KNode<T>), fArr, n*sizeof(KNode<T>));
   for (int i = n; i < 2*n-1; ++i)
     { p[i].next = i + 1; }
   p[2*n-1].next = bFree;
   bFree = n;
   delete []fArr;
   fArr = p;
   n = 2*n;
  }

template <typename T>
KListOnArrayIterator<T> KListOnArray<T>::CreateIterator() { return KListOnArrayIterator<T>(this, b); }


template <typename T>
class KListOnArrayIterator
  {public:
     friend class KListOnArray<T>;

     KListOnArrayIterator(): fList(nullptr) {}

     void First () { iCur = fList->b; }
     void Next () { iCur = fList->fArr[iCur].next; }
     bool IsDone () { return iCur == -1; }
      T CurrentItem () { return fList->fArr[iCur].info;  }

   private:
     KListOnArrayIterator (KListOnArray<T> * aList, int i): fList(aList), iCur(i) {}
   private:
     KListOnArray<T> * fList;
     mutable    int iCur;   // Индекс текущего элемента списка
  };
