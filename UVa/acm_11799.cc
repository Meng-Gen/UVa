#include <iostream>
#include <stdio.h>

int creature_speeds[101] = {};

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
            std::cin >> creature_speeds[n];
        }
        
        int required_speed  = 0; // If N = 0, then we return 0.

        for (int i = 0; i < N; i++)
        {
            if (creature_speeds[i] > required_speed)
            {
                required_speed = creature_speeds[i];
            }
        }

        printf("Case %d: %d\n", t, required_speed);
    }
   
    return 0;
}