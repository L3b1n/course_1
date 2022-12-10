#include <iostream>

using namespace std;

class Dot
{
public:
    Dot(double a1) { a = a1;}
    Dot() { a = 0.0;}
    virtual ~Dot() {}

    virtual double a1() const { return a;}
    virtual void SetA1(double a1) { a = a1;}

    virtual double b() const { return 0;}
    virtual void SetB(double b1) { }

    virtual Dot& operator += (Dot const& num1)
    {
        a += num1.a1();
        return *this;
    }

    virtual Dot& operator = (Dot const& num1)
    {
        a = num1.a1();
        return *this;
    }

    virtual Dot& operator + (Dot const& num1)
    {
        this->SetA1((max(this->a1(), num1.a1()) - min(this->a1(), num1.a1())) / 2);
        return *this;
    }

    virtual ostream& Print(ostream& os) const
    {
        os << a; return os;
    }

    friend ostream& operator << (ostream& os, Dot const& num1)
    {
        return num1.Print(os);
    }
protected:
    double a;
};

class Square: public Dot
{
public:
    Square(): Dot(0), len(0) {}
    Square(double a1, double b1): Dot(a1), len(b1) {}
    virtual ~Square() {}
    
    virtual double b() const override { return len;}
    virtual void SetB(double b1) override { len = b1;}

    virtual Square& operator = (Dot const& num1) override
    {
        a = num1.a1();
        len = num1.b();
        return *this;
    }

    virtual Square& operator += (Dot const& num1) override
    {
        a += num1.a1();
        len += num1.b();
        return *this;
    }

    virtual ostream& Print(ostream& os) const override
    {
        os << a << " " << len; return os;
    }

    friend ostream& operator << (ostream& os, Square const& num1)
    {
        return num1.Print(os);
    }
protected:
    double len;   
};

int main()
{
    Square a(3, 5);
    Square b(4, 1);
    Dot c(6);
    a += c;
    cout << a << endl;
}