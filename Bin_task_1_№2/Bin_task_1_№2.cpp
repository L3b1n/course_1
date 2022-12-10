#include <iostream> //принята
#include <algorithm>

using namespace std;

int main()
{
    int x, y, z, n;
    cout << "Enter x, y, z, n:" << endl;
    cin >> x >> y >> z >> n;
    int f2 = z - (x * y), f1 = y - (x * f2), f0 = x - (f1 * f2), f;
    if (n < 0)
    {
        cout << "n < 0, error" << endl; 
        exit(0);
    }
    for (int i = 0; i <= n; ++i)
    {
        f = f2 * f1 +f0;
        f0 = f1;
        f1 = f2;
        f2 = f;
    }
    cout << "F[" << n << "] = " << f << endl;
    return 0;
}