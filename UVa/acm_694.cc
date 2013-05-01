#include <iostream>
#include <stdio.h>

long long cycle_under_limit(long long A, long long L)
{
	long long n = A;
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
			if (n > L)
			{
				break;
			}
		}
		cycle++;
	}
	return cycle;
}

int main(int argc, char* argv[])
{
	long long A;
	long long L;

	long long case_num = 0;
	while (1) 
	{
		std::cin >> A >> L;
		if (A <= 0 || L < 0)
		{
			break;
		}
		case_num++;
		printf
		(
			"Case %lld: A = %lld, limit = %lld, number of terms = %lld\n", 
			case_num,
			A,
			L,
			cycle_under_limit(A, L)
		);
	}
	return 0;
}
