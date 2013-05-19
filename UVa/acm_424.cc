// Copy code from UVa 713

#include <algorithm>
#include <iostream>
#include <string>
#include <sstream>
#include <stdio.h>

inline int max(int a, int b)
{
    return (a > b) ? a : b;
}

struct BigInteger
{
    std::string number() 
    { 
        std::stringstream number_builder;
        for (int i = pos_ - 1; i >= 0; i--)
        {
            number_builder << digit_[i];
        }
        return number_builder.str();
    }

    BigInteger() : pos_(0)
    {
        Normalize();
    }

    BigInteger(const std::string& number) : pos_(0)
    {
        for (int i = number.size() - 1; i >= 0; i--)
        {
            digit_[pos_] = number[i] - '0';
            pos_++;
        }
        Normalize();
    }

    void Add(const BigInteger& a)
    {
        int longest_pos = max(pos_, a.pos_);
        for (int i = 0; i < longest_pos; i++)
        {
            digit_[i] += a.digit_[i];
            digit_[i+1] += digit_[i]/10;
            digit_[i] %= 10;
        }
        pos_ = longest_pos + 1;
        Normalize();
    }

    void Normalize()
    {
        for (int i = pos_; i < 300; i++)
        {
            digit_[i] = 0;
        }
        int last_nonzero_pos = 300 - 1;
        for (; last_nonzero_pos >= 0; last_nonzero_pos--)
        {
            if (digit_[last_nonzero_pos] != 0)
            {
                break;
            }
        }

        pos_ = last_nonzero_pos + 1;

        // Special case: zero
        if (pos_ == 0) 
        {
            pos_ = 1;
        }
    }

    int digit_[300];
    int pos_;
};

int main(int argc, char* argv[])
{
    BigInteger sum;

    std::string very_long_integer;
    while (std::cin >> very_long_integer)
    {
        if (very_long_integer == "0")
        {
            break;
        }
        sum.Add(BigInteger(very_long_integer));
    }
    std::cout << sum.number() << std::endl;
    return 0;
}