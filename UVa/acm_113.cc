#include <iostream>
#include <math.h>
#include <stdio.h>

int main(int argc, char* argv[])
{
    double n, p;
    while (std::cin >> n >> p)
    {
        printf("%.0lf\n", pow(p, 1.0/n));
    }
    return 0;
}