#include <iostream>
#include <stdio.h>

// Check the case (N, M) = (10000, 10000).
int main(int argc, char* argv[])
{
	int testcase;
	std::cin >> testcase;

	for (int i = 0; i < testcase; i++)
	{
		int N;
		int M;
		std::cin >> N >> M;
	
		int sonar_for_N = (N-2)/3;
		if (((N-2) % 3) != 0)
		{
			sonar_for_N++;
		}

		int sonar_for_M = (M-2)/3;
		if (((M-2) % 3) != 0)
		{
			sonar_for_M++;
		}

		std::cout << sonar_for_N * sonar_for_M << std::endl;
	}

	return 0;
}