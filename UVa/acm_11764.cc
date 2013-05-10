#include <iostream>
#include <stdio.h>

int heights[51] = {};

int main(int argc, char* argv[])
{
    int T;
    std::cin >> T;

    for (int t = 1; t <= T; t++)
    {
        int N;
        std::cin >> N;
        for (int n = 0; n < N; n++)
        {
            std::cin >> heights[n];
        }

        int total_high_jumps = 0;
        int total_low_jumps = 0;

        for (int i = 1; i < N; i++)
        {
            if (heights[i] > heights[i-1])
            {
                total_high_jumps++;
            }
            else if (heights[i] < heights[i-1])
            {
                total_low_jumps++;
            }
        }

        printf("Case %d: %d %d\n", t, total_high_jumps, total_low_jumps);
    }
   
    return 0;
}