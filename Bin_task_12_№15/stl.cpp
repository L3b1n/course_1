#include <iostream>
#include <queue>

using namespace std;

class KNode
{
public:
    KNode() : fInfo(0), fNext(nullptr) {}
    explicit KNode(int aInfo) : fInfo(aInfo), fNext(nullptr) {}
    KNode(int aInfo, KNode * aNext) : fInfo(aInfo), fNext(aNext) {}

    int fInfo;
    KNode * fNext;
};

class KStl
{
public:
    KStl() : first(nullptr), pLast(&first) {}
    ~KStl() { Erase(first); }

    void PushFront(int x)
    {
        first = new KNode(x, first);
        if (first->fNext == nullptr) pLast = &first->fNext;
    }

    void PushBack(int x)
    { 
        pLast = &(*pLast = new KNode(x))->fNext;
    }

    int Length()
    {
        int i = 0;
        KNode *p = first;
        while(p)
        {
            p = p->fNext;
            i++;
        }
        return i;
    }

    void PushInto(int x, int pos)
    {
        int i = 0;
        KNode *pCur = first;
        KNode *p;
        while(pCur)
        {
            if(i == pos - 1)
            {
                *pCur = *(new KNode(x));
                //while(pCur)
                //{
                //    pCur = pCur->fNext;
                //}
            }
            pCur = pCur->fNext;
            i++;
        }
    }

    void Push(KStl const& al1, KStl const& al2)
    { 
        KNode *p = al1.first;
        KNode *t = al2.first;
        while (p != nullptr || t != nullptr)
        {
            if(p != nullptr)
            {
                PushBack(p->fInfo);
                p = p->fNext;
            }
            if(t != nullptr)
            {
                PushBack(t->fInfo);
                t = t->fNext;
            }
        }
    }

    void Del(int a)
    {
        KNode ** pPrev = &first;
        KNode * p = first;
        while (p)
        {
            p = p->fNext;
            if ((*pPrev)->fInfo == a)
            {
                pPrev = &(*pPrev)->fNext;
                while (p)
                {
                    p = p->fNext;
                    delete *pPrev;
                    if (p == nullptr)
                        pLast = &*pPrev;
                    *pPrev = p;
                }
            }
            else
                pPrev = &(*pPrev)->fNext;
        }
    }

    bool PopFront()
    {
        if (IsEmpty()) return false;
        else 
        {
            KNode * p = first;
            first = first->fNext;
            if (first == nullptr) pLast = &first;
            delete p;
            return true;
        }
    }

    bool PopBackIneffective(int x) { return true; }
          int& Front()       { return first->fInfo; }
    int const& Front() const { return first->fInfo; }
          int& Back()        { return ((KNode *)(((char *)pLast) - offsetof(KNode, fNext)))->fInfo; }
    int const& Back() const  { return ((KNode *)(((char *)pLast) - offsetof(KNode, fNext)))->fInfo; }

    bool IsEmpty() const { return first == nullptr; }

    void Print() const
    {   
        KNode * p = first;
        while (p != nullptr)
        { 
            cout << p->fInfo << " ";
            p = p->fNext;
        }
        cout << endl;
    }

    int Sum() const
    {
        int c = 0;
        KNode * p = first;
        while (p != nullptr)
        { 
            c += p->fInfo;
            p = p->fNext;
        }
        return c;
    }

    // Из списка удалить все элементы >= a
    void Del_Great(int a)
    {
        KNode ** pPrev = &first;
        KNode * p = first;
        while (p)
        {
            p = p->fNext;
            if ((*pPrev)->fInfo >= a)
            {
                delete *pPrev;
                if (p == nullptr)
                    pLast = &*pPrev;
                *pPrev = p;
            }
            else
            pPrev = &(*pPrev)->fNext;
        }
    }


    void Clear()
    {
        Erase(first);
        pLast = &first;
    }
    friend
    ostream& operator << (ostream& os, KStl const& lst)
    {
        KNode * p = lst.first;
        while (p)
        {
            os << p->fInfo << " ";
            p = p->fNext;
        }
        return os;
    }

private:
    void Erase(KNode *& pCur)
    {
        while (pCur != nullptr)
        {
            KNode * p = pCur;
            pCur = pCur->fNext;
            delete p;
        }
    }
    
private:
    KNode * first; 
    KNode ** pLast; 
};