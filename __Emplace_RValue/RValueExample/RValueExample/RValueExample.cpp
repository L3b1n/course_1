#include <iostream>
#include <chrono>
#include <list>
#include <vector>

using namespace std;

struct KNode
{   
	explicit KNode (int aData = 0, KNode * aNext = nullptr) : data(aData), next(aNext) {}

	int data;
	KNode* next;
};

class KrvList
{
public:
	KrvList() { pBeg = pEnd = nullptr;}
	KrvList(int item) { pBeg = pEnd = nullptr; push_back(item);}
	KrvList(const KrvList& b)
	{
		KNode *cur = b.pBeg;
		pBeg = pEnd = nullptr;
		while(cur){ push_back(cur->data); cur = cur->next;}
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

private:
	KNode *pBeg;
	KNode *pEnd;
};

void KrvList::push_back(int d) 
{ 
	KNode* p = new KNode(d);
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

	std::cout << "operator =" << std::endl;
	KrvList b1;
	start = chrono::system_clock::now();
	b1 = a1;
	end = chrono::system_clock::now();
	auto elapsed_seconds3 = chrono::duration_cast<chrono::microseconds>(end - start).count();
	
	KrvList c1;
	start = chrono::system_clock::now();
	try{ c1 = move(a1);}
	catch(int i){ std::cout << "Exception=" << i << std::endl; c1.SetZero(); c1.swap(a1); }
	end = chrono::system_clock::now();
	auto elapsed_seconds4 = chrono::duration_cast<chrono::microseconds>(end - start).count();
	
	std::cout << "Copy constructor = " << elapsed_seconds1 << " ms" << std::endl;
	std::cout << "Move constructor = " << elapsed_seconds2 << " ms" << std::endl;
	std::cout << "Copy assignment operator = " << elapsed_seconds3 << " ms" << std::endl;
	std::cout << "Move assignment operator = " << elapsed_seconds4 << " ms" << std::endl;

	std::list<int>&& l{ 1,2,3,4,5 };
	std::cout << std::endl << "l = ";
	for(auto x : l){ std::cout << x << " ";}
	std::cout << std::endl;

	std::vector< int> v;
	f(std::vector<int>{1,2,3});
	return 0;
}
