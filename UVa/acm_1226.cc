#include <iostream>
#include <string>
#include <stdio.h>

int main(int argc, char* argv[])
{
    long long N;
    std::string P;
    long long r; // r = P % N

    int num_testcases;
    std::cin >> num_testcases; 
    while (num_testcases--)
    {
        r = 0;
        std::cin >> N >> P;
        for (std::string::iterator it = P.begin(); it != P.end(); it++)
        {
            r = (r * 10 + *it - '0') % N;
        }
        printf("%lld\n", r);
    }
    return 0;
}