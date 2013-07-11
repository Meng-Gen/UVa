#include <iostream>
#include <stdio.h>

int main(int argc, char* argv[])
{
    int S, T, N;
    int width;

    int case_id = 1;
    while (std::cin >> S >> T >> N && (S || T || N))
    {
        printf("Case %d:\n", case_id);

        width = S * N + T * (N + 1);
        for (int i = 0; i < T; i++)
        {
            for (int j = 0; j < width; j++)
            {
                putchar('*');
            }
            putchar('\n');
        }

        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < S; j++)
            {
                for (int k = 0; k < T; k++)
                {
                    putchar('*');
                }
                for (int k = 0; k < N; k++)
                {
                    for (int r = 0; r < S; r++)
                    {
                        putchar('.');
                    }
                    for (int r = 0; r < T; r++)
                    {
                        putchar('*');
                    }
                }
                putchar('\n');
            }
            for (int j = 0; j < T; j++)
            {
                for (int k = 0; k < width; k++)
                {
                    putchar('*');
                }
                putchar('\n');
            }
        }

        putchar('\n');
        case_id++;
    }
    return 0;
}