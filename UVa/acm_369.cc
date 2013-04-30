#include <iostream>

// Reference: https://en.wikipedia.org/wiki/Combination
int main(int argc, char* argv[])
{
	long long query[101][101];
	for (int i = 1; i < 101; i++)
	{
		query[i][0] = 1;
		query[i][1] = i;
	}
	
	for (int i = 2; i < 101; i++)
	{
		for (int j = 2; j <= i; j++)
		{
			if (i == j)
			{
				query[i][j] = 1;
			}
			else
			{
				query[i][j] = query[i - 1][j - 1] + query[i - 1][j];
			}
		}
	}

	int N;
	int M;
	while(1)
	{
		std::cin >> N >> M;
		if (N == 0 && M == 0)
		{
			break;
		}
		std::cout << N << " things taken " << M << " at a time is " << query[N][M] << " exactly." << std::endl;
	}

	return 0;
}