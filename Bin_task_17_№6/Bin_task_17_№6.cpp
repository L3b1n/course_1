#include <sstream> //принята
#include <stdexcept>
#include <iostream>
#include <tuple>
#include <type_traits>
#include <string>

namespace traits
{
    template<typename T> struct type_holder { T *x;};
    template<typename... Ts> struct template_list {};

    template<typename U>
    constexpr bool is_Integral_Or(type_holder<U> tmp = {})
    {
        return std::is_integral<U>::value;
    }

    template<typename T, typename... Args>
    constexpr const bool is_integral_or(traits::template_list<Args...> = {})
    {
        return std::is_integral<T>::value || (traits::is_Integral_Or(traits::type_holder<Args>{}) || ...);
    }
}

using namespace std;

template <bool b, typename T> 
struct GetType
{ 
    typedef T Type; 
};

template <typename T>
struct GetType<false,T>
{
    typedef int Type;
};

template <bool b, typename T>
struct KSelectValue
{
    static typename GetType<b, T>::Type GetValue(T v)
    {
        if constexpr(b) return v; 
        else return 0;
    }
};

template <typename T1, typename T2>
constexpr decltype(auto) FMax(T1 x, T2 y)
{
    return KSelectValue<is_integral<T1>::value, T1>::GetValue(x) > KSelectValue<is_integral<T2>::value, T2>::GetValue(y) ?
    KSelectValue<is_integral<T1>::value, T1>::GetValue(x) : KSelectValue<is_integral<T2>::value, T2>::GetValue(y);
}

template <typename T, typename... Args>
constexpr auto FMax(T x, Args... args)
{
    return FMax(KSelectValue<is_integral<T>::value, T>::GetValue(x), FMax(args...));
}

template <typename T = void>
constexpr auto FMax2()
{
    static_assert(std::is_integral<T>::value, "Error, you didn't enter arguments in function FMax2"); return 0;
}

template <typename T>
constexpr decltype(auto) FMax2(T x)
{
    static_assert(std::is_integral<T>::value, "You didn't enter none integral arguments in function FMax2");
    return KSelectValue<is_integral<T>::value, T>::GetValue(x);
}

template <typename T1, typename T2>
constexpr decltype(auto) FMax2(T1 x, T2 y)
{
    static_assert(std::is_integral<T1>::value || std::is_integral<T2>::value, "You didn't enter integral arguments in function FMax2");
    return FMax(x, y);
}

template <typename T, typename... Args>
constexpr auto FMax2(T x, Args... args)
{
    static_assert(traits::is_integral_or<T, Args...>(), "You didn't enter integral arguments in function FMax2");
    return FMax(KSelectValue<is_integral<T>::value, T>::GetValue(x), FMax(args...));
}

int main()
{
    // auto t = FMax2();
    // cout << "t = " << t  << endl;

    string str1 = "hello";
    auto l = FMax2(str1, str1, 10);
    cout << "l = " << l  << endl;

    // auto n = FMax2(3.45, double(10));
    // cout << "n = " << n  << endl;

    string str = "wteyuqwteu";
    int x = 5;
    int& z = x;
    auto f = FMax2(z, str, (float)45, 3.34);
    cout << "f = " << f  << endl;

    char chr = 'a';
    auto y = FMax2(1, 2, 3.45, z, chr, (long long)4, z, str);
    cout << "y = " << y << endl;
    
    auto k = FMax2(2, 3.5, 4, 'a', 32, string("abc"), (short)12);
    cout << "k = " << k << endl;
    return 0;
}