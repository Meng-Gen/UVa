#include <iostream>
#include <stdio.h>

// $100, $50, $20, $10, and $5 notes and $2, $1, 50c, 20c, 10c and 5c 
int S[12] = { 0, 5, 10, 20, 50, 100, 200, 500, 1000, 2000, 5000, 10000 };
long long coin_change[30001][12] = {};

inline void InitCoinChangeTable()
{
    for (int i = 0; i < 30001; i++)
	{
		for (int j = 0; j < 12; j++)
		{
			if (i == 0)
			{
				coin_change[i][j] = 1;
			}
			else if (j == 0)
			{
				coin_change[i][j] = 0;
			}
			else if (S[j] > i)
			{
				coin_change[i][j] = coin_change[i][j-1];
			}
			else 
			{
				coin_change[i][j] = coin_change[i][j-1] + coin_change[i-S[j]][j];
			}
		}
	}
}

int main(int argc, char* argv[])
{
	InitCoinChangeTable();

    int dollar, cent; 
	while (scanf("%d.%d", &dollar, &cent) != EOF && (dollar || cent))
	{
        printf("%3d.%02d%17lld\n", dollar, cent, 
            coin_change[dollar * 100 + cent][11]);
        dollar = 0;
        cent = 0;
	}

	return 0;
}

