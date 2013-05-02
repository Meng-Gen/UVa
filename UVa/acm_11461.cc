#include <iostream>
#include <math.h>

using namespace std;

int main(int argc, char* argv[])
{
	int a;
	int b;
	
	while (std::cin >> a >> b) 
	{
		if ((a == 0) && (b == 0))
		{
			break;
		}

		if (a > b)
		{
			int temp = a; 
			a = b; 
			b = temp;
		}

		int sqrt_begin = (int)sqrt((double)(a));
		if (sqrt_begin * sqrt_begin < a)
		{
			sqrt_begin++;
		}
		int sqrt_end = (int)sqrt((double)(b));
		if (sqrt_begin > sqrt_end)
		{
			std::cout << "0" << std::endl;		
		}
		else 
		{
			std::cout << sqrt_end - sqrt_begin + 1 << std::endl;
		}
	}
	return 0;
}
