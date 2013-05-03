#include <iostream>
#include <map>
#include <string>
#include <stdio.h>

char buffer[50000];

int main(int argc, char* argv[])
{
	int N;
	std::cin >> N;
	getchar();

	std::map<std::string, int> conquests_list;
	for (int i = 0; i < N; i++)
	{
		std::cin.getline(buffer, 50000);
		for (int j = 0; buffer[j] != '\0'; j++)
		{
			if (buffer[j] == ' ')
			{
				buffer[j] = '\0';
				break;
			}
		}
		conquests_list[buffer]++;
	}

	for (std::map<std::string, int>::iterator it = conquests_list.begin(); 
		it != conquests_list.end(); 
		it++)
	{
		std::cout << it->first << " " << it->second << std::endl;
	}

	return 0;
}