#include <iostream>
#include <stdio.h>

bool visited[1001] = {};
int prime[169] = {};

inline void InitPrimeTable()
{
    prime[0] = 1;
    int curr_pos = 1;
    for (int i = 2; i < 1001; i++)
    {
        if (!visited[i])
        {
            prime[curr_pos] = i;
            curr_pos++;
            for (int j = i + i; j < 1001; j += i)
            {
                visited[j] = true;
            }
        }
    }
}

int main(int argc, char* argv[])
{
    InitPrimeTable();

    int N, C;
    while (std::cin >> N >> C)
    {
        int len = 0;
        for (; (prime[len] <= N) && (len < 169); len++);

        // Set range
        int lower_bound;
        int upper_bound;
        if (len % 2 == 0)
        {
            lower_bound = len/2 - C;
            upper_bound = len/2 + C - 1;
        }
        else 
        {
            lower_bound = len/2 - C + 1;
            upper_bound = len/2 + C - 1;        
        }

        // Avoid out of bound
        if (lower_bound < 0)
        {
            lower_bound = 0;
        }
        if (upper_bound > len-1)
        {
            upper_bound = len-1;
        }

        printf("%d %d:", N, C);
        for (int i = lower_bound; i <= upper_bound; i++)
        {
            printf(" %d", prime[i]);
        }
        printf("\n\n");
    }
    return 0;
}