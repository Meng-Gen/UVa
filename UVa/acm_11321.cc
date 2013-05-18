#include <algorithm>
#include <iostream>
#include <stdio.h>

struct ModuleNumber
{
    int number;
    int mod;
    bool is_even;
};

ModuleNumber sequence[10001];

bool compare(const ModuleNumber& a, const ModuleNumber& b) 
{
    if (a.mod != b.mod)
    {
        return a.mod < b.mod;
    }
    else if (!a.is_even && b.is_even)
    {
        return true;
    }
    else if (a.is_even && !b.is_even)
    {
        return false;
    }
    else if (!a.is_even)
    {
        return a.number > b.number;
    }
    else if (a.is_even)
    {
        return a.number < b.number;
    }
    
    return false;
}

int main(int argc, char* argv[])
{
    int N = 0;
    int M = 0;
    while (std::cin >> N >> M)
    {
        printf("%d %d\n", N, M);
        if (N == 0 && M == 0)
        {
            break;
        }

        for (int n = 0; n < N; n++)
        {
            std::cin >> sequence[n].number;
            sequence[n].mod = sequence[n].number % M;
            sequence[n].is_even = !(sequence[n].number % 2);
        }

        std::sort(sequence, sequence + N, compare);

        for (int n = 0; n < N; n++)
        {
            printf("%d\n", sequence[n]);
        }
    }
    
    return 0;
}