#include <iostream>
#include <math.h>
#include <stdio.h>

long long SquareRoot(long long n)
{
    long long rv = sqrt((double)n);
    for (long long i = rv - 2; i <= rv + 2; i++) 
    {
        if ((i * i <= n) && (i+1)*(i+1) > n)
        {
            return i;
        }
    }
    return rv;
}

long long H(long long n)
{
    long long n_sqrt = SquareRoot(n);
    long long sum = 0;
    long long prev_pos = 0;
    long long curr_pos = n;
    for (long long i = 1; i <= n_sqrt; i++) 
    {
        sum += n/i;
        if (i != n/i) 
        {
            sum += (i * (n/i - n/(i+1)));
        }
    }
    return sum;
}

int main(int argc, char* argv[]) 
{
    int num_testcases;
    std::cin >> num_testcases;

    for (int case_id = 0; case_id < num_testcases; case_id++)
    {
        long long n;
        std::cin >> n; 
        printf("%lld\n", H(n));
    }
    return 0;
}