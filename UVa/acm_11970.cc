#include <iostream>
#include <math.h>
#include <stdio.h>

int main(int argc, char* argv[])
{
    int T, N;
    int denominator, max_denominator, X;
    std::cin >> T;
    for (int case_id = 1; case_id <= T; case_id++)
    {
        printf("Case %d:", case_id);
        std::cin >> N;
        max_denominator = sqrt(double(N));
        for (int denominator = max_denominator; denominator > 0; denominator--)
        {
            X = N - denominator * denominator;
            if (X && X % denominator == 0)
            {
                printf(" %d", X);
            }
        }

        putchar('\n');
    }

    return 0;
}