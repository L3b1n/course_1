// 19 №10 //принята
#include <limits>
#include <type_traits>
#include <iostream>
#include <compare>
#include <limits>

#define IS_NEGATIVE(x) ((x) & (1U << ((sizeof(x)*CHAR_BIT)-1)))

namespace cx
{
    template <typename FloatingPoint>
    constexpr FloatingPoint abs(FloatingPoint x, typename std::enable_if<std::is_floating_point<FloatingPoint>::value>::type* = nullptr)
    {
        return x >= 0 ? x : x < 0 ? -x : 0;
    }

    namespace detail
    {
        template <typename T>
        constexpr bool feq(T x, T y)
        {
            return abs(x - y) <= std::numeric_limits<T>::epsilon();
        }
    }

    namespace detail
    {
        template <typename T>
        constexpr T exp(T x, T sum, T n, int i, T t)
        {
            return feq(sum, sum + t/n) ? sum : exp(x, sum + t/n, n * i, i+1, t * x);
        }
    }
    template <typename FloatingPoint>
    constexpr FloatingPoint exp(FloatingPoint x, typename std::enable_if<std::is_floating_point<FloatingPoint>::value>::type* = nullptr)
    {
        return true ? detail::exp(x, FloatingPoint{1}, FloatingPoint{1}, 2, x) : 0;
    }
    template <typename Integral>
    constexpr double exp(Integral x, typename std::enable_if<std::is_integral<Integral>::value>::type* = nullptr)
    {
        return detail::exp<double>(x, 1.0, 1.0, 2, x);
    }

    namespace detail
    {
        template <typename T>
        constexpr T log_iter(T x, T y)
        {
            return y + T{2} * (x - cx::exp(y)) / (x + cx::exp(y));
        }
        template <typename T>
        constexpr T log(T x, T y)
        {
            return feq(y, log_iter(x, y)) ? y : log(x, log_iter(x, y));
        }
        constexpr long double e()
        {
            return 2.71828182845904523536l;
        }

        template <typename T>
        constexpr T logGT(T x)
        {
            return x > T{0.25} ? log(x, T{0}) : logGT<T>(x * e() * e() * e() * e() * e()) - T{5};
        }

        template <typename T>
        constexpr T logLT(T x)
        {
            return x < T{1024} ? log(x, T{0}) : logLT<T>(x / (e() * e() * e() * e() * e())) + T{5};
        }
    }
    template <typename FloatingPoint>
    constexpr FloatingPoint log(FloatingPoint x, typename std::enable_if<std::is_floating_point<FloatingPoint>::value>::type* = nullptr)
    {
        return x < 0 ? 0 : x >= FloatingPoint{1024} ? detail::logLT(x) : detail::logGT(x);
    }
    template <typename Integral>
    constexpr double log(Integral x, typename std::enable_if<std::is_integral<Integral>::value>::type* = nullptr)
    {
        return log(static_cast<double>(x));
    }

    template <typename FloatingPoint>
    constexpr FloatingPoint log2(FloatingPoint x, typename std::enable_if<std::is_floating_point<FloatingPoint>::value>::type* = nullptr)
    {
        return log(x) / log(FloatingPoint{2});
    }
    template <typename Integral>
    constexpr float log2(Integral x, typename std::enable_if<std::is_integral<Integral>::value>::type* = nullptr)
    {
        return log2(static_cast<double>(x));
    }
}

using namespace std;
using namespace cx;

constexpr int GetNumber(unsigned int a)
{
    return log2(a) - 1;
    // return a == 1 ? 0 : 1 + GetNumber(a >> 1);
}

int main()
{
    constexpr unsigned int n = numeric_limits<unsigned int>::max();
    constexpr int size[GetNumber(n)] = {};
    cout << sizeof(size) / sizeof(int) << endl;
}