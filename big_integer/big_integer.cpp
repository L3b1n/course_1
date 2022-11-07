#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <iomanip>
#include <algorithm>

using namespace std;

class Big_integer 
{
public:
    Big_integer();
    Big_integer(std::string);
    Big_integer(signed char);
    Big_integer(unsigned char);
    Big_integer(signed short);
    Big_integer(unsigned short);
    Big_integer(signed int);
    Big_integer(unsigned int);
    Big_integer(signed long);
    Big_integer(unsigned long);
    Big_integer(signed long long);
    Big_integer(unsigned long long);
 
    friend const Big_integer operator + (Big_integer, const Big_integer&);
    friend const Big_integer operator - (Big_integer, const Big_integer&);
    friend const Big_integer operator / (const Big_integer&, const Big_integer&);
    friend const Big_integer operator * (const Big_integer&, const Big_integer&);
    friend const Big_integer operator % (const Big_integer&, const Big_integer&);
 
    friend bool operator == (const Big_integer&, const Big_integer&);
    friend inline bool operator < (const Big_integer&, const Big_integer&);
    friend inline bool operator != (const Big_integer&, const Big_integer&);
    friend inline bool operator <= (const Big_integer&, const Big_integer&);
    friend inline bool operator > (const Big_integer&, const Big_integer&);
    friend inline bool operator >= (const Big_integer&, const Big_integer&);
 
    Big_integer& operator += (const Big_integer&);
    Big_integer& operator -= (const Big_integer&);
    Big_integer& operator *= (const Big_integer&);
    Big_integer& operator /= (const Big_integer&);
    Big_integer& operator %= (const Big_integer&);
 
    friend std::ostream& operator << (std::ostream&, const Big_integer&);
    operator std::string() const;
    inline const Big_integer operator + () const;
    inline const Big_integer operator - () const;
    inline const Big_integer operator ++ ();
    inline const Big_integer operator ++ (int);
    inline const Big_integer operator -- ();
    inline const Big_integer operator -- (int);
 
private:
    static const int BASE = 1000000000; // основание системы счисления
    std::vector<int> value;           // хранилище
    bool sign;                         // знак числа
 
    void _remove_leading_zeros();
    void _shift_right();
};

//------------------------------inline-----------------------------------
inline Big_integer& Big_integer::operator += (const Big_integer& value) { return *this = (*this + value);}

inline Big_integer& Big_integer::operator -= (const Big_integer& value) { return *this = (*this - value);}

inline Big_integer& Big_integer::operator *= (const Big_integer& value) { return *this = (*this * value);}

inline Big_integer& Big_integer::operator /= (const Big_integer& value) { return *this = (*this / value);}

inline Big_integer& Big_integer::operator %= (const Big_integer& value) { return *this = (*this % value);}

inline const Big_integer Big_integer::operator + () const { return Big_integer(*this);}
 
inline const Big_integer Big_integer::operator - () const { Big_integer copy(*this); copy.sign = !copy.sign; return copy;}

inline const Big_integer Big_integer::operator ++ () { return (*this += 1);}
 
inline const Big_integer Big_integer::operator ++ (int) { *this += 1; return *this - 1;}
 
inline const Big_integer Big_integer::operator -- () { return *this -= 1;}
 
inline const Big_integer Big_integer::operator -- (int) { *this -= 1; return *this + 1;}
 
inline bool operator != (const Big_integer& number1, const Big_integer& number2) { return !(number1 == number2);}
 
inline bool operator <= (const Big_integer& number1, const Big_integer& number2) { return (number1 < number2 || number1 == number2);}
 
inline bool operator > (const Big_integer& number1, const Big_integer& number2) { return !(number1 <= number2);}
 
inline bool operator >= (const Big_integer& number1, const Big_integer& number2) { return !(number1 < number2);}
//---------------------------end_of_inline-----------------------------------
//----------------------------constructor-----------------------------------
Big_integer::Big_integer() 
{
    this->sign = false;
}

Big_integer::operator std::string() const 
{
    std::stringstream ss;
    ss << *this;
    return ss.str();
}
 
Big_integer::Big_integer(signed char c) 
{
    if(c < 0){ this->sign = true;}
    else{ this->sign = false;}
    this->value.push_back(std::abs(c));
}
 
Big_integer::Big_integer(unsigned char c) 
{
    this->sign = false;
    this->value.push_back(c);
}
 
Big_integer::Big_integer(signed short s) {
    if(s < 0){ this->sign = true;}
    else{ this->sign = false;}
    this->value.push_back(std::abs(s));
}
 
Big_integer::Big_integer(unsigned short s) 
{
    this->sign = false;
    this->value.push_back(s);
}
 
Big_integer::Big_integer(signed int i) 
{
    if(i < 0){ this->sign = true;}
    else{ this->sign = false;}
    this->value.push_back(std::abs(i) % Big_integer::BASE);
    i /= Big_integer::BASE;
    if(i != 0){ this->value.push_back(std::abs(i));}
}
 
Big_integer::Big_integer(unsigned int i) 
{
    this->value.push_back(i % Big_integer::BASE);
    i /= Big_integer::BASE;
    if(i != 0){ this->value.push_back(i);}
}
 
Big_integer::Big_integer(signed long l) 
{
    if(l < 0){ this->sign = true;}
    else{ this->sign = false;}
    this->value.push_back(std::abs(l) % Big_integer::BASE);
    l /= Big_integer::BASE;
    if(l != 0){ this->value.push_back(std::abs(l));}
}
 
Big_integer::Big_integer(unsigned long l) 
{
    this->value.push_back(l % Big_integer::BASE);
    l /= Big_integer::BASE;
    if(l != 0){ this->value.push_back(l);}
}
 
Big_integer::Big_integer(signed long long l) 
{
    if(l < 0){ this->sign = true; l = -l;}
    else{ this->sign = false;}
    do
    {
        this->value.push_back(l % Big_integer::BASE);
        l /= Big_integer::BASE;
    } while(l != 0);
}
 
Big_integer::Big_integer(unsigned long long l) 
{
    this->sign = false;
    do
    {
        this->value.push_back(l % Big_integer::BASE);
        l /= Big_integer::BASE;
    }while(l != 0);
}
 
Big_integer::Big_integer(std::string str) 
{
    if (str.length() == 0){ this->sign = false;}
    else 
    {
        if(str[0] == '-'){ str = str.substr(1); this->sign = true;}
        else{ this->sign = false;}

        for(long long i = str.length(); i > 0; i -= 9) 
        {
            if(i < 9){ this->value.push_back(atoi(str.substr(0, i).c_str()));}
            else{ this->value.push_back(atoi(str.substr(i - 9, 9).c_str()));}
        }
        this->_remove_leading_zeros();
    }
}
//------------------------end_of_constructor-----------------------------------
 
void Big_integer::_remove_leading_zeros() 
{
    while(this->value.size() > 1 && this->value.back() == 0){ this->value.pop_back();}
    if(this->value.size() == 1 && this->value[0] == 0){ this->sign = false;}
}
 
std::ostream& operator << (std::ostream& fo, const Big_integer& bi) 
{
    if(bi.value.empty()){ fo << 0;}
    else 
    {
        if(bi.sign){ fo << '-';}
        fo << bi.value.back();
        char old_fill = fo.fill('0');
        for(long long i = static_cast<long long>(bi.value.size()) - 2; i >= 0; --i){ fo << std::setw(9) << bi.value[i];}
        fo.fill(old_fill);
    }
    return fo;
}

bool operator == (const Big_integer& number1, const Big_integer& number2) 
{
    if(number1.sign != number2.sign){ return 0;}
    if(number1.value.empty()) 
    {
        if(number2.value.empty() || (number2.value.size() == 1 && number2.value[0] == 0)){ return 1;}
        else{ return 0;}
    }
    if(number2.value.empty()) 
    {
        if(number1.value.size() == 1 && number1.value[0] == 0){ return 1;}
        else{ return 0;}
    }
    if(number1.value.size() != number2.value.size()){ return 0;}
    for(size_t i = 0; i < number1.value.size(); ++i){ if(number1.value[i] != number2.value[i]){ return 0;}}
    return 1;
}
 
bool operator < ( const Big_integer& number1, const Big_integer& number2) 
{
    if(number1 == number2){ return 0;}
    if(number1.sign) 
    {
        if(number2.sign){ return ((-number2) < (-number1));}
        else{ return 1;}
    }
    else if(number2.sign){ return 0;}
    else 
    {
        if(number1.value.size() != number2.value.size()){ return number1.value.size() < number2.value.size();}
        else 
        {
            for(long long i = number1.value.size() - 1; i >= 0; --i){ if(number1.value[i] != number2.value[i]){ return number1.value[i] < number2.value[i];}}
            return 0;
        }
    }
}
 
const Big_integer operator + (Big_integer number1, const Big_integer& number2) 
{
    if(number1.sign) 
    {
        if(number2.sign){ return -(-number1 + (-number2));}
        else{ return number2 - (-number1);}
    }
    else if(number2.sign){ return number1 - (-number2);}
    int carry = 0;
    for(size_t i = 0; i < std::max(number1.value.size(), number2.value.size()) || carry != 0; ++i) 
    {
        if(i == number1.value.size()){ number1.value.push_back(0);}
        number1.value[i] += carry + (i < number2.value.size() ? number2.value[i] : 0);
        carry = number1.value[i] >= Big_integer::BASE;
        if(carry != 0){ number1.value[i] -= Big_integer::BASE;}
    }
    return number1;
}
 
const Big_integer operator - (Big_integer number1, const Big_integer& number2) 
{
    if(number2.sign){ return number1 + (-number2);}
    else if(number1.sign){ return -(-number1 + number2);}
    else if(number1 < number2){ return -(number2 - number1);}
    int carry = 0;
    for(size_t i = 0; i < number2.value.size() || carry != 0; ++i) 
    {
        number1.value[i] -= carry + (i < number2.value.size() ? number2.value[i] : 0);
        carry = number1.value[i] < 0;
        if(carry != 0){ number1.value[i] += Big_integer::BASE;}
    }
    number1._remove_leading_zeros();
    return number1;
}
 
const Big_integer operator * (const Big_integer& number1, const Big_integer& number2) 
{
    Big_integer result;
    result.value.resize(number1.value.size() + number2.value.size());
    for(size_t i = 0; i < number1.value.size(); ++i) 
    {
        int carry = 0;
        for(size_t j = 0; j < number2.value.size() || carry != 0; ++j) 
        {
            long long cur = result.value[i + j] + number1.value[i] * 1LL * (j < number2.value.size() ? number2.value[j] : 0) + carry;
            result.value[i + j] = static_cast<int>(cur % Big_integer::BASE);
            carry = static_cast<int>(cur / Big_integer::BASE);
        }
    }
    result.sign = number1.sign != number2.sign;
    result._remove_leading_zeros();
    return result;
}
 
const Big_integer operator / (const Big_integer& number1, const Big_integer& number2) 
{
    if(number2 == 0){ return 0;}
    Big_integer b = number2;
    b.sign = false;
    Big_integer result, current;
    result.value.resize(number1.value.size());
    for(long long i = static_cast<long long>(number1.value.size()) - 1; i >= 0; --i) 
    {
        current._shift_right();
        current.value[0] = number1.value[i];
        current._remove_leading_zeros();
        int x = 0, l = 0, r = Big_integer::BASE;
        while(l <= r) 
        {
            int m = (l + r) / 2;
            Big_integer t = b * m;
            if(t <= current){ x = m; l = m + 1;}
            else{ r = m - 1;}
        }
        result.value[i] = x;
        current = current - b * x;
    }
    result.sign = number1.sign != number2.sign;
    result._remove_leading_zeros();
    return result;
}
 
const Big_integer operator % (const Big_integer& number1, const Big_integer& number2) 
{
    Big_integer result = number1 - (number1 / number2) * number2;
    if(result.sign){ result += number2;}
    return result;
}

void Big_integer::_shift_right() 
{
    if(this->value.size() == 0){ this->value.push_back(0); return;}
    this->value.push_back(this->value[this->value.size() - 1]);
    for(size_t i = this->value.size() - 2; i > 0; --i){ this->value[i] = this->value[i - 1];}
    this->value[0] = 0;
}

int main()
{
    return 0;
}