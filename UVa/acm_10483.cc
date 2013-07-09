#include <iostream>
#include <stdio.h>

int main(int argc, char* argv[])
{
    char decimal_point;
    long long integer_part;
    long long decimal_part;
    long long L, H;

    std::cin >> integer_part >> decimal_point >> decimal_part;
    L = integer_part * 100 + decimal_part;
    std::cin >> integer_part >> decimal_point >> decimal_part;
    H = integer_part * 100 + decimal_part;

    long long c, product;
    bool found;
    for (long long sum = L; sum <= H; sum++)
    {
        found = false;
        for (long long a = 1; a < sum; a++)
        {
            if (found)
            {
                break;
            }
            for (long long b = a; b < sum; b++)
            {
                if (found)
                {
                    break;
                }
                c = sum - a - b;
                if (c < b)
                {
                    break;
                }
                product = a * b * c;
                if (product % 10000 == 0 && product / 10000 == sum)
                {
                    printf("%lld.%02lld = "
                        "%lld.%02lld + %lld.%02lld + %lld.%02lld = "
                        "%lld.%02lld * %lld.%02lld * %lld.%02lld\n", 
                        sum/100, sum%100, 
                        a/100, a%100, b/100, b%100, c/100, c%100,
                        a/100, a%100, b/100, b%100, c/100, c%100);
                    found = true;
                }
            }
        }
    }

    return 0;
}