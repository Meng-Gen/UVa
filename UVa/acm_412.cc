#include <iostream>
#include <math.h>
#include <stdio.h>

int GreatestCommonDivisor(int a, int b) {
    int t;
    while (b) {
        t = b;
        b = a % t;
        a = t;
    }
    return a;
}

int dataset[55] = {};

int main(int argc, char* argv[])
{
    int n;
    while (std::cin >> n && n)
    {
        int all_pairs_count = n*(n-1)/2;
        int relative_prime_pairs_count = 0;

        for (int i = 0; i < n; i++)
        {
            std::cin >> dataset[i];
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = i+1; j < n; j++)
            {
                if (GreatestCommonDivisor(dataset[i], dataset[j]) == 1)
                {
                    relative_prime_pairs_count++;
                }
            }
        }

        if (relative_prime_pairs_count == 0)
        {
            puts("No estimate for this data set.");
        }
        else
        {
            double estimate = sqrt(6.0 * (double)all_pairs_count / 
                (double)relative_prime_pairs_count);

            // Do not add MAGIC_EPSILON (1e-7)
            printf("%.6lf\n", estimate);
        }
    }
    return 0;
}