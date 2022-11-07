#include <iostream>
#include <chrono>
#include <list>
#include <vector>

using namespace std;

struct KNode
{
	explicit KNode(int aData = 0, KNode * aNext = nullptr) : data(aData), next(aNext) {}

	int data;
	KNode *next;
};

class KrvList
{
	KNode *pBeg;
	KNode *pEnd;

public:
	KrvList() { pBeg = pEnd = nullptr;}
	KrvList(int item) { pBeg = pEnd = nullptr; push_back(item);}
	KrvList(const KrvList& b)
	{ 
		KNode *cur = b.pBeg;
		pBeg = pEnd = nullptr;
		while(cur){ push_back(cur->data);cur = cur->next;}
	}

	KrvList(KrvList&& b) 
	{ 
		pEnd = b.pEnd;
		pBeg = b.pBeg;
		b.pBeg = b.pEnd = nullptr;
	}

	~KrvList() { clear();}

	void push_back(int);
	void clear();
	void swap(KrvList&);
	void print();
	void SetZero() { pBeg = pEnd = nullptr;};

	KrvList& operator = (const KrvList& a)
	{ 
		if(this != &a)
		{ 
			KrvList tmp(a);
			(*this).swap(tmp);
		}
		return *this;
	}


	KrvList& operator = (KrvList&& a)
	{ 
		clear();
		(*this).swap(a);
		return *this;
	}
};

void KrvList::push_back(int d)
{	
	KNode *p = new KNode(d);
	if(pBeg == nullptr){ pBeg = p;}
	else{ pEnd->next = p;}
	pEnd = p;
}

void KrvList::clear() 
{ 
	while(pBeg){ auto p = pBeg; pBeg = pBeg->next;}
	pEnd = nullptr;
}

void KrvList::swap(KrvList& a)
{ 
	std::swap(pBeg, a.pBeg);
	std::swap(pEnd, a.pEnd);
}

void KrvList::print()
{
	KNode *p = pBeg;
	while(p){ std::cout << " " << p->data; p = p->next;}
}

template<typename T>
void f(std::vector<T>&& param) {}

KrvList fCopy(KrvList& lst){ return lst;}

int main()
{
	const int n = 10'000;
	chrono::time_point<chrono::system_clock> start, end;

	KrvList a;
	for(auto i = 0; i < n; i++){ a.push_back(i);}

	start = chrono::system_clock::now();
	KrvList b(a);
	end = chrono::system_clock::now();
	auto elapsed_seconds1 = chrono::duration_cast<chrono::microseconds>(end - start).count();

	start = chrono::system_clock::now();
	KrvList �(move(a));
	end = chrono::system_clock::now();
	auto elapsed_seconds2 = chrono::duration_cast<chrono::microseconds>(end - start).count();

	KrvList a1;
	for(auto i = 0; i < n; i++){ a1.push_back(i);}

	KrvList b1;
	start = chrono::system_clock::now();
	b1 = a1;
	end = chrono::system_clock::now();
	auto elapsed_seconds3 = chrono::duration_cast<chrono::microseconds>(end - start).count();

	KrvList c1;
	start = chrono::system_clock::now();
	c1 = move(a1);
	end = chrono::system_clock::now();
	auto elapsed_seconds4 = chrono::duration_cast<chrono::microseconds>(end - start).count();

	KrvList c2;
	start = chrono::system_clock::now();
	c2 = fCopy(c1);
	end = chrono::system_clock::now();
	auto elapsed_seconds5 = chrono::duration_cast<chrono::microseconds>(end - start).count();

	std::cout << "Copy constructor = " << elapsed_seconds1 << " ms" << std::endl;
	std::cout << "Move constructor = " << elapsed_seconds2 << " ms" << std::endl;
	std::cout << "Copy assignment operator = " << elapsed_seconds3 << " ms" << std::endl;
	std::cout << "Move assignment operator = " << elapsed_seconds4 << " ms" << std::endl;
	std::cout << "fCopy = " << elapsed_seconds5 << " ms" << std::endl;

	return 0;
}
