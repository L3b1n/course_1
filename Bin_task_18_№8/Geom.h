#ifndef KSHAPE_H
#define KSHAPE_H

#include <iostream>

using namespace std;

struct KLocation; 

class KPLocation
{ 
    KLocation **p;
    int size;
public:
    KPLocation(int pSize) { p = new KLocation *[size = pSize];}
    ~KPLocation() { delete [] p;}
    KLocation *&operator [] (int i) { return p[i];}	
};

struct KLocation
{
public:
    KLocation(int x=0, int y=0) : x(x), y(y) {}
    ~KLocation() {}
    int X() { return x;}
    int Y() { return y;}

protected:
    int x, y;
};
// ------------------------------------------ End of KLocation -----------------

// ---------------------------------------------- KPoint -----------------------
//template <typename ContextPolicy>
//class KPoint: public KLocation, public ContextPolicy
class KPoint : public KLocation
{
public:
    inline KPoint(ostream& os, int x = 0, int y = 0) : KLocation(x, y), os(os) { is_visible = 0;}
    virtual ~KPoint() {}
    inline virtual void Show();
    inline virtual void Hide();
    inline virtual void Shift(int dx, int dy);
    inline virtual void MoveTo(int aX, int aY);
    virtual void Rotate(double pAngle) {}
    virtual void Expand(double pKoef) {}

    ostream& os;
protected:
    virtual void Draw();
protected:
    bool is_visible;
};

inline void KPoint::Show()
{
    is_visible = true;
    Draw();
}

inline void KPoint::Hide()
{
    is_visible = false;
    Draw(); 
}

inline void KPoint::Shift(int dx, int dy)
{ 
    if(is_visible){ Hide(); x += dx; y += dy; Show();}
    else{ x += dx; y += dy;}
}

inline void KPoint::MoveTo(int aX, int aY)
{
    if(is_visible){ Hide(), x = aX; y = aY; Show();}
    else{ x = aX; y = aY;}
}

void KPoint::Draw ()
{
    os << "<KPoint>" << std::endl;
    os << "  is_visible = " << boolalpha << is_visible << ", x = " << x << ", y = " << y << std::endl;
    os << "<end of KPoint>" << std::endl;
}
// ----------------------------------- End of KPoint ---------------------------

// ----------------------------------- KShape ----------------------------------
class KShape: public KPoint
{
public:
    //KShape (HDC& pHDC, int pX, int pY) : KPoint(pHDC, pX, pY), koef(1) {  }
    KShape(ostream& os, int x, int y, double aAngle = 0.0, double aKoef = 1.0) : KPoint(os, x, y), angle(aAngle), koef(1) {}
    inline virtual void Expand(double pKoef);
    inline virtual void Rotate(double dAngle);

protected:
    double koef;
    double angle;
};

inline void KShape::Expand (double pKoef)
{ 
    if(is_visible){ Hide(); koef *= pKoef; Show();}
    else{ koef *= pKoef;}
}

inline void KShape::Rotate(double dAngle)
{
  if(is_visible){ Hide(); angle += dAngle; Show();}
  else{ angle += dAngle;}
}
// --------------------------------- End of KShape -----------------------------

// --------------------------------- KParallelogram ----------------------------
class KParallelogram: public KShape
{ 
protected:
    double a;
    double b;
    double alpha;
public:
    KParallelogram(ostream& os, double a, double b, double alpha, int x = 0, int y = 0, double aAngle = 0.0, double aKoef = 1.0) : 
    KShape(os, x, y, aAngle, aKoef), a(a), b(b), alpha(alpha) {}

protected:
    inline virtual void Draw () override;
};

inline void KParallelogram::Draw()
{ 
    os << "<KParallelogram>" << std::endl;
    os << "  a = " << a << std::endl;
    os << "  b = " << b << std::endl;
    os << "  alpha = " << alpha << std::endl;
    os << "  diagonal = " << boolalpha << true << std::endl;
    os << "  is_visible = " << boolalpha << is_visible << ", x = " << x << ", y = " << y << std::endl;
    os << "  angle = " << angle << ", koef = " << koef << std::endl;
    os << "<end of KParallelogram>\n" << std::endl;
}
// --------------------------------- End of KParallelogram ---------------------

// --------------------------------- KPaintParallelogram ----------------------------
class KPaintParallelogram: public KParallelogram
{ 
    string color;
    string position;
public:
    KPaintParallelogram(ostream& os, double a, double b, double alpha, string position = "top", string color = "black", int x = 0, int y = 0, double aAngle = 0.0,
    double aKoef = 1.0) : KParallelogram(os, a, b, alpha, x, y, aAngle, aKoef), position(position), color(color) {}
    inline void Paint(string aPosition, string aColor = "");

protected:
    inline virtual void Draw () override;
};

inline void KPaintParallelogram::Paint(string aPosition, string aColor)
{
    if(is_visible){ Hide(); position = aPosition; aColor != "" ? color = aColor : aColor = ""; Show(); Draw();}
    else{ position = aPosition; color = aColor;}
}

inline void KPaintParallelogram::Draw()
{ 
    os << "<KPaintParallelogram>" << std::endl;
    os << "  a = " << a << std::endl;
    os << "  b = " << b << std::endl;
    os << "  alpha = " << alpha << std::endl;
    os << "  diagonal = " << boolalpha << true << std::endl;
    os << "  position = " << position << " triangle, color = " << color << std::endl;
    os << "  is_visible = " << boolalpha << is_visible << ", x = " << x << ", y = " << y << std::endl;
    os << "  angle = " << angle << ", koef = " << koef << std::endl;
    os << "<end of KPaintParallelogram>\n" << std::endl;
}
// --------------------------------- End of KParallelogram ---------------------

// --------------------------------- KTrapeze ----------------------------------
class KTrapeze : public KShape
{
protected:
    double a;
    double b;
    double c;
    double d;
    double alpha;
public:
    KTrapeze(ostream& os, double a, double b, double c, double d, double alpha, int x = 0, int y = 0, double aAngle = 0.0, double aKoef = 1.0) : 
    KShape(os, x, y, aAngle, aKoef), a(a), b(b), c(c), d(d), alpha(alpha) {}

protected:
    inline virtual void Draw() override;
};

inline void KTrapeze::Draw()
{
    os << "<KTrapeze>" << std::endl;
    os << "  a = " << a << std::endl;
    os << "  b = " << b << std::endl;
    os << "  c = " << c << std::endl;
    os << "  d = " << d << std::endl;
    os << "  alpha = " << alpha << std::endl;
    os << "  is_visible = " << boolalpha << is_visible << ", x = " << x << ", y = " << y << std::endl;
    os << "  angle = " << angle << ", koef = " << koef << std::endl;
    os << "<end of KTrapeze>\n" << std::endl;
}
// ------------------------------------------- End of KTrapeze ------------------

// --------------------------------- KPaintTrapeze ----------------------------------
class KPaintTrapeze : public KTrapeze
{
    string color1;
    string color2;
    string position1;
    string position2;
public:
    KPaintTrapeze(ostream& os, double a, double b, double c, double d, double alpha, string color1 = "black", string position1 = "right",
    string color2 = "black", string position2 = "left", int x = 0, int y = 0, double aAngle = 0.0, double aKoef = 1.0) : 
    KTrapeze(os, a, b, c, d, alpha, x, y, aAngle, aKoef), color1(color1), position1(position1), color2(color2), position2(position2) {}
    inline void Paint(string aPosition1 = "", string aPosition2 = "", string aColor1 = "", string aColor2 = "");

protected:
    inline virtual void Draw() override;
};

inline void KPaintTrapeze::Paint(string aPosition1, string aPosition2, string aColor1, string aColor2)
{
    if(is_visible){ Hide(); position1 != "" ? position1 = aPosition1 : aPosition1 = ""; aColor1 != "" ? color1 = aColor1 : aColor1 = "";
        position2 != "" ? position2 = aPosition2: aPosition2 = ""; aColor2 != "" ? color2 = aColor2 : aColor2 = ""; Show(); Draw();}
    else{ position1 != "" ? position1 = aPosition1 : aPosition1 = ""; aColor1 != "" ? color1 = aColor1 : aColor1 = "";
        position2 != "" ? position2 = aPosition2: aPosition2 = ""; aColor2 != "" ? color2 = aColor2 : aColor2 = "";}
}

inline void KPaintTrapeze::Draw()
{
    os << "<KTrapeze>" << std::endl;
    os << "  a = " << a << std::endl;
    os << "  b = " << b << std::endl;
    os << "  c = " << c << std::endl;
    os << "  d = " << d << std::endl;
    os << "  alpha = " << alpha << std::endl;
    os << "  position1 = " << position1 << ", color1 = " << color1 << std::endl;
    os << "  position2 = " << position2 << ", color2 = " << color2 << std::endl;
    os << "  is_visible = " << boolalpha << is_visible << ", x = " << x << ", y = " << y << std::endl;
    os << "  angle = " << angle << ", koef = " << koef << std::endl;
    os << "<end of KTrapeze>\n" << std::endl;
}
// ------------------------------------------- End of KTrapeze ------------------
#endif          