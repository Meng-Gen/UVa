#include <iostream>
#include <string>
#include <stdio.h>

int M = 0;
int N = 0;
int land[101][101] = {};

int maximum(int a, int b)
{
    return (a > b) ? a : b;
}

int GetMaximumSubarray(int lower_bound, int upper_bound)
{
    int width = upper_bound - lower_bound + 1;
    int max_ending_here = 0;
    int max_so_far = 0;

    for (int i = 0; i < M; i++)
    {
        int farm_count = 0;
        for (int j = lower_bound; j <= upper_bound; j++)
        {
            if (land[i][j] == 0)
            {
                farm_count++;
            }
        }
        if (farm_count == width)
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
    while (std::cin >> M >> N && (M != 0 || N != 0))
    {
        for (int i = 0; i < M; i++)
        {
            for (int j = 0; j < N; j++)
            {
                std::cin >> land[i][j];
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