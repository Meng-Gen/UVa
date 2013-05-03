#include <iostream>
#include <sstream>
#include <string>
#include <vector>

// fibonacci[40] = 102334155 is enough.
long long fibonacci[41]; 

std::string convert_to_fibonaccimal_base(int n)
{
	if (n == 0)
	{
		return "0";
	}
	std::vector<char> base_result;
	int curr_n = n;
	for (int i = 40; i > 1; i--)
	{
		if (curr_n >= fibonacci[i])
		{
			curr_n -= fibonacci[i];
			base_result.push_back('1');
		}
		else
		{
			base_result.push_back('0');
		}
	}
	
	int begin_with_one_index = base_result.size() - 1;
	for (int i = 0; i < base_result.size(); i++)
	{
		if (base_result[i] == '1')
		{
			begin_with_one_index = i;
			break;
		}
	}
	
	std::stringstream result_builder;
	for (int i = begin_with_one_index; i < base_result.size(); i++)
	{
		result_builder << base_result[i];
	}
	
	return result_builder.str();
}

int main(int argc, char* argv[])
{
	fibonacci[0] = 0;
	fibonacci[1] = 1;
	for (int i = 2; i < 41; i++)
	{
		fibonacci[i] = fibonacci[i-1] + fibonacci[i-2];
	}

	int testcase;
	std::cin >> testcase;

	for (int i = 0; i < testcase; i++)
	{
		int N;
		std::cin >> N;
		std::cout << N << " = " << convert_to_fibonaccimal_base(N) << " (fib)" << std::endl;
	}
	
	return 0;
}