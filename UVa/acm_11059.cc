#include <iostream>
#include <stdio.h>
#include <stdlib.h>

long long sequence[20];
int N;

inline long long maximum(long long a, long long b)
{
    return (a > b) ? a : b;
}

int main(int argc, char* argv[]) 
{
    int case_id = 1;
    while (std::cin >> N)
    {
        for (int i = 0; i < N; i++)
        {
            std::cin >> sequence[i];
        }

        // If you cannot find a positive sequence, you should consider 0 
        // as the value of the maximum product.
        long long max_so_far = 0;

        // Ad hoc.
        for (int i = 0; i < N; i++)
        {
            long long max_begin_here = sequence[i];
            long long product = sequence[i];
            for (int j = i+1; j < N; j++)
            {
                product *= sequence[j];
                max_begin_here = maximum(max_begin_here, product);
            }
            max_so_far = maximum(max_so_far, max_begin_here);
        }

        printf("Case #%d: The maximum product is %lld.\n\n", case_id, max_so_far);

        case_id++;
    }
    return 0;
}