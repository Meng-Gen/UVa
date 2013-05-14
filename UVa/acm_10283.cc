#include <iostream>
#include <math.h>
#include <stdio.h>

#define PI (2.0*acos(0.0))

// R = r + r / sin(PI/n)
int main(int argc, char* argv[])
{
    int R;
    int N;
    while (std::cin >> R >> N)
    {
        double r_factor = 1.0;
        if (N != 1)
        {
            r_factor = 1.0 / (1.0 + 1.0/sin(PI/(double)N));
        }
        double r = R * r_factor;

        // n/2 * (R-r)^2 * sin(2PI/n).
        double polygon_area = R - r;
        polygon_area *= polygon_area;
        polygon_area = polygon_area * (double)N * 0.5 * sin (2*PI/(double)N);
        double I = 0.0;
        if (N > 2)
        {
            I = polygon_area - PI * r * r * (double)(N - 2)/2.0;
        }
        double E = 0.0;
        if (N > 1)
        {
            E = PI * (R * R - (double)N * r * r) - I;
        }

        printf("%.10lf %.10lf %.10lf\n", r, I, E);
    }

    return 0;
}