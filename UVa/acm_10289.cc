#include <iostream>
#include <string>
#include <math.h>
#include <stdio.h>

#define SQRT_2 (sqrt(2.0))
#define SQRT_3 (sqrt(3.0))

int main(int argc, char* argv[])
{
    long double side[7] = {};
    side[0] = 2.0 * SQRT_2 / (1.0 + SQRT_3);
    side[1] = SQRT_2 / SQRT_3;
    side[2] = 4.0 / SQRT_3 / (2.0 + SQRT_2);
    side[3] = 3.0 / (3.0 + SQRT_3);
    side[4] = (63.0 + 59.0 * SQRT_3)/249.0 - sqrt(4.0 + 6.0 * SQRT_3)*(21 - 8 * SQRT_3)/249.0;
    side[5] = (3.0 + SQRT_3) / 9.0;
    side[6] = (1.0 + SQRT_3) / (4.0 + SQRT_3);

    long double S;
    while (std::cin >> S)
    {
        printf("%.10lf %.10lf %.10lf %.10lf %.10lf %.10lf %.10lf\n", 
            S * side[0], 
            S * side[1], 
            S * side[2],
            S * side[3], 
            S * side[4], 
            S * side[5], 
            S * side[6]);
    }
    return 0;
}