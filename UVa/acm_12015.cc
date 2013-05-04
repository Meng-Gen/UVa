#include <iostream>
#include <string>
#include <stdio.h>

int main(int argc, char* argv[])
{
	int num_testcase;
	std::cin >> num_testcase;
	for (int case_id = 1; case_id <= num_testcase; case_id++)
	{
		std::string url_list[10];
		int relevance_list[10];
		for (int i = 0; i < 10; i++)
		{
			std::cin >> url_list[i] >> relevance_list[i];
		}

		int max_relevance = relevance_list[0];
		for (int i = 1; i < 10; i++)
		{
			if (relevance_list[i] > max_relevance)
			{
				max_relevance = relevance_list[i];
			}
		}

		printf("Case #%d:\n", case_id);
		for (int i = 0; i < 10; i++)
		{
			if (relevance_list[i] == max_relevance)
			{
				std::cout << url_list[i] << std::endl;
			}
		}
	}

	return 0;
}