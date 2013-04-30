#include <iostream>

// Reference: http://en.wikipedia.org/wiki/Fibonacci_number
int main(int argc, char* argv[])
{
	int brick_count;
	while(1)
	{
		std::cin >> brick_count;

		if (brick_count == 0)
		{
			break;
		}
	
		long long way_num;
		if (brick_count == 1)
		{
			way_num = 1;
		}
		else if (brick_count == 2)
		{
			way_num = 2;
		}
		else
		{
			long long prev_way = 1;
			long long curr_way = 2;
			long long temp;
			for (long long i = 3; i <= brick_count; i++)
			{
				temp = curr_way;
				curr_way += prev_way;
				prev_way = temp;
			}
			way_num = curr_way;
		}
		std::cout << way_num << std::endl;
	}

	return 0;
}