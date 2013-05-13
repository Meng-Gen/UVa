#include <iostream>
#include <math.h>
#include <stdio.h>

// ln(1-x) = - x - x^2/2 - x^3/3 - x^4/4 - ...      (1)
// ln(n)   = L - x - x^2/2 - x^3/3 - x^4/4 - ...    (2)
//
// (2)-(1) => ln(n) - ln(1-x) = L.  Hence, ln(n/(1-x)) = L.
// So, 1-x = ne^{-L}, or x = 1-ne^{-L}.  By |x| < 1, -1 < x < 1.
// So, -1 < 1 - ne^{-L} < 1, or e^L > n/2.
int main(int argc, char* argv[]) 
{
    while (1)
    {
        double n;
        std::cin >> n;
        if (n == 0.0)
        {
            break;
        }
    
        int L = 0;
        while (1)
        {
            if (2.0 * exp((double)L) > n)
            {
                break;
            }
            L++;
        }
        double x = 1 - n * exp((double)(-L));

        printf("%d %.8llf\n", L, x);
    }

    return 0;
}