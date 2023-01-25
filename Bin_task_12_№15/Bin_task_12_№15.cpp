#include <iostream> //принята
#include <cmath>
#include "stl.cpp"

using namespace std;

int main() 
{
    KStl l1, l2, l3;

    int n, m, x;
    cout << "Enter n, m: ";
    cin >> n >> m;
    cout << "Enter " << n << " numbers: ";
    for (int i = 0; i < n; ++i)
    {
        cin >> x;
        l1.PushBack(x);
    }
    cout << "\nEnter " << m << " numbers: ";
    for (int i = 0; i < m; ++i)
    {
        cin >> x;
        l2.PushBack(x);
    }
    cout << l1.Length() << endl;
    l3.Push(l1, l2);
    l3.Print();
}