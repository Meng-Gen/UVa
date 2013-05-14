// Sine Theorem:
// For any triangle in the Euclidean plane with sides a, b, c and 
// opposite angles A, B, C, respectively, the equalities
// 
//     a/sin(A) = b/sin(B) = c/sin(C) = 2R
//
// hold, where R is the radius of the circumscribed circle.
// So we have the equation x / sin(3PI/5) = a / sin(7PI/20). 
#include <iostream>
#include <math.h>
#include <stdio.h>

#define PI (acos(-1.0))

int main(int argc, char* argv[])
{
    double factor = sin(PI*0.6) / sin(PI*0.35);
    double a;
    while (std::cin >> a)
    {
        printf("%.10f\n", a * factor);
    }
    return 0;
}