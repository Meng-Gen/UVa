#include <iostream>

long long max_cycle(long long i, long long j)
{
	if (i > j) 
	{
		long long temp = i;
		i = j;
		j = temp;
	}
	long long curr_max_cycle = 0;
	for (long long k = i; k <= j; k++) 
	{
		long long n = k;
		long long cycle = 1;
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
		if (cycle > curr_max_cycle)
		{
			curr_max_cycle = cycle;
		}
	}
	return curr_max_cycle;
}

int main(int argc, char* argv[])
{
	long long i;
	long long j;

	while (std::cin >> i >> j) 
	{
		std::cout << i << " " << j << " " << max_cycle(i, j) << std::endl;
	}
	return 0;
}
