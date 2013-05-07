#include <iostream>
#include <math.h>
#include <stdio.h>

#define CONSTANT_PI acos(-1.0);

int main(int argc, char* argv[])
{
    int n;
    while (std::cin >> n)
    {
        for (int i = 1; i <= n; i++)
        {
            int flag_length;
            std::cin >> flag_length;
            
            double red_area = (double)flag_length * (double)flag_length * 0.2 * 0.2 * CONSTANT_PI;
            double green_area = (double)flag_length * (double)flag_length * 0.6 - red_area;
            printf("%.2lf %.2lf\n", red_area, green_area);
        }
    }

    return 0;
}