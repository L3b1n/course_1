#include <iostream> //принята
#include <cmath>
#include <string>

using namespace std;

int main() 
{
    int a[256] = {0};
    char *str1 = new char(80);
    char *str2 = new char(80);
    cout << "Enter two strings less then 80 simbols: ";
    cin.getline(str1, 80);
    cin.getline(str2, 80);
    for(int i = 0; i < strlen(str1); i++)
    {
        a[(unsigned char)str1[i]]++;
    }
    for(int i = 0; i < strlen(str2); i++)
    {
        if(a[(unsigned char)str2[i]]){ cout << str2[i] << endl; a[(unsigned char)str2[i]] = 0;}
    }
}