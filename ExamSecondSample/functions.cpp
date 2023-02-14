#include <iostream>

using namespace std;

void Sort(int *a, int n)
{
    for(int i = 0; i < n - 1; i++){for(int j = 0; j < n - i - 1; j++){if(a[j] > a[j + 1]) swap(a[j], a[j + 1]);} }
}

void Invers(int *a, int n)
{
    if((n - 1) % 2 == 0)
        for(int i = 0, j = n - 1; i < (n - 1) / 2; i++){swap(a[i], a[j]); j--;}
    else
        for(int i = 0, j = n - 1; i <= (n - 1) / 2; i++){swap(a[i], a[j]); j--;}
}

void Addnumbers(int *a, int *b, int n, int m)
{
    for(int i = 0; i < min(n, m); i++)
    {
        a[i] += b[i];
    }
}

void Print(int *a, int n)
{
    cout << a[0];
    for(int i = 1; i < n; i++)
    {
        cout << " "<< a[i];
    }
    cout << endl;
}

void Read(int *a, int n)
{
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
}

int main()
{
    int n;
    cout << "Enter n: ";
    cin >> n;
    int *a = new int[n];
    Read(a, n);
    Invers(a, n);
    Print(a, n);
    Sort(a, n);
    Print(a, n);
}