#include <iostream>
#include <stdio.h>

int N, B, H, W;
int p, a;

inline int minimum(int a, int b) {
    return (a < b) ? a : b;
}

int main(int argc, char* argv[]) 
{
    while (std::cin >> N >> B >> H >> W)
    {
        int min_cost = 1000000;
        for (int hotel_id = 0; hotel_id < H; hotel_id++)
        {
            std::cin >> p;
            for (int week_id = 0; week_id < W; week_id++)
            {
                std::cin >> a;
                if (a >= N && N * p <= B)
                {
                    min_cost = minimum(min_cost, N * p);
                }
            }
        }

        if (min_cost != 1000000)
        {
            printf("%d\n", min_cost);
        }
        else
        {
            puts("stay home");
        }
    }    
    return 0;
}
