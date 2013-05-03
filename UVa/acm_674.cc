//  Reference: UVa 357

#include <iostream>
#include <stdio.h>

int S[6] = { 0, 1, 5, 10, 25, 50 };
long long coin_change[7490][6];

int main(int argc, char* argv[])
{
	for (int i = 0; i < 7490; i++)
	{
		for (int j = 0; j < 6; j++)
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

	int N;
	while (std::cin >> N)
	{
		printf("%lld\n", coin_change[N][5]);
	}
	return 0;
}