#include <iostream>
#include <stdio.h>

int known_bricks[5][5] = {};
int x[4][4] = {};
int brick_wall[9][9] = {};

inline void ReadKnownBricks()
{
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            std::cin >> known_bricks[i][j];
        }
    }
}

//       k1+k2+2x     = k3 
//   k1+x        k2+x       <=> x = (k3 - k1 - k2)/2
// k1        x       k2
inline void CalcuateBrickBetweenTwoKnownBricks()
{
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            x[i][j] = (known_bricks[i][j] 
                - known_bricks[i+1][j] - known_bricks[i+1][j+1])/2;
        }
    }
}

inline void BuildRowContainingKnownBricks()
{
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j <= i*2; j += 2)
        {
            brick_wall[i*2][j] = known_bricks[i][j/2];
        }
        for (int j = 1; j <= i*2; j += 2)
        {            
            brick_wall[i*2][j] = x[i-1][j/2];
        }
    }
}

inline void BuildRest()
{
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j <= i*2+1; j++)
        {
            brick_wall[i*2+1][j] = 
                brick_wall[i*2+2][j] + brick_wall[i*2+2][j+1]; 
        }
    }
}

inline void PrintBrickWall()
{
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            printf("%d", brick_wall[i][j]);
            putchar((j == i) ? '\n' : ' ');
        }
    }
}

int main(int argc, char* argv[])
{
    int num_testcases;
    std::cin >> num_testcases;
    while (num_testcases--)
    {
        ReadKnownBricks();
        CalcuateBrickBetweenTwoKnownBricks();
        BuildRowContainingKnownBricks();
        BuildRest();
        PrintBrickWall();
    }
    return 0;
}