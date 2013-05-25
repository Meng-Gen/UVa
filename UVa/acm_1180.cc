#include <iostream>
#include <stdio.h>

int mersenne[] = { 2, 3, 5, 7, 13, 17, 19, 31, 61, 89 };  

bool IsMersennePrime(int p)
{
    for (int i = 0; i < 10; i++)
    {
        if (mersenne[i] == p)
        {
            return true;
        }
    }
    return false;
}

int main(int argc, char* argv[])
{
    int N;
    std::cin >> N;
    for (int i = 0; i < N; i++)
    {
        int p;
        std::cin >> p;
        getchar();
        if (IsMersennePrime(p))
        {
            puts("Yes");
        }
        else
        {
            puts("No");
        }
    }
    return 0;
}