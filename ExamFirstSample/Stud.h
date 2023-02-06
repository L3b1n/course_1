#include <iostream> 
#include <fstream>

using namespace std; 
 
class Stud 
{ 
public :
    Stud(): head(0), tail(SIZE) {queue = new int[SIZE]; str = new string[SIZE];} //конструктор класса по умолчанию
    Stud(int n): head(0), tail(n) {queue = new int[n];} //конструктор класса
    void push (int num); 
    int size(); //метод длинны массива
    void pop();
    int front();
    int back();
    void read();
    void GetSorted(); //метод сортировки массива
    int& operator [] (const int i);
    friend inline std::istream& operator >> (std::istream& is, Stud& m);
    friend inline std::ostream& operator << (std::ostream& os, const Stud& m);

    friend inline ifstream& operator >> (ifstream& fi, Stud& m);
    friend inline ofstream& operator << (ofstream& fo, const Stud& m);
public:  
    int *queue; 
    int head, tail; 
    static const int SIZE = 100;
    string* str;
    int ball;
}; 

inline std::ostream& operator << (std::ostream& os, const Stud& m)
{ 
    for(int i = m.head; i < m.tail; i++)
    {
        if(m.queue[i])
            os << m.str[i] << " " << m.queue[i] << endl;
    }
    return os;
}

inline std::istream& operator >> (std::istream& is, Stud& m)
{
    for(int i = m.head; i < m.tail; i++)
    {
        is >> m.queue[i];
    }
    return is;
}

inline ifstream& operator >> (ifstream& fi, Stud& m)
{
    m.read();
    return fi;
}