#include <iostream>
#include <stdio.h>

int M, N;

void PrintTriangularMuseum()
{
    int height = M * N;
    int triangle_level;
    int triangle_height;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < height-1-i; j++)
        {
            putchar(' ');
        }
        triangle_level = i / M;
        triangle_height = i % M;

        for (int j = 0; j <= triangle_level; j++)
        {
            if (j)
            {
                for (int k = 0; k < (M-1-triangle_height) * 2; k++)
                {
                    putchar(' ');
                }
            }
            putchar('/');
            for (int k = 0; k < triangle_height * 2; k++)
            {
                putchar((triangle_height == M-1) ? '_' : ' ');
            }
            putchar('\\');
        }
        putchar('\n');
    }
}

int main(int argc, char* argv[])
{
    int case_id = 1;
    while (std::cin >> M >> N && (M || N))
    {
        printf("Triangular Museum %d\n", case_id);
        PrintTriangularMuseum();
        putchar('\n');
        case_id++;
    }
    return 0;
}