// Fact: The surface area of a sphere is A = 4*PI*r^2.  
// (http://en.wikipedia.org/wiki/Sphere)
//
// When he divides it in n > 1 equal parts, the area will increase n*PI*r^2.
// So the profit increases by n*PI*r^2 / 4*PI*r^2 = n/4.
#include <iostream>
#include <stdio.h>

int main(int argc, char* argv[])
{
    int N;
    while (1)
    {
        std::cin >> N;
        if (N <= 0)
        {
            break;
        }
        if (N == 1)
        {
            printf("0%%\n");
        }
        else
        {
            printf("%.0lf%%\n", (double)N * 25.0);
        }
    }

    return 0;
}