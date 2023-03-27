#include "SimpleList4.h"
#include <cmath>

KSmpListIterator::KSmpListIterator(KSimpleList * l, KNode * first, KNode ** adrFirst)
 : fpList(l), fpCur(first), fppPrev(adrFirst) {}

// ------------------------ end of KListIterator -------------------------------


void KSimpleList::PushFront(int x) //вставить в начало списка число
{
  first = new KNode(x, first);
  if (first->fNext == NULL/*nullptr*/) pLast = &first->fNext;
}

inline void KSimpleList::PushBack(int x) //вставить в конец списка число
{
  pLast = &(*pLast = new KNode(x))->fNext;
}

void KSimpleList::PushInto(int x, int pos) //вставить в определенное место число
{
  int i = 0;
  KSimpleList tm;
  KNode *pCur = first;
  KNode *p;
  while(pCur)
  {
    if(i == pos) tm.PushBack(x);
    tm.PushBack(pCur->fInfo);
    pCur = pCur->fNext;
    i++;
  }
  if(pos >= Length()){tm.PushBack(x);}
  *this = tm;
  tm.Clear();
}

void KSimpleList::Push(KSimpleList const& al1, KSimpleList const& al2) //создать новый список из двух(1, 2, 1, 2....)
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

bool KSimpleList::PopFront() //
{
  if (IsEmpty()) return false;
  else // ������ �� ������
  {
    KNode *p = first;
    first = first->fNext;
    if (first == nullptr) pLast = &first;
    delete p;
    return true;
  }
}

KSimpleList& KSimpleList::operator = (KSimpleList const& aLst2) //оператор копирования одного списка другому
{
  if (this != &aLst2)
  { 
    KSimpleList t(aLst2);
    Swap(t);
  }
  return *this;
}

void KSimpleList::Print() const //вывести на экран
{
  KNode *p = first;
  while (p != NULL/*nullptr*/)
  {
    std::cout << p->fInfo << " ";
    p = p->fNext;
  }
}

KSimpleList& KSimpleList::Read(int n) //заполнение списка с клавиатуры
{
  for (int i = 0; i < n; ++i)
  {
    int x;
    std::cin >> x;
    PushBack(x);
  }
  return *this;
}

int KSimpleList::Sum() const //сумма всех членов списка
{
  int c = 0;
  KNode *p = first;
  while (p != NULL/*nullptr*/)
  {
    c += p->fInfo;
    p = p->fNext;
  }
  return c;
}

void KSimpleList::Clear() //удаление списка
{
  Erase(first);
  pLast = &first;
}

std::ostream& operator << (std::ostream& os, KSimpleList const& lst) //вывод на экран, через cout
{
  KNode *p = lst.first;
  while (p)
  {
    os << p->fInfo << " ";
    p = p->fNext;
  }
  return os;
}

void KSimpleList::Erase(KNode *& pCur) //функция для clear
{
  while (pCur != NULL/*nullptr*/)
  {
    KNode *p = pCur;
    pCur = pCur->fNext;
    delete p;
  }
}

int KSimpleList::Length() //нахождение длинны списка
{
  int i = 0;
  KNode *p = first;
  while(p){p = p->fNext; i++;}
  return i;
}

void KSimpleList::Copy(KNode * aFirst) //функция копирования
{
  while (aFirst)
  {
    PushBack(aFirst->fInfo);
    aFirst = aFirst->fNext;
  }
}

void KSimpleList::Sort() //сортировка списка
{
  int len = Length();
  for (int i = 0; i < len - 1; i++){for(int j = 0; j < len - i - 1; j++){if(Number(j) > Number(j + 1)) Swap(j, j + 1);} } 
}

int KSimpleList::Min() //нахождение минимального элемента
{
  KNode *p = first;
  int min = p->fInfo;
  while(p){if(abs(p->fInfo) < min) min = p->fInfo; p = p->fNext;}
  return min;
}

int KSimpleList::Max() //нахождение максимального элемента
{
  KNode *p = first;
  int max = p->fInfo;
  while(p){if(abs(p->fInfo) > max) max = p->fInfo; p = p->fNext;}
  return max;
}

void KSimpleList::Invers() //инверсия всего списка
{
  int len = Length();
  if((len - 1) % 2 == 0)
    for (int i = 0, j = len - 1; i < (len - 1) / 2; i++){Swap(i, j); j--;}
  else
    for (int i = 0, j = len - 1; i <= (len - 1) / 2; i++){Swap(i, j); j--;}
}

void KSimpleList::Invers(int pos1) //инверсия списка начиная с определенного места и до конца
{
  int len = Length() - 1 - pos1;
  if((len - 1 - pos1) % 2 == 0)
    for (int i = pos1, j = len - 1; i < (len - 1) / 2; i++){Swap(i, j); j--;}
  else
    for (int i = pos1, j = len - 1; i <= (len - 1) / 2; i++){Swap(i, j); j--;}
}

void KSimpleList::Invers(int pos1, int pos2) //инверсия части списка
{
  int len = pos2 - pos1;
  if((pos2 - pos1) % 2 == 0)
    for (int i = pos1, j = pos2; i < (len - 1) / 2; i++){Swap(i, j); j--;}
  else
    for (int i = pos1, j = pos2; i <= (len - 1) / 2; i++){Swap(i, j); j--;}
}

int KSimpleList::Number(int pos) //вызов числа стоящего под определенным индексом
{
  int i = 0;
  KNode *p = first;
  while(i != pos){p = p->fNext; i++;}
  return p->fInfo;
}

int& KSimpleList::operator [] (const int pos) //вызов числа стоящего под определенным индексом
{
  int i = 0;
  KNode *p = first;
  while(i != pos){p = p->fNext; i++;}
  return p->fInfo; 
}

const int& KSimpleList::operator [] (const int pos) const //вызов числа стоящего под определенным индексом
{
  int i = 0;
  KNode *p = first;
  while(i != pos){p = p->fNext; i++;}
  return p->fInfo; 
}

void KSimpleList::Swap(int pos1, int pos2) //обмен переменных стоящих под определенными индексами
{
  int num1 = Number(pos1), num2 = Number(pos2);
  Delete(pos1);
  PushInto(num1, pos2);
  Delete(pos2 - 1);
  PushInto(num2, pos1);
}

void KSimpleList::DelTail(int a) //функция удаления всех последующих чисел, после определенного
{
  KNode **pPrev = &first;
  while((*pPrev)->fInfo != a){pPrev = &(*pPrev)->fNext;}
  pPrev = &(*pPrev)->fNext;
  Erase(*pPrev);
}

void KSimpleList::Delete(int pos) //функция удаления числа определенного идекса
{
  int i = 0;
  KNode **pPrev = &first;
  KNode *p = first;
  while (p)
  {
    p = p->fNext;
    if (i == pos){delete *pPrev; if(p == nullptr) pLast = &*pPrev; *pPrev = p;}
    else pPrev = &(*pPrev)->fNext; 
    i++;
  }
}

void KSimpleList::DelNum(int a) //функция удаления чисел равных заданному
{
  KNode **pPrev = &first;
  KNode *p = first;
  while (p)
  {
    p = p->fNext;
    if ((*pPrev)->fInfo == a){delete *pPrev; if (p == nullptr) pLast = &*pPrev; *pPrev = p;}
    else
      pPrev = &(*pPrev)->fNext;
  }
}