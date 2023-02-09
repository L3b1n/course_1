#include <iostream> 
#include <fstream>

using namespace std; 
 
class Tqueue 
{ 
public :
    Tqueue(): head(0), tail(SIZE) {queue = new int[SIZE];} 
    Tqueue(int n): head(0), tail(n) {queue = new int[n];}
    void push (int num); 
    int size();
    void pop();
    int front();
    int back();
    void read();
    int& operator [] (const int i);
    friend inline std::istream& operator >> (std::istream& is, Tqueue& m);
    friend inline std::ostream& operator << (std::ostream& os, const Tqueue& m);

    friend inline ifstream& operator >> (ifstream& fi, Tqueue& m);
    friend inline ofstream& operator << (ofstream& fo, const Tqueue& m);
public:  
    int *queue; 
    int head, tail; 
    static const int SIZE=100;
}; 

inline std::ostream& operator << (std::ostream& os, const Tqueue& m)
{ 
    os << m.queue[0];
    for(int i = m.head + 1; i < m.tail; i++)
    {
        if(m.queue[i])
            os << " " << m.queue[i];
    }
    os << endl;
    return os;
}

inline std::istream& operator >> (std::istream& is, Tqueue& m)
{
    for(int i = m.head; i < m.tail; i++)
    {
        is >> m.queue[i];
    }
    return is;
}

inline ifstream& operator >> (ifstream& fi, Tqueue& m)
{
    m.read();
    return fi;
}