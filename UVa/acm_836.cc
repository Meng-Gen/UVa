#include <iostream>
#include <string>
#include <stdio.h>

int maximum(int a, int b)
{
    return (a > b) ? a : b;
}

// Kadane's algorithm
int GetMaximumSubarray(int* query_array, int array_size)
{
    int max_ending_here = 0LL;
    int max_so_far = 0LL;
    for (int i = 0; i < array_size; i++) 
    {
        max_ending_here = maximum(0, max_ending_here + query_array[i]);
        max_so_far = maximum(max_so_far, max_ending_here);
    }
    return max_so_far;
}

// -----------------------------------------------------------------------------

int N = 0;
char grid[26][26] = {};
int M[26][26] = {};
int column_sum[26] = {};

int main(int argc, char* argv[]) 
{
    int num_testcases;
    std::cin >> num_testcases;
    for (int case_id = 0; case_id < num_testcases; case_id++)
    {
        if (case_id)
        {
            putchar('\n');
        }

        // Read input
        getchar();
        getchar();
        std::string buffer;
        // Got WA because of using |getline(std::cin, buffer)|.
        // Test case: 
        // 4
        // 
        // 0 
        // 
        // 1
        // 
        // 0
        //
        // 1
        std::cin >> buffer; 
        N = buffer.size();
        for (int j = 0; j < N; j++)
        {
            grid[0][j] = buffer[j];
        }
        for (int i = 1; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                std::cin >> grid[i][j];
            }
        }
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                M[i][j] = grid[i][j] - '0';
                if (M[i][j] == 0)
                {
                    // Dirty hack
                    M[i][j] = -999;
                }
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

        int max_so_far = M[0][0];

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
                int max = GetMaximumSubarray(column_sum, N);
                max_so_far = maximum(max_so_far, max);
            }
        }

        std::cout << max_so_far << std::endl;
    }
    return 0;
}