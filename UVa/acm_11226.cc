#include <iostream>
#include <stdio.h>

int sopf[500002] = {};
int lsopf[500002] = {};

inline void InitSumOfPrimeFactors()
{
    int d;
    for (int i = 2; i < 500002; i++)
    {
        if (sopf[i] == 0)
        {
            for (int j = i; j < 500002; j += i)
            {
                d = j;
                while (d % i == 0)
                {
                    sopf[j] += i;
                    d /= i;
                }
            }
        }
    }
}

inline void InitLengthOfReachingFixPoint()
{
    int next;
    for (int i = 2; i < 500002; i++)
    {
        lsopf[i]++;
        next = i;
        while (sopf[next] != next)
        {
            lsopf[i]++;
            next = sopf[next];
        }
    }
}

int lower_limit, upper_limit;
int max_so_far;

int main(int argc, char* argv[])
{
    InitSumOfPrimeFactors();
    InitLengthOfReachingFixPoint();

    int num_testcases;
    std::cin >> num_testcases;
    for (int case_id = 1; case_id <= num_testcases; case_id++)
    {
        std::cin >> lower_limit >> upper_limit;
        if (lower_limit > upper_limit)
        {
            int temp = lower_limit;
            lower_limit = upper_limit;
            upper_limit = temp;
        }

        max_so_far = 1;
        for (int i = lower_limit; i <= upper_limit; i++)
        {
            if (lsopf[i] > max_so_far)
            {
                max_so_far = lsopf[i];
            }
        }

        printf("Case #%d:\n", case_id);
        printf("%d\n", max_so_far);
    }
    return 0;
}