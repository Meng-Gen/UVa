#include <iostream>
#include <stdio.h>

long long query[1000001] = {};

void InitQueryTable()
{
    // http://oeis.org/A002623
    // a(n+1) = a(n) + {(k-1)*k if n=2*k} or {k*k if n=2*k+1}.
    bool is_even = false;
    for (long long i = 1; i < 1000001; i++)
    {
        long long k = i/2;
        if (is_even)
        {
            query[i] = query[i-1] + k * (k - 1);
        }
        else
        {
            query[i] = query[i-1] + k * k;
        }
        is_even = !is_even;
    }
}

int main(int argc, char* argv[])
{
    InitQueryTable();

    long long n;
    while (std::cin >> n && (n >= 3))    
    {
        printf("%lld\n", query[n-1]);
    }

    return 0;
}