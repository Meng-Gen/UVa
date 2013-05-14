// Let Oi be the center of Ci circle where i = 1, 2, 3.
// Then O1 O2 O3 forms a triangle T having sides R2+R3, R3+R1, R1+R2 and 
// opposite angles A, B, C, respectively.  
// Note that we can compute A, B, C by Law of cosines.
// 
// To get the area of G, we need to compute the following four areas:
//     T = 1/2 (R2+R3)(R3+R1) sin(C)
//     T1 = T intersects C1 = 1/2 R1 * R1 * A
//     T2 = T intersects C2 = 1/2 R2 * R2 * B
//     T3 = T intersects C3 = 1/2 R3 * R3 * C
//
// Therefore, G = T - T1 - T2 - T3. 
#include <iostream>
#include <math.h>
#include <stdio.h>

int main(int argc, char* argv[])
{
    int k;
    std::cin >> k;
    for (int i = 0; i < k; i++)
    {
        double R[3];
        std::cin >> R[0] >> R[1] >> R[2];
        
        double a = R[1] + R[2];
        double b = R[0] + R[2];
        double c = R[0] + R[1];

        // Law of cosines
        double A = acos((b*b + c*c - a*a) * 0.5 / b / c);
        double B = acos((c*c + a*a - b*b) * 0.5 / c / a);
        double C = acos((a*a + b*b - c*c) * 0.5 / a / b);

        double G = 0.5 * a * b * sin(C) 
            - 0.5 * A * R[0] * R[0] 
            - 0.5 * B * R[1] * R[1] 
            - 0.5 * C * R[2] * R[2];

        printf("%.6f\n", G);
    }
    return 0;
}