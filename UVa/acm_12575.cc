#include <iostream>
#include <math.h>
#include <stdio.h>

#define PI (acos(-1.0))
#define MAGIC_EPSILON (1e-8)

int main(int argc, char* argv[]) 
{
    int num_testcases;
    std::cin >> num_testcases;
    while (num_testcases--)
    {
        long long A, B;
        std::cin >> A >> B;
        if(A == 0 && B == 0) {
            puts("0.00 0.00");
            continue;
        }
        double R = sqrt((double)(A*A + B*B));
        double alpha = atan2((double)A, (double)B);
        if (alpha + MAGIC_EPSILON < 0.0)
        {
            alpha += (PI * 2.0);
        }

        printf("%.2lf %.2lf\n", alpha, R);
    }
    return 0;
}