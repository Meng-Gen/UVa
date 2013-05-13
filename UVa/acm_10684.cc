// Dynamic Programming :: Max 1D Range Sum 

#include <iostream>
#include <stdio.h>

int N;
int bets[10001];

inline long long get_max(long long a, long long b)
{
    if (a > b)
    {
        return a;
    }
    return b;
}

// Kadane's algorithm
long long get_maximum_subarray()
{
    long long max_ending_here = 0LL;
    long long max_so_far = 0LL;
    for (int i = 0; i < N; i++) 
    {
        max_ending_here = get_max(0, max_ending_here + bets[i]);
        max_so_far = get_max(max_so_far, max_ending_here);
    }
    return max_so_far;
}

int main(int argc, char* argv[]) 
{
    while (1) 
    {  
        std::cin >> N;
        if (N == 0) 
        { 
            break;
        }
        for (int n = 0; n < N; n++)
        {
            std::cin >> bets[n];
        }

        long long winning_streak = get_maximum_subarray();
        if (winning_streak > 0)
        {
            printf("The maximum winning streak is %lld.\n", winning_streak);
        }
        else
        {
            printf("Losing streak.\n");
        }
    }

    return 0;
}