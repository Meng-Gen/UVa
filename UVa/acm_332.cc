#include <iostream>
#include <string>
#include <stdio.h>

long long GreatestCommonDivisor(long long a, long long b) {
    while (b) {
        long long t = b;
        b = a % t;
        a = t;
    }
    return a;
}

long long Pow10(long long n)
{
    long long rv = 1;
    for (int i = 0; i < n; i++)
    {
        rv *= 10;
    }
    return rv;
}

long long ConvertNumber(const std::string& number)
{
    long long rv = 0;
    for (int i = 0; i < number.size(); i++)
    {
        rv *= 10;
        rv += number[i] - '0';
    }
    return rv;
}

int main(int argc, char* argv[])
{
    int case_id = 1;

    long long j;
    char dummy; // eat |0| and |.|
    std::string decimal_fraction_string;
    while (std::cin >> j && (j != -1))
    {
        std::cin >> dummy >> dummy >> decimal_fraction_string;
        long long k = decimal_fraction_string.size() - j;
        long long decimal_fraction = ConvertNumber(decimal_fraction_string);

        long long numerator = 0;
        long long denominator = 0;
        if (j)
        {
            numerator = decimal_fraction - decimal_fraction / Pow10(j);
            denominator = Pow10(k+j) - Pow10(k);
        }
        else
        {
            numerator = decimal_fraction;
            denominator = Pow10(k);
        }
        long long gcd = GreatestCommonDivisor(numerator, denominator);
        numerator /= gcd;
        denominator /= gcd;

        printf("Case %d: %lld/%lld\n", 
            case_id, numerator, denominator);
        case_id++;
    }
    return 0;
}