#include <iostream>
#include <stdio.h>

int main(int argc, char* argv[])
{
    int num_testcases;
    std::cin >> num_testcases;
    
    int N, T, P;
    while (num_testcases--)
    {
        std::cin >> N >> T >> P;
        int extra_marks = T - N * P;
        if (extra_marks < 0)
        {
            puts("0");
            continue;
        }
        
        // Number of combinations with repetition
        // The answer is C(N + extra_marks - 1, extra_marks). 
        long long A = N + extra_marks - 1;
        long long B = (extra_marks > A/2) ? A - extra_marks : extra_marks;
        
        long long ways = 1;
        for (long long i = 1; i <= B; i++)
        {
            ways *= (A - i + 1);
            ways /= i;
        }
        printf("%lld\n", ways);

    }
    return 0;
}