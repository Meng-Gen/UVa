#include <iostream>
#include <stdio.h>

int main(int argc, char* argv[])
{
    long long n, k;
    while (std::cin >> n >> k && (n || k))    
    {
        long long ways = 1;

        // Compute C(n,k) directly
        long long small_k = (k > n/2) ? n - k : k;
        for (int i = 1; i <= small_k; i++)
        {
            ways *= (n - i + 1);
            ways /= i;
        }

        printf("%lld\n", ways);
    }

    return 0;
}