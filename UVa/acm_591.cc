#include <iostream>
#include <vector>
#include <stdio.h>
#include <string.h> // strtok().  You will get CE without including this.
#include <stdlib.h> // atoi().  You will get CE without including this.

char buffer[50000];

int main(int argc, char* argv[])
{
	int test_set_count = 1;
	while(1)
	{
		// Parse n.
		std::cin.getline(buffer, 50000);
		int n = atoi(buffer);
		if (n == 0)
		{
			break;
		}

		// Parse h_i for i = 1 to n.
		std::vector<int> height_list;
		std::cin.getline(buffer, 50000);
		int curr_index = 0;
		while(curr_index != n)
		{
			char* curr_string = strtok(buffer, " ");
			if (curr_string)
			{
				height_list.push_back(atoi(curr_string));
				curr_index++;
			}
			while (curr_string = strtok(0, " "))
			{
				height_list.push_back(atoi(curr_string));
				curr_index++;
			}
		}
		
		int total_brick_count = 0;
		for(std::vector<int>::size_type i = 0; i != height_list.size(); i++) 
		{
			total_brick_count += height_list[i];
		}
		int average = total_brick_count / n;

		// Move the stack which contains higher brick count than the average 
		// down to the average.
		int move_count = 0;
		for(std::vector<int>::size_type i = 0; i != height_list.size(); i++) 
		{
			int diff = height_list[i] - average;
			if (diff > 0)
			{
				move_count += diff;
			}
		}

		printf("Set #%d\n", test_set_count);
		// Output a blank line after each set.  Otherwise you will get WA.
		printf("The minimum number of moves is %d.\n\n", move_count);

		test_set_count++;
	}

	return 0;
}