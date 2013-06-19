#include <iostream>
#include <stdio.h>

inline int minimum(int a, int b)
{
    return (a < b) ? a : b;
}

// -----------------------------------------------------------------------------

bool visited[5001] = {};
int prime[669] = {};

inline void InitPrimeTable()
{
    int curr_pos = 0;
    for (int i = 2; i < 5001; i++)
    {
        if (!visited[i])
        {
            prime[curr_pos] = i;
            curr_pos++;
            for (int j = i + i; j < 5001; j += i)
            {
                visited[j] = true;
            }
        }
    }
}

// -----------------------------------------------------------------------------

int factorized[669] = {};
int unfactorized = 0;

void Factorize(int n)
{
    unfactorized = n;
    for (int i = 0; i < 669; i++)
    {
        factorized[i] = 0;
        if (unfactorized % prime[i] == 0)
        {
            do 
            {
                factorized[i]++;
                unfactorized /= prime[i];
            }
            while (unfactorized % prime[i] == 0);
        }
    }
}

int GetFactorialFactorPower(int factorial, int factor)
{
    int power = 0;
    int d = factorial;
    while (d)
    {
        d /= factor;
        power += d;
    }
    return power;
}

// -----------------------------------------------------------------------------

int main(int argc, char* argv[])
{
    InitPrimeTable();
    
    int num_testcases;
    std::cin >> num_testcases;

    int m, n;
    for (int case_id = 1; case_id <= num_testcases; case_id++)
    {
        std::cin >> m >> n;

        printf("Case %d:\n", case_id);

        Factorize(m);
        if (unfactorized > 1)
        {
            // The result is either an integer if m divides n! or a line 
            // "Impossible to divide" (without the quotes).
            //
            // Do not output "0"
            puts("Impossible to divide");
            continue;
        }

        int largest_power_so_far = 2 << 20;
        for (int i = 0; i < 669; i++)
        {
            if (factorized[i] == 0)
            {
                continue;
            }
            int power = GetFactorialFactorPower(n, prime[i]) / factorized[i];
            largest_power_so_far = minimum(largest_power_so_far, power);
            
            // prune
            if (largest_power_so_far == 0)
            {
                break;
            }
        }
        if (largest_power_so_far)
        {
            printf("%d\n", largest_power_so_far);
        }
        else
        {
            // Do not output "0"
            puts("Impossible to divide");
        }
    }
    return 0;
}