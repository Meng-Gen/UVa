#include <stdio.h>

bool not_self_numbers[1000001] = {};

inline int digitadition(int n)
{
    int rv = n;
    while (n > 0)
    {
        rv += (n % 10);
        n /= 10;
    }
    return rv;
}

void PopulateSelfNumbers()
{
    for (int i = 1; i < 1000001; i++)
    {
        not_self_numbers[digitadition(i)] = true;
    }
}

void PrintSelfNumbers()
{
    for (int i = 1; i < 1000001; i++)
    {
        if (!not_self_numbers[i])
        {
            printf("%d\n", i);
        }
    }
}

int main(int argc, char* argv[])
{
    PopulateSelfNumbers();
    PrintSelfNumbers();
    return 0;
}