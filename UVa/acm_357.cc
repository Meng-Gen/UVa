//  Practice with 
//      Root :: Competitive Programming: Increasing the Lower Bound of 
//      Programming Contests (Steven & Felix Halim) :: 
//      Chapter 3. Problem Solving Paradigms :: 
//      Dynamic Programming :: Coin Change - Classical	
//
//  Reference: http://www.algorithmist.com/index.php/Coin_Change

#include <iostream>
#include <string>
#include <stdio.h>

// S = { penny: 1c, nickel: 5c, dime: 10c, quarter: 25c, half-dollar: 50c }
int S[6] = { 0, 1, 5, 10, 25, 50 };
long long coin_change[30001][6];

int main(int argc, char* argv[])
{
	for (int i = 0; i < 30001; i++)
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
		long long change_way = coin_change[N][5];
		if (change_way == 1)
		{
			printf("There is only 1 way to produce %d cents change.\n", N);
		}
		else
		{
			printf("There are %lld ways to produce %d cents change.\n", change_way, N);
		}
	}
	return 0;
}