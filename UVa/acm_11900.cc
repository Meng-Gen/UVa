#include <iostream>
#include <string>
#include <stdio.h>

int weights[31];

int main(int argc, char* argv[])
{
    int T;
    std::cin >> T;
    for (int t = 1; t <= T; t++)
    {
        int n; // Now they have n eggs and a bowl.
        int P; // It's risky to put more than P eggs in the bowl
        int Q; // The bowl can carry at most Q gm of eggs. 
        std::cin >> n >> P >> Q;

        // The next line contains n positive integers (not greater than 10) 
        // ``in non-descending order.''
        // So, we don't need to sort anymore.
        for (int i = 0; i < n; i++)
        {
            std::cin >> weights[i];
        }

        int curr_weight_sum = 0;
        int max_egg_count = 0;
        for (int i = 0; i < n; i++)
        {
            if (weights[i] + curr_weight_sum > Q)
            {
                break;
            }
            curr_weight_sum += weights[i];
            max_egg_count++;
        }

        if (max_egg_count > P)
        {
            max_egg_count = P;
        }

        printf("Case %d: %d\n", t, max_egg_count);
    }

    return 0;
}