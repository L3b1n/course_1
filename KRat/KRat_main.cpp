#include <iostream> //
#include "KRat.cpp"

using namespace std;

int main()
{
    KRat r1, r2, r3;
    cout << "Enter r1, r2: " << endl;
    cin >> r1 >> r2;
    cout << "-----------------------------------" << endl;
    cout << "r1 == r2: " << (r1 == r2) << endl;
    cout << "r1 != r2: " << (r1 != r2) << endl;
    cout << "r1 > r2: " << (r1 > r2) << endl;
    cout << "r1 <= r2: " << (r1 <= r2) << endl;
    cout << "r1 > 3: " << (r1 > 3) << endl;
    cout << "r1 <= 3: " << (r1 <= 3) << endl;
    cout << "r1 > 0.5: " << (r1 > 0.5) << endl;
    cout << "r1 <= 0.5: " << (r1 <= 0.5) << endl;
    cout << "-----------------------------------" << endl;
    r3 = r1 + r2;
    cout << "r3 = r1 + r2: " << r3 << endl; 
    r3 = r1 * 3;
    cout << "r3 = r1 * 3: " << r3 << endl;
    r3 = r1 / 0.5;
    cout << "r3 = r1 / 0.5: " << r3 << endl;
    cout << "-----------------------------------" << endl;
    r1 += r2;
    cout << "r1 += r2: " << r1 << endl; 
    r1 -= 3;
    cout << "r1 -= 3: " << r1 << endl;
    r1 *= 0.5;
    cout << "r1 *= 0.5: " << r1 << endl;
    cout << "-----------------------------------" << endl;
}