#include <iostream>

using namespace std;

int main()
{
    int n, m, t = 0, k = 0;
    cin >> n >> m;
    int* a = new int [n];
    int** b = new int *[m + 1];
    for(int i = 0; i < m + 1; i++){b[i] = new int [3];}
    for(int i = 0; i < n; i++){cin >> a[i];}
    for(int i = 0; i < m; i++){for(int j = 0; j < 3; j++){cin >> b[i][j];} }
    for(int i = 0; i < m + 1; i++){for(int j = 0; j < m - i - 1; j++){if(b[j][1] > b[j + 1][1]) swap(b[j], b[j + 1]);} }
    for(int i = 0; i < m; i++){for(int j = 0; j < m - i - 1; j++){if(b[j][0] < 0) swap(b[j], b[j + 1]);} }
    int tm = a[0], j = 0;
    while(b[j][0] > 0)
    {
        if(b[j][1] <= tm && b[j][0] >= 0)
        {
            a[k + b[j][0]] += b[j][2];
            j++;
        }else{k++; tm += a[k];}
    }
    for(int i = 0; i < n - 1; i++){t += a[i];}
    cout << t << endl;
}





// for(int i = 0; i < n; i++){cout << a[i] << " ";}
// cout << endl;
// for(int i = 0; i < m; i++){for(int j = 0; j < 3; j++){cout << b[i][j] << " ";} cout << endl; }
// cout << j << " " << b[j][0] << "===" << (a[j + b[j][0]] += b[j][3]) << " ";



// 5 6 
// 9
// 8
// 6
// 4
// 5
// 1 18 2
// 1 1 2 
// -1 10 3 
// 3 13 10 
// 3 13 9
// 4 11 4

// 5 6
// 9
// 8
// 6
// 4
// 5
// 4 18 2
// 4 1 4
// -1 10 3
// 3 10 4
// 3 13 9
// 4 11 4

// 5 6
// 1
// 2
// 3 9 13
// 4 7 16 20
// 5 
// 1 3 2   
// 1 3 4
// 1 4 3
// 1 3 4
// 1 4 9
// 1 8 4

// 4 6 
// 9
// 8
// 6
// 5
// 1 18 2
// 1 1 2 
// -1 10 3 
// 3 13 10 
// 3 13 9
// 4 11 4