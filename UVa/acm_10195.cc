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
        double r = 0.0;
        if (a != 0.0 && b != 0.0 && c != 0.0)
        {
            double p = (a+b+c)/2.0;
            double area = sqrt(p*(p-a)*(p-b)*(p-c));
            r = area / p;            
        }
        printf("The radius of the round table is: %.3f\n", r);
    }

    return 0;
}