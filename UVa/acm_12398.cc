#include <iostream>
#include <string>
#include <stdio.h>

int transition[9][3][3] = {};
char command[201];

void init_transition()
{
    for (int i = 0; i < 9; i++)
    {
        int x = i / 3;
        int y = i % 3;
        transition[i][x][y] = 1;
        for (int dx = -1; dx <= 1; dx += 2)
        {
            int x_effect = x + dx;
            if (x_effect >= 0 && x_effect < 3)
            {
                transition[i][x_effect][y] = 1;
            }
        }
        for (int dy = -1; dy <= 1; dy += 2)
        {
            int y_effect = y + dy;
            if (y_effect >= 0 && y_effect < 3)
            {
                transition[i][x][y_effect] = 1;
            }
        }
    }
}

int main(int argc, char* argv[])
{
    init_transition();

    int case_id = 1;
    while (std::cin.getline(command, 201))
    {
        int puzzle[3][3] = {};
        for (int i = 0; command[i] != 0; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                for (int k = 0; k < 3; k++)
                {
                    puzzle[j][k] += transition[command[i]-'a'][j][k];
                }
            }
        }

        printf("Case #%d:\n", case_id);
        for (int j = 0; j < 3; j++)
        {
            for (int k = 0; k < 3; k++)
            {
                printf("%d", puzzle[j][k]);
                if (k == 2)
                {
                    printf("\n");
                }
                else
                {
                    printf(" ");
                }
            }
        }

        case_id++;
    }

    return 0;
}
