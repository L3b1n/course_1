#pragma once
#include <iostream>
#include <algorithm>


class KNode
{
public:
 KNode() : fInfo(0), fNext(nullptr) {}
 explicit KNode(int aInfo) : fInfo(aInfo), fNext(nullptr) {}
 KNode(int aInfo, KNode * aNext) : fInfo(aInfo), fNext(aNext) {}

 int fInfo;
 KNode * fNext;
};

class KSimpleList;

class KSmpListIterator //: public std::iterator<std::forward_iterator_tag, int>
  {
    friend class KSimpleList;
   public:
    using iterator_category = std::forward_iterator_tag;
    using value_type = int;
    using difference_type = ptrdiff_t;
    using pointer = int *;
    using reference = int &;

   public:
    KSmpListIterator() : fpCur(nullptr) { }
    //KListIterator (const KListIterator& it);
    ~KSmpListIterator() {}

    //KListIterator& operator =  (const KListIterator& it);
    inline KSmpListIterator&      operator ++ ();         // prefix operator
    inline KSmpListIterator const operator ++ (int);      // postfix operator

    inline bool       operator != (const KSmpListIterator& it) const;
    inline bool       operator == (const KSmpListIterator& it) const;
    inline int const& operator * () const;
    inline int&       operator * ();
          int *       operator -> () { return &fpCur->fInfo; }
    int const *       operator -> () const { return &fpCur->fInfo; }

   private:
    KSmpListIterator(KSimpleList * l, KNode * first, KNode ** adrFirst);
    KSmpListIterator(const KSimpleList * l, KNode * nd, KNode ** adrLast)
     : fpList((KSimpleList *)l), fpCur(nd), fppPrev(adrLast) {}
   private:
    KSimpleList * fpList;
    KNode  * fpCur;
    KNode ** fppPrev;
  };

// ------------------------ end of KListIterator -------------------------------


inline KSmpListIterator& KSmpListIterator::operator ++ ()       // prefix operator
  {
   if (fpCur)
     {fppPrev = &fpCur->fNext;
      fpCur = fpCur->fNext;
     }
   return *this;
  }

inline KSmpListIterator const KSmpListIterator::operator ++ (int)       // postfix operator
  {
   KSmpListIterator tmp(*this);
   ++*this;
   return tmp;
  }


inline bool KSmpListIterator::operator != (const KSmpListIterator& it) const
  {
   return fpCur != it.fpCur;
  }

inline bool KSmpListIterator::operator == (const KSmpListIterator& it) const
  {
   return !(*this != it);
  }

inline int const& KSmpListIterator::operator * () const
  {
   return fpCur->fInfo;
  }

inline int&  KSmpListIterator::operator * ()
  {
   return fpCur->fInfo;
  }

class KSimpleList
  {
  public:
   //typedef KSmpListIterator iterator;
   //friend class iterator;

          KSimpleList () : first(NULL), pLast(&first) {}
   inline KSimpleList (KSimpleList const& aLst);
         ~KSimpleList () { Erase(first); }

          void PushFront (int x);
   inline void PushBack (int x);
          void Push(KSimpleList const& al1, KSimpleList const& al2);
          void PushInto(int x, int pos);

          bool PopFront();

   bool PopBackIneffective(int x) { /* �������� ��� ���� */ return true; }

         int& Front() { return first->fInfo; }
   int const& Front() const { return first->fInfo; }
         int& Back() { return ((KNode *)(((char *)pLast) - offsetof(KNode, fNext)))->fInfo; }
   int const& Back() const { return ((KNode *)(((char *)pLast) - offsetof(KNode, fNext)))->fInfo; }

         bool IsEmpty() const { return first == NULL/*nullptr*/; }

   inline void Swap(KSimpleList& aLst2);

   KSimpleList& operator = (KSimpleList const& aLst2);

   const int& operator [] (const int pos) const;

   int& operator [] (const int pos);

   void Print() const;

   KSimpleList& Read(int n);

   int Sum() const;

   int Min();

   int Max();

   void Clear();

   int Length();

   void Sort();

   int Number(int pos);

   void DelTail(int a);

   void Swap(int pos1, int pos2);

   void Invers();

   void Invers(int pos1);

   void Invers(int pos1, int pos2);

   void DelNum(int a);

   void Delete(int pos);

   //iterator begin() { return iterator(this, first, &first); } // ���������� �������� �� ������ ������

   //iterator   end() { return iterator(this, nullptr, pLast); }

   friend
    std::ostream& operator << (std::ostream& os, KSimpleList const& lst);

  private:
   void Erase(KNode *& pCur);
   void Copy(KNode * aFirst);

  private:
   KNode * first; // ��������� �� ������ ������� ������
   KNode ** pLast; // ��������� �� ���� fNext ���������� 
                   // �������� ������
  };

  inline KSimpleList::KSimpleList(KSimpleList const& aLst) : first(NULL/*nullptr*/), pLast(&first)
  {
    Copy(aLst.first);
  }
  inline void KSimpleList::Swap(KSimpleList& aLst2)
  {
    std::swap(first, aLst2.first);
    std::swap(pLast, aLst2.pLast);
  } 