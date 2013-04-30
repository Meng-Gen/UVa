#include <iostream>

using namespace std;

int main(int argc, char* argv[])
{
	long long x[3][3];
	while (std::cin >> x[0][0] >> x[0][1] >> x[0][2] >> x[1][0] >> x[1][1] >> x[1][2] >> x[2][0] >> x[2][1] >> x[2][2]) 
	{
		long long sum = 0;
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				sum += x[i][j];
			}
		}

		// Algorithm: brute force
		// If more than one order of brown, green, and clear bins yields the 
		// minimum number of movements then the alphabetically first string 
		// representing a minimal configuration should be printed.
		// So we prepare an ordered query string list for querying.
		char query[6][4] = { "BCG", "BGC", "CBG", "CGB", "GBC", "GCB"};
		long long result[6];
		for (int i = 0; i < 6; i++)
		{
			result[i] = sum;
			for (int j = 0; j < 3; j++)
			{
				if (query[i][j] == 'B')
				{
					result[i] -= x[j][0];
				}
				else if (query[i][j] == 'G')
				{
					result[i] -= x[j][1];
				}
				else if (query[i][j] == 'C')
				{
					result[i] -= x[j][2];
				}
			}
		}

		long long min_result = result[5];
		char* min_query = query[5];
		for (int i = 4; i >= 0; i--)
		{
			if (result[i] <= min_result)
			{
				min_result = result[i];
				min_query = query[i];
			}
		}

		std::cout << min_query << " " << min_result << std::endl;
	}
	return 0;
}