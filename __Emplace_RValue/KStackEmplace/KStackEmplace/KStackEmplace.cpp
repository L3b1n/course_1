#include <new>
#include <iostream>
#include <stack>

using namespace std;

template <typename T>
class KStack
{
public:
	KStack() 
	{
		pVec = static_cast<T*>(operator new[](100 * sizeof(T)));
	   	iTop = -1;
	}

	~KStack()
	{
		for(int i = 0; i <= iTop; i++){ pVec[i].~T();}
	   	operator delete[](pVec);
	   	// delete[] pVec; - �������� � ������������
	}

	KStack(initializer_list<T> _Ilist) 
	{
	   pVec = static_cast<T*>(operator new[]((_Ilist.size()<<1) * sizeof(T)));
	   iTop = -1;
	   for(auto x : _Ilist){ push_back(x);}
	}

	void push_back(T const& e){ ++iTop; *(pVec + iTop) = e;}

	void pop_back(){ pVec[iTop].~T(); --iTop;}

	template <typename ... Args>
	void emplace_back(Args&&... val)
	{
		++iTop; 
		new (pVec + iTop) T(forward<Args>(val)...);
	}

	T& back(){ return pVec[iTop];}

	bool is_empty(){ return iTop < 0;}
  
	friend ostream& operator << (ostream& os, KStack<T> const& lst)
	{
	   for(int i = 0; i <= lst.iTop; ++i){ os << *(lst.pVec + i) << " ";}
	   return os;
	}
  
private:
	T *pVec;
	int iTop;
};

class A
{
public:
	A(int x): a(x), b(0) {}
	A(int x, int y) : a(x), b(y) {}
	A(A const& a1): a(a1.a), b(a1.b){ cout << "A" << endl;}
	~A(){ cout << "~A() ";}

	friend ostream& operator << (ostream& os, A const& e)
	{
		os << "(" << e.a << "," << e.b << ")" ;
	   	return os;
	}

public:
	int a;
	int b;
};

int main ()
{
	stack<int> sti;

	{
		KStack<A> st;
		st.emplace_back(23, 46);
		st.push_back(A(23, 46));
		st.emplace_back(A(77, 88));
		cout << st << endl;
	}

	// KStack<A> st1 = { A(3), A(43,21), A(18,19)};
	// cout << st1 << endl;
	// st1.pop_back();
	// cout << st1 << endl;
	// st1.emplace_back(46);
	// cout << st1 << endl;
	// while(!st1.is_empty())
	// {
	//   	cout << st1.back() << " ";
	//   	st1.pop_back();
	// }
	cout << endl;
}