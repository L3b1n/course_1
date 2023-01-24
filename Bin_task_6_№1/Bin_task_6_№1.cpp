#include <iostream> //принята
#include <cmath>
#include <time.h>
#include <iomanip>

using namespace std;

int main()
{
    int n;
    cout << "Enter n: " << endl;
    cin >> n;
    if(n < 0)
    {
        cout << "Erorr: n < 0" << endl;
        exit(0);
    }
    int *a = new int[n];
    srand(time(NULL));
    for(int i = 0; i < n; i++)
        a[i] = rand()%100;
    
    cout << "No sort A[" << n << "] = ";        
    for(int i = 0; i < n; i++)     
        cout << setw(3) << a[i];
    
    for(int i = 0, x; i < n; i++)  
    {
        x = a[i];
        for(int j = i - 1; j >= 0 && a[j] > x; j--)
        {
            a[j+1] = a[j];
            a[j] = x;
        }
    }
    
    cout << endl << "sort B[" << n << "] = ";        
    for(int i = 0; i < n; i++)
    {
        cout << setw(3) << a[i];
    }
    cout << endl;
}