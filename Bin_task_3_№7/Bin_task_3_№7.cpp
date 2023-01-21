#include <iostream> //
#include <cmath>

using namespace std;

int main() 
{
    int x, y, n;
    cout << "Enter x, y, n: " << endl;
    cin >> x >> y >> n;
    if(y == 0) 
    {
        cout << "Error: y = 0" << endl;
        return 0;
    }
    double s = 0, r = 0, p = 0, k = 1, h = 1, d = x;
    for(int i = 0; i < n; ++i)
    {
        h = h * y;
        k = k * h;
        d = d * x * x / k;
        p = p + d;
        r = r + p;
        s = s + r;
    }
    cout << "S[" << n << "] = " << s << endl;
    return 0;
}