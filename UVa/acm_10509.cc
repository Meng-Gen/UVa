// n^{1/3} = a + dx.
// n = a^3 + 3a^2 dx + 3a (dx)^2 + (dx)^3 = a^3 + 3a^2 dx + O((dx)^2).
// We ignore O((dx)^2) terms and then get dx = (n - a^3)/(3a^2).
#include <iostream>
#include <stdio.h>
#include <math.h>

int main(int argc, char* argv[])
{
    double n;
    while (std::cin >> n)
    {
        if (n == 0)
        {
            break;
        }

        double math_cubic_root = pow((double)n, 1.0/3.0);

        // When we calculate the cubic root of 64, we may get 
        // 3.9999999999999996.  Therefore, we do some adjustment. 
        int a = (int)math_cubic_root;
        if ((a+1)*(a+1)*(a+1) <= n)
        {
            a++;
        }
        double dx = (double)(n - a*a*a)/((double)(3*a*a));
        
        double feynman_cubic_root = a + dx;

        printf("%.4lf\n", feynman_cubic_root);
    }
    return 0;
}