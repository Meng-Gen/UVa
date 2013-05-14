#include <iostream>
#include <math.h>
#include <stdio.h>

#define PI acos(-1.0)

int main(int argc, char* argv[])
{
    double striped_region_factor = 1.0 - sqrt(3.0) + PI / 3.0;
    double dotted_region_factor = -4.0 + 2 * sqrt(3.0) + PI / 3.0; 
    double rest_region_factor = 4.0 - sqrt(3.0) - 2.0 * PI / 3.0;
    double a;
    while (std::cin >> a)
    {
        double square_area = a*a;

        printf("%.3lf %.3lf %.3lf\n", 
            striped_region_factor * square_area,
            dotted_region_factor * square_area,
            rest_region_factor * square_area);
    }

    return 0;
}