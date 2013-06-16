#include <iostream>
#include <string>
#include <stdio.h>

#define UPPER_BOUND (1000000000000000000)

bool visited[1001] = {};
int prime[168] = {};

inline void InitPrimeTable()
{
    int curr_pos = 0;
    for (long i = 2; i < 1001; i++)
    {
        if (!visited[i])
        {
            prime[curr_pos] = i;
            curr_pos++;
            for (long j = i + i; j < 1001; j += i)
            {
                visited[j] = true;
            }
        }
    }
}

// -----------------------------------------------------------------------------

int prime_factor_count[168] = {};

void UpdatePrimeFactorCount(int n)
{
    int d = n;
    for (int i = 0; i < 168 && prime[i] <= d; i++)
    {
        if (d % prime[i] == 0)
        {
            do 
            {
                prime_factor_count[i]++;
                d /= prime[i];
            }
            while (d % prime[i] == 0);
        }
    }
}

long long GetFactorCounts()
{
    long long rv = 1;

    for (int i = 0; i < 168; i++)
    {
        long long count = prime_factor_count[i] + 1;
        if (rv > UPPER_BOUND / count) // avoid overflow
        {
            return -1;
        }
        rv *= count;
    }

    return rv;
}

// -----------------------------------------------------------------------------

int main(int argc, char* argv[])
{
    InitPrimeTable();

    int num_testcases;
    std::cin >> num_testcases;

    int n;
    std::string marks;
    for (int case_id = 1; case_id <= num_testcases; case_id++)
	{
        for (int i = 0; i < 168; i++)
        {
            prime_factor_count[i] = 0;
        }

        std::cin >> n >> marks;
        int k = marks.size();

        int curr_factor = n;
        while (curr_factor > 0)
        {
            UpdatePrimeFactorCount(curr_factor);
            curr_factor -= k;
        }

        long long rv = GetFactorCounts();
        if (rv < 0)
        {
            printf("Case %d: Infinity\n", case_id);
        }
        else
        {
            printf("Case %d: %lld\n", case_id, rv);
        }
	}

	return 0;
}
