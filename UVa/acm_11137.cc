#include <iostream>
#include <stdio.h>

int S[22] = {};
long long coin_change[10001][22] = {};

inline void InitCoinChangeTable()
{
    for (int i = 0; i < 22; i++)
    {
        S[i] = i * i * i;
    }

    for (int i = 0; i < 10001; i++)
	{
		for (int j = 0; j < 22; j++)
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

    int N; 
    while (std::cin >> N)
	{
        std::cout << coin_change[N][21] << std::endl;
	}

	return 0;
}
