// Reference: http://pballew.net/kmedian.html
// Or you can google: ``area of a triangle from medians''
// It is taught in my junior high school.

#include <iostream>
#include <math.h>
#include <stdio.h>

int main(int argc, char* argv[])
{
    double a;
    double b;
    double c;
    while (std::cin >> a >> b >> c)
    {
        if (a <= 0.0 || b <= 0.0 || c <= 0.0)
        {
            printf("%.3lf\n", -1.0);
            continue;
        }
        if ((a + b > c) && (b + c > a) && (c + a > b))
        {
            double p = (a+b+c)/2.0;
            double area_of_medians = sqrt(p*(p-a)*(p-b)*(p-c));
            double area = area_of_medians * 4.0 / 3.0;
            printf("%.3lf\n", area);
        }
        else 
        {
            printf("%.3lf\n", -1.0);
        }
    }
    return 0;
}