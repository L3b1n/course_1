#include <iostream> //принята 
#include <cmath>

using namespace std;

int number(int x, int y, int z, int &min_number, int &max_number)
{
    if(x == max(x, max(y, z)))
    {
        if(y > z)
        {
            max_number = 100 * x + 10 * y + z;
            min_number = 100 * z + 10 * y + x;
        }
        else 
        {
            max_number = 100 * x + 10 * z + y;
            min_number = 100 * y + 10 * z + x;
        }
    }
    else 
    {
        if(y == max(x, max(y, z)))
        {
            if(x > z)
            {
                max_number = 100 * y + 10 * x + z;
                min_number = 100 * z + 10 * x + y;
            }
            else
            {
                max_number = 100 * y + 10 * z + x;
                min_number = 100 * x + 10 * z + y;
            }
        }
        else 
        {
            if(x > y)
            {
                max_number = 100 * z + 10 * x + y;
                min_number = 100 * y + 10 * x + z;
            }
            else
            {
                max_number = 100 * z + 10 * y + x;
                min_number = 100 * x + 10 * y + z;
            }
        } 
    }
    return(0);
}



int main()
{
    int m, max_number = 0, min_number = 0, x = 0, y = 0, z = 0;
    cout << "Enter M:" << endl;
    cin >> m;

    for(; x < 10; ++x)
    {
        for(; y < 10; ++y)
        {
            for(; z < 10; ++z)
            {
                if(m == (pow(x, 3) + pow(y, 3) + pow(z, 3)))
                {
                    number(x, y, z, max_number, min_number);        
                    cout << "Max_Number = " << max_number << endl;
                    cout << "Min_Number = " << min_number << endl;
                    return 0;
                }
            }
            z = 0;
        }
        y = 0;
    }
    cout << "There isn't such number" << endl;
}