#include <iostream>
#include <unordered_map>

std::pair<std::string, int> findDecimal(const int& numerator, const int& denominator)
{
    if(numerator == 0){ return std::make_pair("0", 0);}
    int length = 0;
    std::string result;
    std::unordered_map<long long, int> remainders;
    if((numerator < 0) ^ (denominator < 0)){ result += "-";}
    long long num = std::abs(static_cast<long long>(numerator));
    long long den = std::abs(static_cast<long long>(denominator));
    result += std::to_string(num / den);
    long long remainder = num % den;
    if(remainder == 0){ return std::make_pair(result, length);}
    int intLength = result.length();
    result += ".";
    while(remainder != 0)
    {
        if(remainders.find(remainder) != remainders.end())
        {
            result.insert(remainders[remainder], "(");
            result += ")";
            length = result.length() - intLength - 1 - remainders[remainder];
            break;
        }
        remainders[remainder] = result.length();
        remainder *= 10;
        result += std::to_string(remainder / den);
        remainder %= den;
    }
    return std::make_pair(result, length);
}

int main()
{
    int numerator;
    int denominator;
    std::cout << "Enter numerator and denominator: ";
    std::cin >> numerator >> denominator;
    auto [result, length] = findDecimal(numerator, denominator);
    std::cout << "Number period length: " << length << "\n";
    std::cout << "Decimal number: " << result << "\n";
    return 0;
}
