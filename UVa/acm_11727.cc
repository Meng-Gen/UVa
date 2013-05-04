#include <iostream>
#include <string>
#include <stdio.h>

// Ad Hoc
int main(int argc, char* argv[])
{
	int num_testcase;
	std::cin >> num_testcase;

	for (int case_id = 1; case_id <= num_testcase; case_id++)
	{
		int salaries[3];
		std::cin >> salaries[0] >> salaries[1] >> salaries[2];

		// Bubble sort
		for (int i = 0; i < 3; i++)
		{
			for (int j = i + 1; j < 3; j++)
			{
				if (salaries[i] > salaries[j])
				{
					int temp = salaries[i];
					salaries[i] = salaries[j];
					salaries[j] = temp;
				}
			}
		}
		printf("Case %d: %d\n", case_id, salaries[1]);
	}
	
	return 0;
}