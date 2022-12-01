#ifndef KRatH
#define KRatH
#include <iostream>
#include <cmath>
#include <exception>
#include <assert.h>

using namespace std;

class KRat;

struct KNode
{
	explicit KNode(int aInfo = 0, KNode * aNext = nullptr): info(aInfo), next(aNext) {}
	~KNode() {}
	
	int info;
	KNode * next;
};

class KRat
{ 
public:
	friend class KNumProxy;
			
	KRat() : fNum(0), fDenom(1) {}
	explicit KRat(double aNum) : fNum(aNum), fDenom(1) {}
	explicit KRat(double aNum, double aDenom) : fNum(aNum), fDenom(aDenom) { Normalize();}         
	~KRat() { }
   	// Accessors
	double& Numerator() { return fNum;}
   	const double& Numerator() const { return fNum;}
	double& Denominator() { return fDenom;}   
   	const double& Denominator() const { return fDenom;}  

	KRat& operator = (KRat const& r);
	KRat& operator = (double a);
	KRat& operator = (int a);

	friend bool operator > (double a, KRat const&r1){ return a > (double)r1;}
	friend bool operator < (double a, KRat const&r1){ return a < (double)r1;}
	friend bool operator >= (double a, KRat const&r1){ return a >= (double)r1;}
	friend bool operator <= (double a, KRat const&r1){ return a <= (double)r1;}
	friend bool operator == (double a, KRat const&r1){ return a == (double)r1;}
	friend bool operator != (double a, KRat const&r1){ return a != (double)r1;}

	friend bool operator > (int a, KRat const&r1){ KRat r(a * r1.fDenom, r1.fDenom); return r > r1;}
	friend bool operator < (int a, KRat const&r1){ KRat r(a * r1.fDenom, r1.fDenom); return r < r1;}
	friend bool operator >= (int a, KRat const&r1){ KRat r(a * r1.fDenom, r1.fDenom); return r >= r1;}
	friend bool operator <= (int a, KRat const&r1){ KRat r(a * r1.fDenom, r1.fDenom); return r <= r1;}
	friend bool operator == (int a, KRat const&r1){ KRat r(a * r1.fDenom, r1.fDenom); return r == r1;}
	friend bool operator != (int a, KRat const&r1){ KRat r(a * r1.fDenom, r1.fDenom); return r != r1;}

	bool operator > (KRat const& r){ return this->fNum * r.fDenom > this->fDenom * r.fNum;}
	bool operator < (KRat const& r){ return this->fNum * r.fDenom < this->fDenom * r.fNum;}
	bool operator >= (KRat const& r){ return this->fNum * r.fDenom >= this->fDenom * r.fNum;}
	bool operator <= (KRat const& r){ return this->fNum * r.fDenom <= this->fDenom * r.fNum;}
	bool operator == (KRat const& r){ return this->fNum * r.fDenom == this->fDenom * r.fNum;}
	bool operator != (KRat const& r){ return this->fNum * r.fDenom != this->fDenom * r.fNum;}

	bool operator > (double a){ return (double)*this > a;}
	bool operator < (double a){ return (double)*this < a;}
	bool operator >= (double a){ return (double)*this >= a;}
	bool operator <= (double a){ return (double)*this <= a;}
	bool operator == (double a){ return (double)*this == a;}
	bool operator != (double a){ return (double)*this != a;}

	bool operator > (int a){ KRat r(a * this->fDenom, this->fDenom); return *this > r;}
	bool operator < (int a){ KRat r(a * this->fDenom, this->fDenom); return *this < r;}
	bool operator >= (int a){ KRat r(a * this->fDenom, this->fDenom); return *this >= r;}
	bool operator <= (int a){ KRat r(a * this->fDenom, this->fDenom); return *this <= r;}
	bool operator == (int a){ KRat r(a * this->fDenom, this->fDenom); return *this == r;}
	bool operator != (int a){ KRat r(a * this->fDenom, this->fDenom); return *this != r;}

	double const operator + (double a){ return (double)*this + a;}
	friend double const operator + (double a, KRat const& r2){ return a + (double)r2;}

	double const operator - (double a){ return (double)*this - a;}
	friend double const operator - (double a, KRat const& r2){ return a - (double)r2;}

	double const operator * (double a){ return (double)*this * a;}
	friend double const operator * (double a, KRat const& r2){ return a * (double)r2;}

	double const operator / (double a){ return (double)*this / a;}
	friend double const operator / (double a, KRat const& r2){ return a / (double)r2;}

	KRat& operator += (const KRat& r);
	double const operator += (double a);
	KRat& operator += (int a);

	KRat& operator -= (const KRat& r);
	double const operator -= (double a);
	KRat& operator -= (int a);

	KRat& operator *= (const KRat& r);
	double const operator *= (double a);
	KRat& operator *= (int a);

	KRat& operator /= (const KRat& r);
	double const operator /= (double a);
	KRat& operator /= (int a);

 
	inline KRat& operator ++ (); //prefix
	inline KRat const operator ++ (int); //postfix

	inline KRat const operator + (KRat const& r);
	inline KRat const operator + (int a);
	friend inline KRat const operator + (int a, KRat const& r2);

	inline KRat const operator - (KRat const& r);
	inline KRat const operator - (int a);
   	friend inline KRat const operator - (int a, KRat const& r2);

	inline KRat const operator * (KRat const& r);
	inline KRat const operator * (int a);
   	friend inline KRat const operator * (int a, KRat const& r2);
   
	inline KRat const operator / (KRat const& r);
	inline KRat const operator / (int a);
   	friend inline KRat const operator / (int a, KRat const& r2);


	explicit operator double () const { return (double)fNum / fDenom;}

  	friend std::istream& operator >> (std::istream& is, KRat& r);
  	friend inline std::ostream& operator << (std::ostream& os, const KRat& r);

private:
	//static double count(double num, int &i);
	static int GCD (int, int);
	void Normalize();

   	double fNum;
   	double fDenom;
};    // end of KRat

//----------------------------- inline implementation --------------------------
inline KRat& KRat::operator ++ ()     //prefix
{
	fNum += fDenom;
	return *this;
}

inline KRat const KRat::operator ++ (int)  //postfix
{
	KRat r = *this;
	++*this;
	return r;
}

inline KRat const KRat::operator + (KRat const& r) { return KRat(fNum * r.fDenom + r.fNum * fDenom, fDenom * r.fDenom);}

inline KRat const KRat::operator + (int a) { return KRat(fNum + a * fDenom, fDenom);}

inline KRat const operator + (int a, KRat const& r2) { return KRat(a * r2.fDenom + r2.fNum, r2.fDenom);}

inline KRat const KRat::operator - (KRat const& r) { return KRat(fNum * r.fDenom - r.fNum * fDenom, fDenom * r.fDenom);}

inline KRat const KRat::operator - (int a) { return KRat(fNum - a * fDenom, fDenom);}

inline KRat const operator - (int a, KRat const& r2) { return KRat(a * r2.fDenom - r2.fNum, r2.fDenom);}

inline KRat const KRat::operator * (const KRat& r) { return KRat(fNum * r.fNum, fDenom * r.fDenom);}

inline KRat const KRat::operator * (int a) { return KRat(fNum * a, fDenom);}

inline KRat const operator * (int a, KRat const& r2) { return KRat(a * r2.fNum, r2.fDenom);}

inline KRat const KRat::operator / (const KRat& r) { return KRat(fNum * r.fDenom, fDenom * r.fNum);}

inline KRat const KRat::operator / (int a) { return KRat(fNum, fDenom * a);}

inline KRat const operator / (int a,KRat const& r2) { return KRat(a * r2.fDenom, r2.fNum);}

inline std::ostream& operator << (std::ostream& os, const KRat& r)
{ 
	os << r.fNum;
  	if(1 != r.fDenom){ os << '/' << r.fDenom;}
  	return os;
}

#endif