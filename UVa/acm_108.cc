// Dynamic Programming :: Max 2D Range Sum 

#include <iostream>
#include <stdio.h>

int N;
long long M[101][101];
long long column_sum[101];

inline long long get_max(long long a, long long b)
{
    if (a > b)
    {
        return a;
    }
    return b;
}

// Kadane's algorithm
long long get_maximum_subarray(long long* query_array, int array_size)
{
    long long max_ending_here = 0LL;
    long long max_so_far = 0LL;
    for (int i = 0; i < array_size; i++) 
    {
        max_ending_here = get_max(0, max_ending_here + query_array[i]);
        max_so_far = get_max(max_so_far, max_ending_here);
    }
    return max_so_far;
}

int main(int argc, char* argv[]) 
{
    std::cin >> N;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            std::cin >> M[i][j];
        }
    }

    // Compute partial sums
    for (int i = 0; i < N; i++)
    {
        for (int j = 1; j < N; j++)
        {
            M[i][j] += M[i][j-1];
        }
    }

    long long max_so_far = M[0][0];

    // T(N) = O(N^3)
    for (int min_j = 0; min_j < N; min_j++)
    {
        for (int max_j = min_j; max_j < N; max_j++)
        {
            // Init |column_sum|
            for (int i = 0; i < N; i++)
            {
                if (min_j == max_j)
                {
                    column_sum[i] = M[i][max_j];
                }
                else
                {
                    column_sum[i] = M[i][max_j] - M[i][min_j];
                }
            }

            long long max = get_maximum_subarray(column_sum, N);
            max_so_far = get_max(max_so_far, max);
        }
    }
    std::cout << max_so_far << std::endl;

    return 0;
}