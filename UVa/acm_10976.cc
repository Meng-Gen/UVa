//  1/k = 1/x + 1/y where x >= y.
//
//  (1) 1/k <= 1/y + 1/y = 2/y <=> y <= 2k.  
//  (2) 1/x = 1/k - 1/y > 0 <=> y > k.
//  By (1) and (2), we need to check the value of y from (k+1) to 2k.
//
//  Note: 1/k = 1/(k+1) + 1/(k(k+1)) is always true.
#include <iostream>
#include <stdio.h>

long long sol_x[10001] = {};
long long sol_y[10001] = {};

int main(int argc, char* argv[])
{
    long long k;
    while (std::cin >> k) 
    {
        int sol_count = 0;
        for (long long y = k+1; y <= 2*k; y++)
        {
            if ((y*k) % (y-k) == 0)
            {
                sol_x[sol_count] = (y*k)/(y-k);
                sol_y[sol_count] = y;
                sol_count++;
            }
        }

        // Generate summary.
        printf("%d\n", sol_count);
        for (int i = 0; i < sol_count; i++)
        {
            printf("1/%lld = 1/%lld + 1/%lld\n", k, sol_x[i], sol_y[i]);
        }
    }
    return 0;
}
