#include <iostream>
#include <stdio.h>

inline int Norm(int a)
{
    return (a < 0) ? -a : a;
}

int N, row1, col1, row2, col2;
int width;

char GetAscii(int row, int col)
{
    // The distance (L1 norm, taxicab norm) to the center will 
    // determine the ASCII code.
    int d = Norm(N - 1 - row % width) + Norm(N - 1 - col % width); 
    if (d < N)
    {
        return d % 26 + 'a';
    }
    else 
    {
        return '.';
    }
}

int main(int argc, char* argv[])
{
    int case_id = 1;
    while (std::cin >> N >> row1 >> col1 >> row2 >> col2 && N)
    {
        width = 2 * N - 1;

        printf("Case %d:\n", case_id);
        case_id++;

        for (int row = row1; row <= row2; row++)
        {
            for (int col = col1; col <= col2; col++)
            {
                putchar(GetAscii(row, col));
            }
            putchar('\n');
        }
    }
    return 0;
}