#include <iostream>
#include <stdio.h>

// Check four cases (a, b) = (+/- 1000000000, +/- 1000000000).
int main(int argc, char* argv[])
{
	int testcase;
	std::cin >> testcase;

	for (int i = 0; i < testcase; i++)
	{
		long long a;
		long long b;
		std::cin >> a >> b;
	
		if (a > b)
		{
			std::cout << ">" << std::endl;
		}
		else if (a < b)
		{
			std::cout << "<" << std::endl;
		}
		else
		{
			std::cout << "=" << std::endl;
		}
	}

	return 0;
}