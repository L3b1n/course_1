#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

struct Items
{
public:
    Items() : Name(""), myDate(""), Section(""), Count(0) {};
    Items(string name, string mydate, string section, int count) : Name(name), myDate(mydate), Section(section), Count(count) {};
    ~Items() = default;
    Items& operator = (Items const x)
    {
        Name = x.Name;
        myDate = x.myDate;
        Section = x.Section;
        Count = x.Count;
        return *this;
    }
    friend ofstream& operator << (ofstream& fo, Items const& a)
    {
        fo << a.Name << "  " << a.myDate << "  " << a.Section << "  " << a.Count;
        return fo;
    }
    friend ifstream& operator >> (ifstream& fi, Items& a)
    {
        string s;
        if(getline(fi, s))
        {
            istringstream ss(s); string sf;
            getline(ss, sf, ' '); a.Name = sf;
            getline(ss, sf, ' '); a.myDate = sf;
            getline(ss, sf, ' '); a.Section = sf;
            getline(ss, sf, ' '); a.Count = stoi(sf);
        }
        return fi;
    }

    friend ostream& operator << (ostream& os, Items const& a)
    {
        os << a.Name << "  " << a.myDate << "  " << a.Section << "  " << a.Count;
        return os;
    }

    string Name;
    string myDate;
    string Section;
    int Count;
};

struct Price
{
public:
    Price() : Name(""), Pr(0.0) {};
    Price(string name, double pr) : Name(name), Pr(pr) {};
    ~Price() = default;
    friend ofstream& operator << (ofstream& fo, Price const& a)
    {
        fo << a.Name << "  " << a.Pr;
        return fo;
    }
    friend ifstream& operator >> (ifstream& fi, Price& a)
    {
        string s;
        if(getline(fi, s))
        {
            istringstream ss(s); string sf;
            getline(ss, sf, ' '); a.Name = sf;
            getline(ss, sf, ' '); a.Pr = stod(sf);
        }
        return fi;
    }

    friend ostream& operator << (ostream& os, Price const& a)
    {
        os << a.Name << "  " << a.Pr;
        return os;
    }

    string Name;
    double Pr;
};

struct Med
{
public:
    Med() : Name(""), myDate(""), Section(""), Pr(0.0), Count(0) {};
    Med(string name, string md, string section, double pr, int count) : Name(name), myDate(md), Section(section), Pr(pr), Count(count) {};
    friend ofstream& operator << (ofstream& fo, Med const& a)
    {
        fo << a.Name << "  " << a.myDate << "  " << a.Section << "  " << a.Pr << "  " << a.Count;
        return fo;
    }
    friend ifstream& operator >> (ifstream& fi, Med& a)
    {
        string s;
        if(getline(fi, s))
        {
            istringstream ss(s); string sf;
            getline(ss, sf, ' '); a.Name = sf;
            getline(ss, sf, ' '); a.myDate = sf;
            getline(ss, sf, ' '); a.Section = sf;
            getline(ss, sf, ' '); a.Pr = stod(sf);
            getline(ss, sf, ' '); a.Count = stoi(sf);
        }
        return fi;
    }

    friend ostream& operator << (ostream& os, Med const& a)
    {
        os << a.Name << "  " << a.myDate << "  " << a.Section << "  " << a.Pr << "  " << a.Count;
        return os;
    }

    string Name;
    string myDate;
    string Section;
    double Pr;
    int Count;
};

class MB1
{
public:
    MB1() : count(10) { M = new Items[count];}
    MB1(int n) : count(n) { M = new Items[count];}
    ~MB1(){ count = 0; delete[] M;}
    Items& operator [] (int ind)
    {
        return M[ind];
    }
    void GetMeds(ifstream& fi)
    {
        Items temp; int i = 0;
        while(fi >> temp){ M[i++] = temp;}
    }

    int count;
    Items* M;
};

int main()
{
    MB1 M1;
    Items item;
    ifstream fi("in.txt", ios::out);
    ofstream fo("out.txt", ios::end);
    M1.GetMeds(fi);
    sort(M1.M, M1.M + M1.count, [](Items a, Items b)->bool { return a.Name < b.Name;});
    for_each(M1.M, M1.M + M1.count, [](Items a)->void { cout << a << endl;});
    // while(fi >> item){ cout << item << endl;}
    // fo << item << endl;
}

// sort(M1.M, M1.M + M1.count, [](Items* a, Items* b)->bool { return ((a->lastName.compare(b->lastName)) < 0);});