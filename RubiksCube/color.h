#include <iostream>
#include <iomanip>

using namespace std;

class Col
{
public:
    int ind;
    string col;
public:
    Col() : ind(0), col("") {}
    Col(string col) : ind(0), col(col) {}
    Col(int ind, string col) : ind(ind), col(col) {}
    ~Col(){ col.erase();}
    Col operator () (const int ind1, const string col1)
    {
        ind = ind1; col = col1;
        return *this;
    }
    Col operator () (const string col1)
    {
        ind = 0; col = col1;
        return *this;
    }
    Col operator = (const Col& m){ ind = m.ind; col = m.col; return *this;}
    Col operator = (const int& m){ ind = m; return *this;}
    Col operator = (const string& m){ col = m; return *this;}
    bool operator == (const Col& m){ return m.ind == 0 ? col == m.col : ind == m.ind && col == m.col;}
    bool operator == (const string& col1){ return col == col1;}
    bool operator == (const int& ind1){ return ind == ind1;}
    bool operator != (const Col& m){ return (ind != m.ind && col != m.col);}
    friend ostream& operator << (ostream& out, const Col& m)
    {
        cout << m.ind << "  " << m.col;
        return out;
    }
};

class Color
{
public:
    int* index;
    string* color;
public:
    Color();
    Color(string str);
    ~Color();
    void Change_index(int ind, int data);
    void Change_color(int ind, string data);
    void Swap_index(int ind_one, int ind_two);
    void Change_index();
    void Change_index_stroke();
    friend ostream& operator << (ostream& out, const Color& m)
    {
        for(int i = 0, j = 0, z = 0; i < 3; i++)
        {   
            for (int k = z; z < k + 3; z++) 
            {
                out << m.index[z] << " ";
            }
            for (int k = j; j < k + 3; j++) 
            {
                out << setw(m.color[j].size()) << m.color[j] << " ";
            }
            out << endl;
        }
        return out;
    }
};