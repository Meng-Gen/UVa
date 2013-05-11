#include <iostream>
#include <string>
#include <stdio.h>

long long reverse_digits(long long num)
{
    long long rv = 0;

    while (num >= 10)
    {
        rv = rv * 10 + (num % 10);
        num /= 10;
    }
    rv = rv * 10 + num;

    return rv;
}

int main(int argc, char* argv[])
{
    long long N;
    std::cin >> N;

    for (long long i = 0; i < N; i++)
    {
        long long P;
        std::cin >> P;
     
        long long reverse_P;
        long long num_iterations = 0;
        while (1)
        { 
            reverse_P = reverse_digits(P);
            if (P == reverse_P)
            {
                break;
            }
            else
            {
                num_iterations++;
                P += reverse_P;
            }
        }

        std::cout << num_iterations << " " << P << std::endl;
    }

    return 0;
}