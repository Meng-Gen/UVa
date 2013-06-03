// We need to check: 
// (1) Boundary cases: x = 0, x = min(L,W)/2
// (2) Local minimal/maximal of V(x) = x(L-2x)(W-2x).
//
// For (1), it is easy to check.  
// For (2), if x is a local maximum or a local minimum of V(x), 
// then the derivative of V(x) = 12x^2 - 4(L+W)x + LW at x is zero.

#include <iostream>
#include <math.h>
#include <stdio.h>

#define MAGIC_EPSILON (1e-8)

double minimum(double a, double b)
{
    return (a < b) ? a : b;
}

int main(int argc, char* argv[])
{
    double L;
    double W;
    while (std::cin >> L >> W)
	{
        double x = (L + W - sqrt(L*L - L*W + W*W)) / 6.0;
        printf("%.3lf 0.000 %.3lf\n", 
            x + MAGIC_EPSILON, 
            minimum(L, W) * 0.5 + MAGIC_EPSILON);
	}
	
	return 0;
}