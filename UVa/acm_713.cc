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
            number_builder << number_[i];
        }
        return number_builder.str();
    }

    std::string reversed_number() 
    { 
        std::stringstream number_builder;
        for (int i = 0; i < pos_; i++)
        {
            number_builder << number_[i];
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
            number_[pos_] = number[i] - '0';
            pos_++;
        }
        Normalize();
    }

    BigInteger Add(const BigInteger& a)
    {
        BigInteger rv;

        int longest_pos = max(pos_, a.pos_);
        for (int i = 0; i < longest_pos; i++)
        {
            rv.number_[i] += (number_[i] + a.number_[i]);
            rv.number_[i+1] += rv.number_[i]/10;
            rv.number_[i] %= 10;
        }
        rv.pos_ = longest_pos + 1;
        rv.Normalize();

        return rv;
    }

    void Normalize()
    {
        for (int i = pos_; i < 300; i++)
        {
            number_[i] = 0;
        }
        int last_nonzero_pos = 300 - 1;
        for (; last_nonzero_pos >= 0; last_nonzero_pos--)
        {
            if (number_[last_nonzero_pos] != 0)
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

    int number_[300];
    int pos_;
};

int main(int argc, char* argv[])
{
    int num_testcase;
    std::cin >> num_testcase;
    for (int i = 0; i < num_testcase; i++)
    {
        std::string A;
        std::string B;
        std::cin >> A >> B; 
        
        reverse(A.begin(), A.end());
        reverse(B.begin(), B.end());
        std::string sum = BigInteger(A).Add(BigInteger(B)).reversed_number();

        // Lazy dirty implementation (reuse)
        std::cout << BigInteger(sum).number() << std::endl;
    }
    return 0;
}