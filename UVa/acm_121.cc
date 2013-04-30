#include <iostream>
#include <math.h>

using namespace std;

double kRegularTriangleHeight = sqrt(3.0) / 2.0;

long long get_skew_count(double width, double height)
{
	int level = 0;
	if (height >= 1.0)
	{
		level = (int)((height - 1.0)/kRegularTriangleHeight) + 1;	
	}

	long long count = (int)width * level;
	if (width - (int)width < 0.5)
	{
		count -= (int)level/2;
	}

	return count;
}

int main(int argc, char* argv[])
{
	double a;
	double b;
	
	while (std::cin >> a >> b) 
	{
		long long skew_count_width_a = get_skew_count(a, b);
		long long skew_count_width_b = get_skew_count(b, a);
		
		long long skew_count = skew_count_width_a;
		if (skew_count_width_b > skew_count)
		{
			skew_count = skew_count_width_b;
		}

		long long grid_count = (int)a * (int)b;
		if (skew_count > grid_count)
		{
			std::cout << skew_count << " skew" << std::endl;		
		}
		else
		{
			std::cout << grid_count << " grid" << std::endl;
		}
	}
	return 0;
}
