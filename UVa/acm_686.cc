#include <iostream>

#define MAX_N (1 << 15)

int main(int argc, char* argv[])
{
	// Create the prime table from 2 to MAX_N.
	// Algorithm: Sieve of Eratosthenes
	// Wiki: http://en.wikipedia.org/wiki/Sieve_of_Eratosthenes
	//
	// We examine every number of the form 6k+1 or 6k+5 only because every 
	// odd prime larger than 6 cannot divided by 2 or 3.
	bool prime_visited[MAX_N];
	bool prime_query[MAX_N];
	for (int i = 0; i < MAX_N; i++)
	{
		prime_visited[i] = false;
		prime_query[i] = false;
	}

	prime_visited[0] = true;
	prime_visited[1] = true;
	prime_query[2] = true;
	for (int i = 1; i < MAX_N/2; i++)
	{
		prime_visited[i * 2] = true;
	}

	prime_query[3] = true;
	for (int i = 1; i < MAX_N/3; i++)
	{
		prime_visited[i * 3] = true;
	}

	prime_query[5] = true;
	for (int i = 1; i < MAX_N/5; i++)
	{
		prime_visited[i * 5] = true;
	}
	
	int step = 2;
	for (int curr_visiting = 7; curr_visiting < MAX_N; curr_visiting += step)
	{
		step = 6 - step;
		if (prime_visited[curr_visiting])
		{
			continue;
		}
		prime_visited[curr_visiting] = true;

		prime_query[curr_visiting] = true; 
		for (int i = 2; i * curr_visiting < MAX_N; i++)
		{
			prime_visited[i * curr_visiting] = true;
		}
	}

	int N;
	while (std::cin >> N) 
	{
		if (N == 0)
		{
			break;
		}
		if (N == 4)
		{
			std::cout << 1 << std::endl;
			continue;
		}

		int pair_count = 0;
		for (int i = 3; i <= N / 2; i += 2)
		{
			if (prime_query[i] && prime_query[N - i])
			{
				pair_count++;
			}
		}

		std::cout << pair_count << std::endl;
	}
	return 0;
}
