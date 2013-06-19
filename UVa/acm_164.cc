#include <iostream>
#include <stdio.h>
#include <string.h>

inline int minimum(int a, int b) 
{
    return (a < b) ? a : b;
}

int d[22][22] = {};
char s[22], t[22] = {};
int m, n;

inline void BuildLevenshteinDistanceMatrix() 
{
    for (int i = 0; i < 22; i++)
    {
        for (int j = 0; j < 22; j++)
        {
            d[i][j] = 0;
        }
    }

    m = strlen(s);
    n = strlen(t);

    for (int i = 1; i <= m; i++)
    {
        d[i][0] = i;
    }
    for (int j = 1; j <= n; j++)
    {
        d[0][j] = j;
    }
 
    for (int j = 1; j <= n; j++)
    {
        for (int i = 1; i <= m; i++)
        {
            // 1-based to 0-based string
            if (s[i-1] == t[j-1])
            {
                d[i][j] = d[i-1][j-1];
            }
            else
            {
                d[i][j] = minimum(d[i-1][j] + 1, d[i][j-1] + 1);
                d[i][j] = minimum(d[i][j], d[i-1][j-1] + 1);
            }
        }
    }
}

char cmd[30][5] = {};

inline void BuildCommands()
{
    int edit_distance = d[m][n];

    int x = m;
    int y = n;
    int C, D, I;
    int pos_cmd = d[m][n] - 1;
    while (edit_distance)
    {
        C = edit_distance;
        if (x-1 >= 0 && y-1 >= 0)
        {
            C = d[x-1][y-1];
        }
        D = edit_distance;
        if (x-1 >= 0)
        {
            D = d[x-1][y];
        }
        I = edit_distance;
        if (y-1 >= 0)
        {
            I = d[x][y-1];
        }

        if (C < I && C < D)
        {
            if (edit_distance != C)
            {
                // change string position to 1-based
                sprintf(cmd[pos_cmd], "C%c%02d", t[y-1], y);
                pos_cmd--;
                edit_distance = C;
            }
            x = x-1;
            y = y-1;
        }
        else if (I < C && I < D)
        {
            if (edit_distance != I)
            {
                // change string position to 1-based
                sprintf(cmd[pos_cmd], "I%c%02d", t[y-1], y);
                pos_cmd--;
                edit_distance = I;
            }
            y = y-1;  
        }
        else if (D < C && D < I)
        {
            if (edit_distance != D)
            {
                // change string position to 1-based
                sprintf(cmd[pos_cmd], "D%c%02d", s[x-1], x);
                pos_cmd--;
                edit_distance = D;
            }
            x = x-1;
        }
        else if (I <= C && I <= D)
        {
            if (edit_distance != I)
            {
                // change string position to 1-based
                sprintf(cmd[pos_cmd], "I%c%02d", t[y-1], y);
                pos_cmd--;
                edit_distance = I;
            }
            y = y-1;
        }
        else if (D <= C && D <= I)
        {
            if (edit_distance != D)
            {
                // change string position to 1-based
                sprintf(cmd[pos_cmd], "D%c%02d", s[x-1], x);
                pos_cmd--;
                edit_distance = D;
            }
            x = x-1;        
        }

    }
    for (int i = 0; i < d[m][n]; i++)
    {
        printf("%s", cmd[i]);
    }

    printf("E\n");
}

int main(int argc, char* argv[])
{
    while (std::cin >> s && strcmp(s, "#"))
    {
        std::cin >> t;
        BuildLevenshteinDistanceMatrix();
        BuildCommands();
    }
    return 0;
}