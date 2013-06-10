// Let f(x) = pe^{-x} + q sin(x) + r cos(x) + s tan(x) + t x^2 + u = 0
// f'(x) = -p e^{-x} + q cos(x) - r sin(x) + s sec^{2}(x) + 2t x <= 0.
// So f(x) is a non-increasing function.

#include <iostream>
#include <math.h>
#include <stdio.h>

#define EPSILON (1e-7)

int p, q, r, s, t, u;

double f(double x)
{
    return p*exp(-x) + q*sin(x) + r*cos(x) + s*tan(x) + t*x*x + u;
}

double df(double x)
{
    return -p*exp(-x) + q*cos(x) - r*sin(x) + s/cos(x)/cos(x) + 2*t*x;
}

double newton_method()
{
    double x = 0.5;
    double next_x;
    while (1)
    {
        double next_x = x - f(x) / df(x);
        if (fabs(next_x - x) < EPSILON) 
        {   
            return x;
        }
        x = next_x;
    }
}

int main(int argc, char* argv[]) 
{
    while (std::cin >> p >> q >> r >> s >> t >> u)
    {
        if (f(0) * f(1) > 0)
        {
            puts("No solution");
        }
        else if (p + r + u == 0)
        {
            puts("0.0000");
        }
        else
        {
            printf("%.4lf\n", newton_method());
        }
    }
    return 0;
}