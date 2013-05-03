#include <iostream>
#include <stdio.h>

int query[1 << 14];

int main(int argc, char* argv[])
{
	int curr_power = 0;
	int N = 0;

	query[0] = 0;
	query[1] = 0;
	for (int i = 2; i < 10001;)
	{
		int power_of_two = 1 << curr_power;
		for (int j = 0; j < power_of_two; j++)
		{
			query[i+j] = curr_power + 1;
		}
		curr_power++;
		i += power_of_two;
	}

	int case_id = 1;

	while (1)
	{
		int N;
		std::cin >> N;

		// Input is terminated by a line containing a negative integer.
		// Not necessary -1.  Otherwise you will get a lot of TLE.
		if (N < 0)
		{
			break;
		}

		printf("Case %d: %d\n", case_id, query[N]);
		// You can create the result table as the above.  Or hand-code as the 
		// following.  Both methods are slow. (0.019s)

		/*
		if (N == 1)
		{
			printf("Case %d: 0\n", case_id);
		}
		else if (N <= 2)
		{
			printf("Case %d: 1\n", case_id);
		}
		else if (N <= 4)
		{
			printf("Case %d: 2\n", case_id);
		}
		else if (N <= 8)
		{
			printf("Case %d: 3\n", case_id);
		}
		else if (N <= 16)
		{
			printf("Case %d: 4\n", case_id);
		}
		else if (N <= 32)
		{
			printf("Case %d: 5\n", case_id);
		}
		else if (N <= 64)
		{
			printf("Case %d: 6\n", case_id);
		}
		else if (N <= 128)
		{
			printf("Case %d: 7\n", case_id);
		}
		else if (N <= 256)
		{
			printf("Case %d: 8\n", case_id);
		}
		else if (N <= 512)
		{
			printf("Case %d: 9\n", case_id);
		}
		else if (N <= 1024)
		{
			printf("Case %d: 10\n", case_id);
		}
		else if (N <= 2048)
		{
			printf("Case %d: 11\n", case_id);
		}
		else if (N <= 4096)
		{
			printf("Case %d: 12\n", case_id);
		}
		else if (N <= 8192)
		{
			printf("Case %d: 13\n", case_id);
		}
		else 
		{
			printf("Case %d: 14\n", case_id);
		}
		*/

		case_id++;
	}

	return 0;
}