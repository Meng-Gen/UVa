#include <iostream>
#include <stdio.h>

int query[5001][2000] = {};

int main(int argc, char* argv[])
{
    query[0][0] = 0;
    query[1][0] = 1;
    for (int i = 2; i < 5001; i++)
    {
        for (int j = 0; j < 2000; j++)
        {
            query[i][j] = query[i-1][j] + query[i-2][j];
        }

        // Normalize.
        for (int j = 0; j < 2000; j++)
        {
            query[i][j+1] += query[i][j]/10;
            query[i][j] %= 10;
        }
    }

    int n;
    while(std::cin >> n) 
    {
        if (n == 0)
        {
            printf("The Fibonacci number for 0 is 0\n");
        }
        else
        {
            int j = 0;
            for (j = 1999; j >= 0; j--)
            {
                if (query[n][j] != 0)
                {
                    break;
                }
            }
            printf("The Fibonacci number for %d is ", n);
            for (; j >= 0; j--)
            {
                printf("%d", query[n][j]);
            }
            printf("\n");
        }
    }
}