#include <iostream>
#include <stdio.h>

char field[101][101];

int main(int argc, char* argv[])
{
    int num_field = 1;

    int n;
    int m;
    while (1)
    {
        std::cin >> n >> m;
        if (n == 0 && m == 0)
        {
            break;
        }

        for (int i = 0; i < n; i++)
        {
            std::cin >> field[i];
        }

        // Initialize.
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (field[i][j] == '.')
                {
                    field[i][j] = '0';
                }
            }
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (field[i][j] == '*')
                {
                    // Mark the number of adjacent mines to that square.
                    for (int dx = -1; dx <= 1; dx++)
                    {
                        for (int dy = -1; dy <= 1; dy++)
                        {
                            int new_x = i + dx;
                            int new_y = j + dy;
                            if (new_x < 0 || new_x >= n || 
                                new_y < 0 || new_y >= m)
                            {
                                continue;
                            }
                            if (field[new_x][new_y] == '*')
                            {
                                continue;
                            }
                            field[new_x][new_y]++;
                        }
                    }
                }
            }
        }

        if (num_field > 1)
        {
            printf("\n");
        }
        printf("Field #%d:\n", num_field);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                printf("%c", field[i][j]);
            }
            printf("\n");
        }

        num_field++;
    }

    return 0;
}