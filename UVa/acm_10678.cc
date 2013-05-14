// Reference: http://en.wikipedia.org/wiki/Ellipse
// The area enclosed by an ellipse is PI*a*b, where a and b are one-half of 
// the ellipse's major and minor axes respectively.
#include <iostream>
#include <math.h>
#include <stdio.h>

#define PI (2.0*acos(0.0))

int main(int argc, char* argv[])
{
    int N;
    std::cin >> N;
    for (int n = 0; n < N; n++)
    {
        int D; // 2c, where c^2 = a^2 - b^2
        int L; // 2a
        std::cin >> D >> L;

        double a = (double)L / 2.0;
        double c = (double)D / 2.0;
        double b = sqrt(a*a - c*c);
        printf("%.3lf\n", PI * a * b);
    }

    return 0;
}