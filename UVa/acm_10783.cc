#include <iostream>
#include <stdio.h>

int main(int argc, char* argv[])
{
	int num_testcase;
	std::cin >> num_testcase;
	for (int i = 1; i <= num_testcase; i++)
	{
		int a;
		int b; 
		std::cin >> a;
		std::cin >> b;
	
		if (a > b)
		{
			int temp = a;
			a = b;
			b = temp;
		}

		if (a % 2 == 0) 
		{
			a++;
		}
		if (b % 2 == 0)
		{
			b--;
		}

		int answer = 0;
		if (a <= b)
		{
			answer = ((a + b) * ((b - a)/2 + 1)) / 2;
		}
		
		std::cout << "Case " << i << ": " << answer << std::endl;
	}

	return 0;
}