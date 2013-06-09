#include <iostream>
#include <stdio.h>

bool board[502][502] = {};

inline int minimum(int a, int b)
{
    return (a < b) ? a : b;
}

inline int maximum(int a, int b)
{
    return (a > b) ? a : b;
}

int main(int argc, char* argv[]) 
{
    int W, H, N;
    int X1, Y1, X2, Y2;
    int lower_x, upper_x, lower_y, upper_y;

    while (std::cin >> W >> H >> N && (W != 0 || H != 0 || N != 0))
    {
        for (int i = 0; i < W; i++)
        {
            for (int j = 0; j < H; j++)
            {
                board[i][j] = false;
            }
        }

        for (int subboard_id = 0; subboard_id < N; subboard_id++)
        {
            std::cin >> X1 >> Y1 >> X2 >> Y2;
            lower_x = minimum(X1, X2);
            upper_x = maximum(X1, X2);
            lower_y = minimum(Y1, Y2);
            upper_y = maximum(Y1, Y2);

            for (int i = lower_x; i <= upper_x; i++)
            {
                for (int j = lower_y; j <= upper_y; j++)
                {
                    // 1-based to 0-based
                    board[i-1][j-1] = true;
                }
            }
        }

        int free_spot_count = 0;
        for (int i = 0; i < W; i++)
        {
            for (int j = 0; j < H; j++)
            {
                if (!board[i][j])
                {
                    free_spot_count++;
                }
            }
        }

        if (free_spot_count == 0)
        {
            puts("There is no empty spots.");
        }
        else if (free_spot_count == 1)
        {
            puts("There is one empty spot.");
        }
        else
        {
            printf("There are %d empty spots.\n", free_spot_count);
        }
    }
    return 0;
}