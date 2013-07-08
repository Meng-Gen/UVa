#include <iostream>
#include <stdio.h>

long long n, d;
int digit_frequency[10] = {};

inline void SetDigitFrequency()
{
    for (int i = 0; i <= 9; i++)
    {
        digit_frequency[i] = 0;
    }
    while (n)
    {
        digit_frequency[n % 10]++;
        n /= 10;
    }
}

long long a, b, diff;

inline void RearrangeToMaximum()
{
    a = 0;
    for (int i = 9; i >= 0; i--)
    {
        for (int j = 0; j < digit_frequency[i]; j++)
        {
            a *= 10;
            a += i;
        }
    }
}

inline void RearrangeToMinimum()
{
    b = 0;
    bool has_leading_digit = false;
    bool is_zero_digit_used = false;
    for (int i = 1; i <= 9; i++)
    {
        for (int j = 0; j < digit_frequency[i]; j++)
        {
            has_leading_digit = true;
            b *= 10;
            b += i;

            // 100102 => 211000 - 100012 = 110988 = 9 * 12332
            if (!is_zero_digit_used && has_leading_digit)
            {
                for (int j = 0; j < digit_frequency[0]; j++)
                {
                    b *= 10;
                }
                is_zero_digit_used = true;
            }
        }
    }
}

int main(int argc, char* argv[])
{
    while (std::cin >> n)
    {
        SetDigitFrequency();
        RearrangeToMaximum();
        RearrangeToMinimum();
        diff = a - b;
        printf("%lld - %lld = %lld = 9 * %lld\n", a, b, diff, diff/9);
    }
    return 0;
}