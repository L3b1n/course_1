#include <map>
#include <cmath>
#include <vector>
#include <fstream>
#include <iostream>
#include <iterator>
#include <algorithm>

int i = 1;
std::vector<int> answer;
std::map<long long, long long> sum;

int main()
{
    std::ios_base::sync_with_stdio(0);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    std::cin.tie(0);
    std::cout.tie(0);
    int n;
    std::cin >> n;
    for(int i = 0; i < std::pow(n, 2); i++)
    {
        long long temp;
        std::cin >> temp;
        sum[temp]++;
    }
    answer.resize(n);
    std::map<long long, long long>::iterator iterator = sum.begin();
    answer[0] = iterator->first >> 1; iterator->second--;
    std::for_each(++answer.begin(), answer.end(), 
        [&iterator](int& tempI){
            while(!iterator->second){ iterator++;}
            tempI = iterator->first - answer[0];
            std::for_each(answer.begin(), (answer.begin() + i), 
                [&tempI](const int& tempJ){
                    sum[tempI + tempJ] -= 2;
                }
            );
            sum[tempI + tempI]--;
            i++;
        }
    );
    std::copy(answer.begin(), answer.end(), std::ostream_iterator<int>(std::cout, "\n"));
    return 0;
}