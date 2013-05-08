// UVa 264 with little modification
#include <iostream>
#include <math.h>
#include <stdio.h>

// WA if we use C++ integer datatype instead of |long long|.
long long get_level(long long which_term)
{
    long long possible = (long long)(sqrt((double)which_term * 2.0));
    for (long long j = possible - 1; j <= possible + 2; j++)
    {
        if ((j*(j+1)/2 < which_term) && (which_term <= (j+1)*(j+2)/2))
        {
            return j + 1;
        }
    }
    return 0LL;
}

int main(int argc, char* argv[])
{
    long long which_term;
    while (std::cin >> which_term) 
    {
        long long level = get_level(which_term);
        long long which_term_of_level = level * (level + 1) / 2 - which_term + 1;
        long long numerator = which_term_of_level;
        long long denominator = level - numerator + 1;

        printf("%lld/%lld\n", numerator, denominator);
    }
    return 0;
}
