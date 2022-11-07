#include "KRat.h" // сделать приведение к double
#include <cmath>

using namespace std;

std::istream& operator >> (std::istream& is, KRat& r)
{
    is >> r.fNum >> r.fDenom;
    r.Normalize();
    return is;
}

KRat& KRat::operator = (KRat const& r)
{
    fNum = r.fNum;
    fDenom = r.fDenom;
    Normalize();
    return *this;
}

KRat& KRat::operator = (double a)
{
    fNum = a;
    fDenom = 1;
    return *this;
}

KRat& KRat::operator = (int a)
{
    fNum = a;
    fDenom = 1;
    return *this;
}

KRat& KRat::operator += (const KRat& r)
{
    fNum = fNum * r.fDenom + r.fNum * fDenom;
    fDenom *= r.fDenom;
    Normalize();
    return *this;
}

double const KRat::operator += (double a)
{
    fNum = (double)*this + a;
    fDenom = 1;
    return *this;
}

KRat& KRat::operator += (int a)
{
    fNum = fNum + a * fDenom;
    Normalize();
    return *this;
}

KRat& KRat::operator -= (const KRat& r)
{
    fNum = fNum * r.fDenom - r.fNum * fDenom;
    fDenom *= r.fDenom;
    Normalize();
    return *this;
}

double const KRat::operator -= (double a)
{
    fNum = (double)*this - a;
    fDenom = 1;
    return *this;
}

KRat& KRat::operator -= (int a)
{
    fNum = fNum  - a * fDenom;
    Normalize();
    return *this;
}

KRat& KRat::operator *= (const KRat& r)
{
    fNum *= r.fNum;
    fDenom *= r.fDenom;
    Normalize();
    return *this;
}

double const KRat::operator *= (double a)
{
    fNum = (double)*this * a;
    fDenom = 1;
    return *this;
}

KRat& KRat::operator *= (int a)
{
    fNum *= a;
    Normalize();
    return *this;
}

KRat& KRat::operator /= (const KRat& r)
{
    fNum *= r.fDenom;
    fDenom *= r.fNum;
    Normalize();
    return *this;
}

double const KRat::operator /= (double a)
{
    fNum = (double)*this / a;
    fDenom = 1;
    return *this;
}

KRat& KRat::operator /= (int a)
{
    fDenom *= a;
    Normalize();
    return *this;
}

int KRat::GCD(int a, int b)
{
    a = abs(a); b = abs(b);
    while(a && b){ a > b ? a %= b : b %= a;}
    return (a+b);
}

void KRat::Normalize()
{
    int gcd = GCD(fNum,fDenom);
    fNum /= gcd;
    fDenom /= gcd;
    if(fDenom < 0){ fNum *= -1; fDenom *= -1;}
}