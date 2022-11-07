//задание 20 выполнить все 4
#include <iostream>
#include <vector>
#include <set>
#include "KRat.cpp"

using namespace std;

template <typename T, typename ... Args>
auto matches_one(const T& range, Args ... args)
{
    return (std::count(std::begin(range), std::end(range), args) && ...);
}

template <typename T, typename ... Args>
bool add(T &set, Args... args)
{
    return (set.emplace(args).second && ...);
}

template <typename T1, typename T2, typename ... Args>
int matches_all(const T1 min, const T2 max, Args ... args)
{
    return ((min <= args && args <= max) + ...);
}

template <typename T, typename ... Args>
void add_all(T &basket, Args... args)
{
    (basket.emplace_back(args), ...);
}

int main()
{
    std::set<KRat> test1;
    test1.emplace(2); test1.emplace(KRat(3, 4)); test1.emplace(5);
    std::vector<KRat> test2;
    test2.emplace_back(2); test2.emplace_back(4); test2.emplace_back(KRat(1, 7)); 
    std::cout << "\nHow many matches of one element has your range: " << matches_one("abxcyz", 'x', 'y', 'z', 'f') << std::endl;
    std::cout << "Is adding has been completed successfully: " << add(test1, 4, KRat(3, 4), 4, 6, 7) << std::endl;
    for(auto x : test1){ std::cout << x << "  ";} std::cout << std::endl;
    std::cout << "How many matches of all elements has your range: " << matches_all(KRat(3, 4), 20, 100, 104, 35) << std::endl;
    add_all(test2, 3, KRat(1, 9), 6);
    for(auto x : test2){ std::cout << x << "  ";} std::cout << std::endl;
}