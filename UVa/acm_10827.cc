#include <iostream>
#include <string>
#include <stdio.h>

int N = 0;
int grid[76][76] = {};
int subarray[76] = {};

int maximum(int a, int b)
{
    return (a > b) ? a : b;
}

int minimum(int a, int b)
{
    return (a < b) ? a : b;
}

// Reference: http://www.geeksforgeeks.org/maximum-contiguous-circular-sum/
// Quote:
// (1) The elements that contribute to the maximum sum are arranged 
//     such that no wrapping is there. 
// (2) The elements which contribute to the maximum sum are arranged 
//     such that wrapping is there.  In this case, we change wrapping to 
//     non-wrapping.  Wrapping of contributing elements implies non wrapping 
//     of non contributing elements, so find out the sum of non contributing 
//     elements and subtract this sum from the total sum. 
int MaxCircularSubarray(int min_j, int max_j)
{
    int sum = 0;
    for (int i = 0; i < N; i++)
    {
        subarray[i] = 0;
        for (int j = min_j; j <= max_j; j++)
        {
            subarray[i] += grid[i][j % N];
        }
        sum += subarray[i];
    }

    int max_ending_here = 0;
    int max_so_far = 0;
    int min_ending_here = 0;
    int min_so_far = 0;
    for (int i = 0; i < N; i++)
    {
        max_ending_here = maximum(0, max_ending_here + subarray[i]);
        max_so_far = maximum(max_so_far, max_ending_here);
        min_ending_here = maximum(0, min_ending_here - subarray[i]);
        min_so_far = maximum(min_so_far, min_ending_here);
    }
    return maximum(max_so_far, sum + min_so_far);
}

int main(int argc, char* argv[]) 
{
    int num_testcases;
    std::cin >> num_testcases;
    while (num_testcases--)
    {
        std::cin >> N;
        
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                std::cin >> grid[i][j];
            }
        }
        
        int max_so_far = 0; 
        for (int min_j = 0; min_j < N; min_j++)
        {
            for (int max_j = min_j; max_j < min_j + N; max_j++)
            {
                int max = MaxCircularSubarray(min_j, max_j);
                max_so_far = maximum(max_so_far, max);
            }
        }

        std::cout << max_so_far << std::endl;
    }
    return 0;
}