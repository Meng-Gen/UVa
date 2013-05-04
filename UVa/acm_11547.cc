#include <iostream>
#include <stdio.h>

//   (N * 567 / 9 + 7492) * 235 / 47 - 498
// = (N * 63 + 7492) * 5 - 498
// =  N * 315 + 36962
//
// The maximun answer could be 1000 * 315 + 36962.
int main(int argc, char* argv[])
{
	int num_testcase;
	std::cin >> num_testcase;

	for (int case_id = 0; case_id < num_testcase; case_id++)
	{
		long long N;
		std::cin >> N;

		long long result = N * 315 + 36962;
		if (result < 0)
		{
			result = -result;
		}
		long long tens_column = (result % 100) / 10;
		std::cout << tens_column << std::endl;
	}
	return 0;
}