#include <iostream> //принята 
#include <cmath>
#include <limits>

using namespace std;

int main() 
{
    const double Pi = acos(-1);
    double a, b, x, y, z;
    auto eps = numeric_limits<double>::epsilon();
    cout << "Enter x, y, z: " << endl;
    cin >> x >> y >> z;
    double conditional = abs(z);
    while (conditional > 1)
    {
        conditional -= 90;
    }
    z = (z * Pi) / 180;

    a = (4 + sin(x + y)) / (2 + abs(x - 1 + pow(x * y, 2)));
    cout << "A = " << a << endl;

    if ((conditional > -eps) && (conditional < eps))
        cout << "Error: tg of 90 when calculating B" << endl;
    else
    {
        b = cos(tan(z));
        cout << "B = " << b << endl;
    }
    cout << conditional << endl;
}