#include <iostream>
#include <stdlib.h>
#include <string.h>

using namespace std;

// TODO: TLE
// BF cannot work.  We need DP instead.
int main(int argc, char* argv[])
{
	char dim_string[4];
	char buffer[50000];
	int M[100][100];

	while (1)
	{
		std::cin.getline(dim_string, 4); 
		int N = atoi(dim_string);

		int matrix_size = N * N;
		int curr_index = 0;
		while(curr_index != matrix_size)
		{
			std::cin.getline(buffer, 50000);
			char* curr_string = strtok(buffer, " ");
			if (curr_string)
			{
				M[curr_index / N][curr_index % N] = atoi(curr_string);
				curr_index++;
			}
			while (curr_string = strtok(0, " "))
			{
				M[curr_index / N][curr_index % N] = atoi(curr_string);
				curr_index++;
			}
		}

		for (int i = 0; i < N; i++)
		{
			for (int j = 1; j < N; j++)
			{
				M[i][j] += M[i][j-1];
			}
		}
		for (int j = 0; j < N; j++)
		{
			for (int i = 1; i < N; i++)
			{
				M[i][j] += M[i-1][j];
			}
		}

		// Time complexity = O(N^4)
		int max_sum = 0;
		if (N > 0)
		{
			max_sum = M[0][0];
			for (int x1 = 0; x1 < N; x1++)
			{
				for (int y1 = 0; y1 < N; y1++)
				{
					for (int x2 = x1; x2 < N; x2++)
					{
						for (int y2 = y1; y2 < N; y2++)
						{
							int sub_sum = M[x2][y2];
							if (x1 != x2)
							{
								sub_sum -= M[x1][y2];
							}
							if (y1 != y2)
							{
								sub_sum -= M[x2][y1];
							}
							if (x1 != x2 && y1 != y2)
							{
								sub_sum += M[x1][y1];
							}
							if (sub_sum > max_sum)
							{
								max_sum = sub_sum;
							}
						}
					}	
				}
			}
		}

		std::cout << max_sum << std::endl;
	}
}