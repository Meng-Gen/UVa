#include <iostream>
#include <stdio.h>

int main(int argc, char* argv[])
{
    long long a, b, c, d, L;
    while (std::cin >> a >> b >> c >> d >> L && (a || b || c || d || L))
    {
        int count = 0;

        // f(0)
        long long f = c % d;
        if (f == 0)
        {
            count++;
        }

        // f(n) = f(n-1) + a(2x-1) + b
        for (long long i = 1; i <= L; i++)
        {
            f = (f + a * (2 * i - 1) + b) % d;
            if (f == 0)
            {
                count++;
            }
        }

        printf("%d\n", count);
    }
    
    return 0;
}