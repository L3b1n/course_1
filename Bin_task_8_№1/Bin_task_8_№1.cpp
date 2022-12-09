#include <iostream> //принята
#include <cmath>

using namespace std;

int HOD(int a, int b)
{
    if (a == 0)
        return b;
 
    if ((b & 1) == 0)
    {
        if ((a & 1) == 0)
            return 2 * HOD(a / 2, b / 2);
        return HOD(b / 2, a);
    }
 
    if ((a & 1) == 0)
        return HOD(a / 2, b);
 
    if (b > a)
        return HOD(b - a, a);
 
    return HOD(a - b, b);
}

int main()
{
    int a = -1, b, m, x, y, x2 = 1, x1 = 0, y2 = 0, y1 = 1, q, r;
    while (a < 0 || b < 0)
    {
        cout << "Enter a, b: " << endl;
        cin >> a >> b;
        if ((a < 0) || (b < 0) || (a < 0 && b < 0))
            cout << "Error: a or b < 0\n" << endl;
    }

    cout << "HOD(" << a << ", " << b << ") = " << HOD(a, b) << endl;

    while (b > 0) 
    {
        q = a / b, r = a - q * b; 
        x = x2 - q * x1, y = y2 - q * y1; 
        a = b, b = r; 
        x2 = x1, x1 = x, y2 = y1, y1 = y;
    }
    x = x2, y = y2;
    cout << "X = " << x << endl;
    cout << "Y = " << y << endl;
}