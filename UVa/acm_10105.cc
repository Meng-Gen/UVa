//               n!
// Key: --------------------
//       n_1! n_2! ... n_k!
//
// Also, 12! = 479001600.  Not BigInteger problem.

#include <iostream>

long long factorial(int n)
{
    if (n == 0)
    {
        return 1;
    }
    long long rv = 1;
    for (int i = 1; i <= n; i++)
    {
        rv *= i;
    }
    return rv;
}

int main(int argc, char* argv[])
{
    int N; 
    int K;
    while (std::cin >> N >> K)
    {
        long long rv = factorial(N);
        for (int i = 0; i < K; i++)
        {
            int nk;
            std::cin >> nk;
            rv /= factorial(nk);
        }
        std::cout << rv << std::endl;
    }
    return 0;
}