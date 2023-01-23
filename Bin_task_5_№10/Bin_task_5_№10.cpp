#include <iostream> //принята
#include <cmath>

using namespace std;

int main()
{
    int x, f0, f1, f2, f, n;
    cout << "Enter f0, f1, f2, x, n:" << endl;
    cin >> f0 >> f1 >> f2 >> x >> n;
    int p1 = f0, p2 = f0, d = 1, f_1 = f1;
    if (n < 0)
    {
        cout << "n < 0, error" << endl; 
        exit(0);
    }
    for(int i = 1; i <= min(n, 2); ++i)
    {
        f = f_1;
        f_1 = f2;
        d = d * x;
        p1 = p1 * x + f;
        p2 = p2 + f * d;
    }
    for(int i = 3; i <= n; ++i)
    {
        f = 3 * f2 * f1 + 2 * f0;
        f0 = f1;
        f1 = f2;
        f2 = f;
        d = d * x;
        p1 = p1 * x + f;
        p2 = p2 + f * d;

    }
    cout << "P1 = " << p1 << endl;
    cout << "P2 = " << p2 << endl;
    return 0;
}