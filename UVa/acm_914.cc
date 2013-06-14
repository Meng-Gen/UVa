#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
#include <stdio.h>

bool prime[1000001] = {};

inline void InitPrimeTable()
{
    for (long long i = 2; i < 1000001; i++)
    {
        prime[i] = true;
    }
    for (long long i = 2; i < 1000001; i++)
    {
        if (prime[i])
        {
            for (long long j = i + i; j < 1000001; j += i)
            {
                prime[j] = false;
            }
        }
    }
}

// -----------------------------------------------------------------------------

typedef std::pair<long long, int> JumpingCount;

bool Compare(const JumpingCount& a, const JumpingCount& b)
{
    return a.second > b.second;
}

int main(int argc, char* argv[])
{
    InitPrimeTable();

    int num_testcases;
    std::cin >> num_testcases;
    for (int case_id = 0; case_id < num_testcases; case_id++)
    {
        long long L, U;
        std::cin >> L >> U;

        std::map<long long, int> jumping;
        long long prev_prime;
        bool is_first_prime = true;
        for (long long i = L; i <= U; i++)
        {
            if (!prime[i])
            {
                continue;
            }

            if (is_first_prime)
            {
                prev_prime = i;
                is_first_prime = false;
            }
            else
            {
                jumping[i - prev_prime]++;
                prev_prime = i;
            }
        }
        std::vector< JumpingCount > frequency;
        for (std::map<long long, int>::iterator it = jumping.begin();
            it != jumping.end(); it++)
        {
            frequency.push_back(std::make_pair(it->first, it->second));
        }
        std::sort(frequency.begin(), frequency.end(), Compare);

        int length = frequency.size();
        if (length == 0)
        {
            puts("No jumping champion");
            continue;
        }
        
        int max_jumping = frequency[0].first;
        int max_jumping_frequency = frequency[0].second;
        if (length > 1 && frequency[1].second == max_jumping_frequency)
        {
            puts("No jumping champion");
        }
        else
        {
            printf("The jumping champion is %d\n", max_jumping);
        }
    }
    return 0;
}