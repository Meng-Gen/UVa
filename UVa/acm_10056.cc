#include <iostream>
#include <stdio.h>

#define MAGIC_EPSILON (1e-8)

int main(int argc, char* argv[])
{
    int S;
    std::cin >> S;
    while (S--)
	{
        int N;
        double p;
        int I;
        std::cin >> N >> p >> I;
        
        if (p == 0.0)
        {
            puts("0.0000");
            continue;
        }

        double q = 1.0 - p;
        double r = 1.0;
        for (int i = 0; i < N; i++)
        {
            r *= q;
        }
        
        double a_0 = p;
        for (int i = 1; i < I; i++)
        {
            a_0 *= q;
        }

        printf("%.4lf\n", a_0 / (1.0 - r) + MAGIC_EPSILON);
	}
	
	return 0;
}