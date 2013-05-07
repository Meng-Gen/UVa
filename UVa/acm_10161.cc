#include <iostream>
#include <stdio.h>
#include <math.h>

int main(int argc, char* argv[])
{
    long long N;
    while (std::cin >> N)
    {
        if (N == 0)
        {
            break;
        }

        long long level = sqrt((double)N);
        if (level * level != N)
        {
            level++;
        }

        long long diagonal_num = level * (level - 1) + 1;
        long long x;
        long long y;
        if (level % 2 == 0)
        {
            if (N < diagonal_num)
            {
                x = level - diagonal_num + N;
                y = level;
            }
            else
            {
                x = level;
                y = level + diagonal_num - N;
            }
        }
        else
        {
            if (N < diagonal_num)
            {
                x = level;
                y = level - diagonal_num + N;
            }
            else
            {
                x = level + diagonal_num - N;
                y = level;
            }
        }

        std::cout << x << " " << y << std::endl;
    }
    return 0;
}