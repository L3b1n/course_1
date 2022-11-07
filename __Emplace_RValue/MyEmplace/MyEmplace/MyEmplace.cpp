#include <iostream>
#include <list>

using namespace std;

struct KNoEmplace__ {};
struct KEmplace__ {};

template <typename T>
struct KNode
{ 	
	KNode(KNoEmplace__ const& aNoEmpl, T const e) : info(e), next(nullptr) {}
    KNode(KNoEmplace__ const& aNoEmpl, T const& d, KNode<T> * _ptr) : info(d), next(_ptr) {}

    template <typename ... Args>
    KNode(KEmplace__ const& aEmpl, Args&&... val) : info(forward<Args>(val)...), next(nullptr) {}

    T info;
    KNode<T> *next;
};

template <typename T>
class KList
{
public: 
    KList(): first(nullptr), last(nullptr) {}
   
	KList(initializer_list<T> _Ilist) : first(nullptr), last(nullptr) { for(auto x: _Ilist){ push_back(x);}}

	~KList()
	{ 
		KNode<T> *p = first;
		while(first)
		{
			KNode<T> *p = first;
			first = first->next;
			delete p;
		}
	}
   
	void push_back(T const& e)
	{
		if(first == nullptr){ last = first = new KNode<T>(KNoEmplace__(), e, nullptr);}
		else
		{
			last->next = new KNode<T>(KNoEmplace__(), e, nullptr);
			last = last->next;
		}
	}

	template <typename ... Args>
	void emplace_back(Args&&... val)
	{
		if(first == nullptr){ last = first = new KNode<T>(KEmplace__(),forward<Args>(val)...);}
		else
		{ 
			last->next = new KNode<T>(KEmplace__(),forward<Args>(val)...);
			last = last->next;
		}
	}

	friend std::ostream& operator << (std::ostream& os, KList<T> const& lst)
	{
		KNode<T> *p = lst.first;
		while(p) 
		{
			os << p->info << " "; 
			p = p->next;
		}
		return os;
	}

private: 
    KNode<T> *first;
    KNode<T> *last;
};

//===================================================================
struct KTest
{
    KTest(int _a, double _b, long long _c) : a(_a), b(_b), c(_c) {}
    friend std::ostream& operator << (std::ostream& os, KTest const& tst)
    { 	
		os << tst.a << " " << tst.b << " " << tst.c;
        return os;
    }

	int a;
    double b;
    long long c;
};

int main()
{
    KList<int> xl= {10,11,12};
    xl.emplace_back(45);
    std::cout << xl << std::endl;

    KList<KTest> xTst = { KTest(1,1,1), KTest(2,2,2)};
    xTst.emplace_back(2, 3.14, 2222222);
    int k = 33;
    xTst.emplace_back(k, 6.28, 5555555);
    std::cout << xTst << std::endl;

    std::list<int> v = { 1,2,4,5 };
    v.emplace_back(56);
    v.push_back(77);

    for (auto x : v){ cout << x << " ";}
    std::cout << std::endl;
    return 0;
}

