// By Heron's formula,
//     T = sqrt(p(p-a)(p-b)(p-c)), 
//     ^^^^^^^^^^^^^^^^^^^^^^^^^^
// where p = (a+b+c)/2 is the semiperimeter.
// Also, we have 
//     T = 1/2 a H_a = 1/2 b H_b = 1/2 c H_c.  
//     ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
// So, 
//     T/H_a = a/2, 
//     T/H_b = b/2, 
//     T/H_c = c/2.  
// Sum them up, 
//     T(1/H_a + 1/H_b + 1/H_c) = p.
// Observe that p-a = T(1/H_a + 1/H_b + 1/H_c) - 2T/H_a.  In brief,
//     p-a = T(1/H_b + 1/H_c - 1/H_a)
//     p-b = T(1/H_c + 1/H_a - 1/H_b)
//     p-c = T(1/H_a + 1/H_b - 1/H_c)
// Replace p, p-a, p-b, p-c of Heron's formula in terms of H_a, H_b, H_c.
//     T^2 = T(1/H_a + 1/H_b + 1/H_c) * T(1/H_b + 1/H_c - 1/H_a) *
//           T(1/H_c + 1/H_a - 1/H_b) * T(1/H_a + 1/H_b - 1/H_c)
// Therefore,
//     T^{-1} = sqrt((1/H_a + 1/H_b + 1/H_c) * (1/H_b + 1/H_c - 1/H_a) *
//     ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
//              (1/H_c + 1/H_a - 1/H_b) * (1/H_a + 1/H_b - 1/H_c)).
//              ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

#include <iostream>
#include <math.h>
#include <stdio.h>

int main(int argc, char* argv[])
{
    int n; // the number of invalid inputs after which the input will terminate
    std::cin >> n;
    while (n > 0)
    {
        double H[3];
        std::cin >> H[0] >> H[1] >> H[2];
    
        // a > 0 <=> H_a > 0
        // b > 0 <=> H_b > 0
        // c > 0 <=> H_c > 0
        if (H[0] <= 0.0 || H[1] <= 0.0 || H[2] <= 0.0)
        {
            n--;
            printf("These are invalid inputs!\n");
            continue;
        }

        double reciprocal_sum = 1.0/H[0] + 1.0/H[1] + 1.0/H[2]; 
        double diff[3];
        for (int i = 0; i < 3; i++)
        {
            diff[i] = reciprocal_sum - 2.0/H[i];
        }

        // a + b > c <=> 1/H_a + 1/H_b > 1/H_c
        // b + c > a <=> 1/H_b + 1/H_c > 1/H_a
        // c + a > b <=> 1/H_c + 1/H_a > 1/H_b
        if (diff[0] <= 0.0 || diff[1] <= 0.0 || diff[2] <= 0.0)
        {
            n--;
            printf("These are invalid inputs!\n");
            continue;
        }

        double T = 1.0 / sqrt(reciprocal_sum * diff[0] * diff[1] * diff[2]);
        printf("%.3f\n", T);
    }
    return 0;
}