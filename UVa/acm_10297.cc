#include <iostream>
#include <math.h>
#include <stdio.h>

#define PI (acos(-1.0))

//     PI (D/2)^2 D = V + PI (d/2)^2 + 2 (PI/3 (D/2)^2 D/2 - PI/3 (d/2)^2 d/2)
// <=> PI/4 D^3 = V + PI/4 d^2 + 2(PI/24 D^3 - PI/24 d^3)
// <=> V = PI/6 (D^3 - d^3)
// <=> d^3 = D^3 - 6/PI V 

int main(int argc, char* argv[])
{
    int D, V;
    while (std::cin >> D >> V && (D || V))
    {
        double d = pow((double)(D*D*D) - 6.0 * (double)V / PI, 1.0/3.0);
        printf("%.3lf\n", d);
    }
    return 0;
}