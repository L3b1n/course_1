#include<iostream>
#include<iomanip>
#include<cmath>

using namespace std;

int main()
{
    int n1, n2;
    const double Pi = acos(-1);
    double r, h, p, l = 0.0;
    double a[3] = {0};
    double b[3] = {0};
    cin >> r >> h;
    for(int i = 0; i < 3; i++){cin >> a[i];}
    for(int i = 0; i < 3; i++){cin >> b[i];}
    p = 2 * r * Pi / sqrt(r * r + h * h);

    if(a[0] > 0. && a[1] > 0.) n1 = 0;
    if((a[0] < 0. && a[1] > 0.) || (a[0] < 0. && a[1] < 0.)) n1 = 1;
    if(a[0] > 0. && a[1] < 0.) n1 = 2;

    if(b[0] > 0. && b[1] > 0.) n2 = 0;
    if((b[0] < 0. && b[1] > 0.) || (b[1] < 0. && b[1] < 0.)) n2 = 1;
    if(b[0] > 0. && b[1] < 0.) n2 = 2;

    if(a[0] != 0. && b[0] != 0.) p *= (max(Pi * n1 + atan(a[1] / a[0]), Pi * n2 + atan(b[1] / b[0])) - min(Pi * n1 + atan(a[1] / a[0]), Pi * n2 + atan(b[1] / b[0]))) / (2 * Pi);
    else 
        if(a[0] != 0. && b[0] == 0.) p *= (max(Pi * n1 + atan(a[1] / a[0]), 0.0) - min(Pi * n1 + atan(a[1] / a[0]), 0.0)) / (2 * Pi);
        else 
            if(a[0] == 0. && b[0] != 0.) p *= (max(0.0, Pi * n2 + atan(b[1] / b[0])) - min(0.0, Pi * n2 + atan(b[1] / b[0]))) / (2 * Pi);
            else p *= Pi / (2 * Pi);

    if(a[2] == 0 && b[2] == 0)
        l = sqrt(pow(a[0] - b[0], 2) + pow(a[1] - b[1], 2));
    if((a[0,1,2] != 0 && b[0,1,2] != 0) || (a[2] != b[2] && (a[0, 1] == 0 || b[0, 1] == 0)))
        l = sqrt(pow((h - a[2]) * r / h, 2) + pow(h - a[2], 2) + pow((h - b[2]) * r / h, 2) + pow(h - b[2], 2) - 2 * sqrt((pow((h - a[2]) * r / h, 2) + pow(h - a[2], 2)) * (pow((h - b[2]) * r / h, 2) + pow(h - b[2], 2))) * cos(p));
    if(a[2] == 0)
        l = sqrt(a[0] * a[0] + r * r) + b[2] / sin(atan(h / r));
    if(b[2] == 0)
        l = sqrt(b[0] * b[0] + r * r) + a[2] / sin(atan(h / r));
    if(a[2] == 0 && (a[0] == b[0] || a[1] == b[1]))
        l = max(r, a[0]) - min(r, a[0]) + b[2] / sin(atan(h / r));
    if(b[2] == 0 && (a[0] == b[0] || a[1] == b[1]))
        l = max(r, b[0]) - min(r, b[0]) + a[2] / sin(atan(h / r));
    if(a[2] != 0 && b[2] != 0 && a[0] == -b[0] && a[1] == -b[1])
        l = 2 * sqrt(h * h + r * r) - (a[2] + b[2]) / sin(atan(h / r));
    cout << fixed << setprecision(8) << l << endl;
}




// 1 1
// 0.0 0.5 0.0
// 0.0 -0.5 0.0

// 1 2
// 1.0 0.0 0.0 
// 0.0 0.0 2.0

// 1 1
// 0.0 0.0 0.0
// -0.7 0.7 0.0

// 1 1
// 1.0 1.0 1.0
// -0.7 0.7 0.7

// 1 2
// 0.7 0.7 0.0 
// 0.0 0.0 2.0

// if((x1 == 0. && z1 == 0. && x2 == 0. && z2 == 0.) ||(z1 == 0. && z2 == 0. && y1 == 0 && y2 == 0.))
//     l = max(y1, y2) - min(y1, y2) + max(x1, x2) - min(x1, x2);
// if(z1 == z2 && x1 != 0 && x2 != 0 && (y1 != 0 || y2 != 0))
//     l = ((h - z1) * r / h) * (max(atan(y1 / x1), atan(y2 / x2)) - min(atan(y1 / x1), atan(y2 / x2)));
// if(z1 == z2 && x1 == 0 && x2 != 0 && (y1 != 0 || y2 != 0))
//     l = ((h - z1) * r / h) * (max(0.0, atan(y2 / x2)) - min(0.0, atan(y2 / x2)));
// if(z1 == z2 && x2 == 0 && x1 != 0 && (y1 != 0 || y2 != 0))
//     l = ((h - z1) * r / h) * (max(0.0, atan(y1 / x1)) - min(0.0, atan(y1 / x1)));
// if(z1 != z2 && (x1 == 0 || x2 == 0) && (y1 == 0 || y2 == 0))
//     l = sqrt(pow((max(z1, z2) - min(z1, z2)), 2) + pow((max(x1, x2) - min(x1, x2)), 2) + pow((max(y1, y2) - min(y1, y2)), 2));
// cout << (atan(y2 / x2)) * 180 / Pi << endl;