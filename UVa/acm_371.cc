#include <iostream>

long long curr_max_cycle = 0;
long long curr_max_cycle_number = 0;

void max_cycle(long long i, long long j)
{
	curr_max_cycle = 0;
	curr_max_cycle_number = i;
	for (long long k = i; k <= j; k++) 
	{
		long long cycle = 0;
		if (k == 1)
		{
			cycle = 3;
		}
		else 
		{
			long long n = k;
			while (n != 1) 
			{
				if (n % 2 == 0) 
				{
					n = n / 2;
				}
				else 
				{
					n = 3 * n + 1;
				}
				cycle++;
			}
		}
		if (cycle > curr_max_cycle)
		{
			curr_max_cycle = cycle;
			curr_max_cycle_number = k;
		}
	}
}

int main(int argc, char* argv[])
{
	long long i;
	long long j;

	while (1) 
	{
		std::cin >> i >> j;
		if (i == 0 && j == 0)
		{
			break;
		}

		if (i > j) 
		{
			long long temp = i;
			i = j;
			j = temp;
		}
		max_cycle(i, j);
		std::cout << "Between " << i << " and " << j << ", " << curr_max_cycle_number << " generates the longest sequence of " << curr_max_cycle << " values." << std::endl;
	}

	return 0;
}