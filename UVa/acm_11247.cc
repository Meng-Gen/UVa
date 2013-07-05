#include <iostream>
#include <stdio.h>

int main(int argc, char* argv[])
{
    long long m, x, v, r;
    while (std::cin >> m >> x && (m || x))
    {
        if (x != 100)
        {
            v = (m - 1) * 100 / (100 - x);
            r = ((m - 1) * 100) % (100 - x);
            if (r == 0)
            {
                v--;
            }
            if (v >= m)
            {
                printf("%lld\n", v);
            }
            else
            {
                puts("Not found");
            }
        }
        else
        {
            puts("Not found");
        }
    }
    return 0;
}