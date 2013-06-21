#include <iostream>
#include <stdio.h>

int N;
bool H[12][12] = {};
bool V[12][12] = {};

inline void InitBoard()
{
    for (int i = 0; i < 12; i++)
    {
        for (int j = 0; j < 12; j++)
        {
            H[i][j] = false;
            V[i][j] = false;
        }
    }

    int num_lines;
    std::cin >> num_lines;
    for (int line_id = 0; line_id < num_lines; line_id++)
    {
        char direction;
        int i, j;
        std::cin >> direction >> i >> j;
        if (direction == 'H')
        {
            H[i][j] = true;
        }
        else if (direction == 'V')
        {
            V[j][i] = true;
        }
    }
}

inline bool IsVaildSquare(int i, int j, int size)
{
    int num_valid_sides = 0;

    // Check two horizontal sides.
    for (int k = 0; k < size; k++)
    {
        if (j+k >= N)
        {
            continue;
        }
        if (H[i][j+k])
        {
            num_valid_sides++;
        }
        if (i + size <= N && H[i + size][j+k])
        {
            num_valid_sides++;
        }
    }

    // Check two vertical sides.
    for (int k = 0; k < size; k++)
    {
        if (i+k >= N)
        {
            continue;
        }
        if (V[i+k][j])
        {
            num_valid_sides++;
        }
        if (j + size <= N && V[i+k][j + size])
        {
            num_valid_sides++;
        }
    }

    return num_valid_sides == 4 * size;
}

int main(int argc, char* argv[])
{
    int problem_id = 1;
    while (std::cin >> N)
    {
        if (problem_id > 1)
        {
            putchar('\n');
            puts("**********************************");
            putchar('\n');
        }
        printf("Problem #%d\n\n", problem_id);
        problem_id++;

        InitBoard();

        bool found = false;
        for (int square_size = 1; square_size <= N; square_size++)
        {
            int count = 0;
            for (int i = 1; i <= N; i++)
            {
                for (int j = 1; j < N; j++)
                {
                    if (IsVaildSquare(i, j, square_size))
                    {
                        count++;
                    }
                }
            }
            if (count)
            {
                found = true;
                printf("%d square (s) of size %d\n", count, square_size);
            }
        }
        if (!found)
        {
            puts("No completed squares can be found.");
        }
    }

    return 0;
}