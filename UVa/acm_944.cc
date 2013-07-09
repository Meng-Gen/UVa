#include <iostream>
#include <stdio.h>

// For n = 1 to 99999, DigitSquareSum(n) <= DigitSquareSum(99999) = 405.

int happy_cycle[406] = {};

int DigitSquareSum(int n)
{
    int rv = 0;
    while (n > 0)
    {
        int mod = n % 10;
        rv = rv + mod * mod;
        n /= 10;
    }
    return rv;
}

bool IsHappyNumber(int n)
{
    if (n == 1)
    {
        return true;
    }
    else if (n == 4)
    {
        return false;
    }
    return IsHappyNumber(DigitSquareSum(n));
}

void InitHappyCycle()
{
    happy_cycle[1] = 1;
    happy_cycle[2] = -1;
    happy_cycle[3] = -1;
    happy_cycle[4] = -1;

    for (int i = 5; i <= 405; i++)
    {
        happy_cycle[i] = 1;
        int next = i;
        while (next != 1)
        {
            next = DigitSquareSum(next);
            if (happy_cycle[next] == -1)
            {
                happy_cycle[i] = -1;
                break;
            }
            else if (happy_cycle[next] > 0)
            {
                happy_cycle[i] += happy_cycle[next];
                break;
            }
            else
            {
                happy_cycle[i]++;
            }
        }
    }
}

int GetHappyCycle(int n)
{
    if (n <= 405)
    {
        return happy_cycle[n];
    }

    int next = DigitSquareSum(n);
    return (happy_cycle[next] < 0) ? -1 : happy_cycle[next] + 1;
}

int main(int argc, char* argv[])
{
    InitHappyCycle();

    int case_id = 0;
    int L, H;
    while (std::cin >> L >> H)
    {
        if (case_id)
        {
            putchar('\n');
        }

        for (int i = L; i <= H; i++)
        {
            int rv = GetHappyCycle(i);
            if (rv > 0)
            {
                printf("%d %d\n", i, rv);
            }
        }

        case_id++;
    }
    return 0;
}
