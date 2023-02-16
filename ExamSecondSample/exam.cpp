#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

struct Comp
{
public:
    Comp() : Name(""), Section(""), Price(0) {};
    Comp(string name, string section, int price) : Name(name), Section(section), Price(price) {};
    Comp(const Comp &temp) : Name(temp.Name), Section(temp.Section), Price(temp.Price) {};
    ~Comp() = default;

    bool compare(Comp b)
    {
        return Name < b.Name;
    }

    Comp& operator = (Comp const &a)
    {
        Name = a.Name;
        Section = a.Section;
        Price = a.Price;
        return *this;
    }

    string GetName(){ return Name;}

    string ToString()
    {
        return Name + " " + Section + " " + to_string(Price);
    }

    bool operator == (const Comp a){ return a.Name == Name;}

    friend ostream& operator << (ostream& fo, Comp const& a)
    {
        fo << a.Name << "  " << a.Section << "  " << a.Price;
        return fo;
    }

    friend istream& operator >> (istream& fi, Comp& a)
    {
        string s;
        if(getline(fi, s))
        {
            istringstream ss(s); string sf;
            getline(ss, sf, ' '); a.Name = sf;
            getline(ss, sf, ' '); a.Section = sf;
            getline(ss, sf, ' '); a.Price = stoi(sf);
        }
        return fi;
    }

private:
    string Name;
    string Section;
    int Price;
};


struct Bag
{
public:
    Bag() : Name(""), Section(""), Num(0) {};
    Bag(string name, string section, int num) : Name(name), Section(section), Num(num) {};
    Bag(const Bag &temp) : Name(temp.Name), Section(temp.Section), Num(temp.Num) {};
    ~Bag() = default;

    bool compare(Bag b)
    {
        return Name < b.Name;
    }

    bool operator == (const Bag a){ return a.Name == Name;}

    Bag& operator = (Bag const &a)
    {
        Name = a.Name;
        Section = a.Section;
        Num = a.Num;
        return *this;
    }

    string GetName(){ return Name;}

    string ToString()
    {
        return Name + " " + Section + " " + to_string(Num);
    }

    friend ostream& operator << (ostream& fo, Bag const& a)
    {
        fo << a.Name << "  " << a.Section << "  " << a.Num;
        return fo;
    }

    friend istream& operator >> (istream& fi, Bag& a)
    {
        string s;
        if(getline(fi, s))
        {
            istringstream ss(s); string sf;
            getline(ss, sf, ' '); a.Name = sf;
            getline(ss, sf, ' '); a.Section = sf;
            getline(ss, sf, ' '); a.Num = stoi(sf);
        }
        return fi;
    }

private:
    string Name;
    string Section;
    int Num;
};


template<class T>
class comp
{
public:
    comp() : Table_Title(""), Count(10) { M = new T[Count];};
    comp(string table_title, int count) : Table_Title(table_title), Count(count) { M = new T[Count];};
    comp(const comp<T> &temp) : Table_Title(temp.Table_Title), Count(temp.Count) { M = new T[Count]; for(int i = 0; i < Count; i++){ M[i] = temp.M[i];}};
    ~comp() = default;

    comp<T> operator = (comp<T> const& a)
    {
        if(this != &a) 
        {
            Count = a.Count; delete[] M;
            T *M = new T[Count];
            for(int i = 0; i < Count; i++){ M[i] = a.M[i];}
        }
        return *this;
    }

    friend comp<T> operator + (comp<T> a, comp<T> b)
    {
        int n = 0;
        comp<T> res(a.Table_Title, a.Count + b.Count);
        a.Sort(); b.Sort();
        for(int i = 0; i < a.Count; i++){ res.M[i] = a.M[i]; n++;}
        for(int i = 0; i < b.Count; i++)
        { 
            if(a.FindName(b.M[i].GetName()) == "There isn't this name in your array")
            { res.M[i + a.Count] = b.M[i]; n++;}
        }
        cout << n << endl;
        res.Count = n;
        return res;
    }

    string FindName(string name)
    {
        string res;
        for(int i = 0; i < Count; i++){ if(M[i].GetName() == name){ res = M[i].ToString(); return res;};}
        return "There isn't this name in your array";
    }

    int GetCount(){ return Count;}

    void Sort()
    {
        sort(M, M + Count, [](T a, T b)->bool { return a.compare(b);});
    }

    void Sort_revers()
    {
        sort(M, M + Count, [](T a, T b)->bool { return !a.compare(b);});
    }

    friend ostream& operator << (ostream& fo, comp const& a)
    {
        fo << a.Table_Title << endl;
        for_each(a.M, a.M + a.Count, [&fo](T const b){ fo << b << endl;});
        return fo;
    }

    friend istream& operator >> (istream& fi, comp& a)
    {
        string s;
        for(int i = 0; i < a.Count; i++){ fi >> a.M[i];}
        return fi;
    }

private:
    string Table_Title;
    int Count;
    T *M;
};

int main()
{
    ifstream fi1("in1.txt", ios::out);
    ifstream fi2("in2.txt", ios::out);
    ofstream out1("out1.txt");
    ifstream fi3("in3.txt", ios::out);
    ifstream fi4("in4.txt", ios::out);
    ofstream out2("out2.txt");
    comp<Comp> a("Наименование товара  Секция  Цена", 2), b("Наименование товара  Секция  Количество", 2), c;
    comp<Bag> k("Наименование товара  Секция  Цена", 2), l("Наименование товара  Секция  Количество", 2), p;
    cout << "Comp---------------------------------------" << endl;
    fi1 >> a; cout << a << endl; cout << "---------------------------------------" << endl;
    fi2 >> b; cout << b << endl; cout << "Bag---------------------------------------" << endl;
    fi3 >> k; cout << k << endl; cout << "---------------------------------------" << endl;
    fi4 >> l; cout << l << endl; cout << "Add---------------------------------------" << endl;
    c = a + b; cout << c << endl; cout << "---------------------------------------" << endl;
    a.Sort(); cout << a << endl; cout << "---------------------------------------" << endl;
    k.Sort_revers(); cout << k << endl; cout << "Comp---------------------------------------" << endl;
    string res1 = a.FindName("Nokia");
    cout << res1 << endl; cout << "Bag---------------------------------------" << endl;
    string res2 = k.FindName("Nokia");
    cout << res2 << endl; cout << "---------------------------------------" << endl;
    out1 << a << endl; out1 << b << endl; out1 << c << endl;
    out2 << k << endl; out2 << l << endl;
    out2.close();
    out1.close();
}