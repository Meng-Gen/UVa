#include <iostream>
#include <stdio.h>

// BigInteger simulation.  Lazy Implementation.
int query[4900][1005] = {};

int main(int argc, char* argv[])
{
    query[0][0] = 0;
    query[1][0] = 1;

    for (int i = 2; i < 4900; i++)
    {
        for (int j = 0; j < 1005; j++)
        {
            query[i][j] = query[i-1][j] + query[i-2][j];
        }

        // Normalize.
        for (int j = 0; j < 1005; j++)
        {
            query[i][j+1] += query[i][j]/10;
            query[i][j] %= 10;
        }
    }

    int n;
    while(std::cin >> n) 
    {
        int j = 0;
        for (j = 1004; j >= 0; j--)
        {
            if (query[n][j] != 0)
            {
                break;
            }
        }
        for (; j >= 0; j--)
        {
            printf("%d", query[n][j]);
        }
        printf("\n");
    }
}