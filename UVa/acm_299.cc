#include <iostream>
#include <stdio.h>

int trains[50];

int main(int argc, char* argv[])
{
	int num_testcase;
	std::cin >> num_testcase;
	for (int i = 1; i <= num_testcase; i++)
	{
		int num_train;
		std::cin >> num_train;

		for (int j = 0; j < num_train; j++)
		{
			std::cin >> trains[j];
		}

		int swap_count = 0;
		int temp;
		for (int p = 0; p < num_train; p++)
		{
			for (int q = p; q < num_train; q++)
			{
				if (trains[p] > trains[q])
				{
					temp = trains[p];
					trains[p] = trains[q];
					trains[q] = temp;
					swap_count++;
				}
			}
		}

		printf("Optimal train swapping takes %d swaps.\n", swap_count);
	}

	return 0;
}