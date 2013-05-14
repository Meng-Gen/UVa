// Heron's formula: T = sqrt(p(p-a)(p-b)(p-c)) where p = (a+b+c)/2 is 
// the semiperimeter, or half of the triangle's perimeter.
//
// Also, 
//     T = pr where r is the radius of the incircle.
//     T = abc/(4R) where R is the radius of the circumcircle.
#include <iostream>
#include <math.h>
#include <stdio.h>

#define PI (2.0*acos(0.0))

int main(int argc, char* argv[])
{
    double a;
    double b;
    double c;
    while (std::cin >> a >> b >> c)
    {
        double p = (a+b+c)/2.0;
        double triangle_area = sqrt(p*(p-a)*(p-b)*(p-c));
        double r = triangle_area / p;
        double R = a*b*c / 4.0 / triangle_area;

        double roses_area = r * r * PI;
        double violets_area = triangle_area - roses_area;
        double sunflowers_area = R * R * PI - triangle_area;

        printf("%.4f %.4f %.4f\n", sunflowers_area, violets_area, roses_area);
    }

    return 0;
}