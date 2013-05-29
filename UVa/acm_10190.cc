#include <iostream>
#include <vector>
#include <stdio.h>

std::vector<long long> r;

bool IsBoring(long long n, long long m)
{
    r.clear();
    if (n == 0 || m < 2)
    {
        return true;
    }

    while (1)
    {
        if (n % m == 0)
        {
            r.push_back(n);
            n /= m;
            if (n == 1)
            {
                r.push_back(1);
                break;
            }
        }
        else 
        {
            return true;
        }
    }
    return false;
}

int main(int argc, char* argv[])
{
    long long n;
    long long m;
    while (std::cin >> n >> m)
    {
        if (IsBoring(n, m))
        {
            puts("Boring!");
        }
        else
        {
            unsigned int r_length = r.size();
            for (unsigned int i = 0; i < r_length; i++)
            {
                printf("%lld", r[i]);
                if (i != r_length - 1)
                {
                    putchar(' ');
                }
                else
                {
                    putchar('\n');
                }
            }
        }
    }
    return 0;
}