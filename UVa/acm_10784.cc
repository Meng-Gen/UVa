#include <iostream>
#include <math.h>
#include <stdio.h>

// The number of diagonal of the n-side convex polygon is n(n-3)/2 if n > 3.
// So we need to solve the equation n(n-3)/2 = d.
// Therefore, n = (3 + sqrt(9 + 8d)) / 2.
long long GetNumSide(long long d)
{
    long long possible_n = (long long)(3.0 + sqrt(9.0 + 8.0 * d)) * 0.5;
    for (long long i = possible_n - 2; i <= possible_n + 2; i++)
    {
        if (i*(i-3)/2 >= d)
        {
            return i;
        }
    }
    return -1;
}

int main(int argc, char* argv[])
{
    long long num_diagonal;
    int case_id = 1;
    while (std::cin >> num_diagonal && num_diagonal)
    {
        printf("Case %d: %lld\n", case_id, GetNumSide(num_diagonal));
        case_id++;
    }
    return 0;
}