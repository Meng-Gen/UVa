#include <iostream>
#include <string>
#include <stdio.h>

int N = 0;
int chessboard[101][101] = {};

int maximum(int a, int b)
{
    return (a > b) ? a : b;
}

int GetMaximumSubarray(int lower_bound, int upper_bound)
{
    int width = upper_bound - lower_bound + 1;
    int max_ending_here = 0;
    int max_so_far = 0;

    for (int i = 0; i < N; i++)
    {
        int free_space_count = 0;
        for (int j = lower_bound; j <= upper_bound; j++)
        {
            if (chessboard[i][j] == 0)
            {
                free_space_count++;
            }
        }
        if (free_space_count == width)
        {
            max_ending_here++;
            max_so_far = maximum(max_so_far, max_ending_here);
        }
        else
        {
            max_ending_here = 0;
        }
    }

    return max_so_far * width;
}

int main(int argc, char* argv[]) 
{
    int num_testcases;
    std::cin >> num_testcases;
    while (num_testcases--)
    {
        std::cin >> N; // board size
        
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                chessboard[i][j] = 0;
            }
        }

        int num_blocks;
        std::cin >> num_blocks;
        for (int block_id = 0; block_id < num_blocks; block_id++)
        {
            int r1, c1, r2, c2;
            std::cin >> r1 >> c1 >> r2 >> c2;
            for (int i = c1; i <= c2; i++)
            {
                for (int j = r1; j <= r2; j++)
                {
                    // 1-based to 0-based
                    chessboard[i-1][j-1] = 1;
                }
            }
        }
        
        int max_so_far = 0; 
        for (int min_j = 0; min_j < N; min_j++)
        {
            for (int max_j = min_j; max_j < N; max_j++)
            {
                int max = GetMaximumSubarray(min_j, max_j);
                max_so_far = maximum(max_so_far, max);
            }
        }

        std::cout << max_so_far << std::endl;
    }
    return 0;
}