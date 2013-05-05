#include <algorithm>
#include <iostream>
#include <stdio.h>

int coin_count;
int coin_values[102];
int knapsack_weight;
int knapsack_query[102][25001];

int main(int argc, char* argv[])
{
	int testcase_count;
	std::cin >> testcase_count;

	for (int case_id = 0; case_id < testcase_count; case_id++)
	{
		std::cin >> coin_count;
        
		if (coin_count < 0)
		{
			printf("0\n");
			continue;
		}
		for (int i = 0; i < coin_count; i++)
		{
			std::cin >> coin_values[i];
		}

        int total_value = 0;
        for (int i = 0; i < coin_count; i++)
        {
            total_value += coin_values[i];
        }

        if (total_value % 2 == 0)
        {
            knapsack_weight = total_value / 2;
        }
        else
        {
            knapsack_weight = (total_value + 1)/2;
        }

        for (int i = 0; i < coin_count; i++)
        {
            for (int j = 0; j <= knapsack_weight; j++)
            {
                knapsack_query[i][j] = 0;
            }
        }

        for (int i = 0; i < coin_count; i++)
        {
            for (int j = 0; j <= knapsack_weight; j++)
            {
                if (j - coin_values[i] < 0)
                {
                    knapsack_query[i+1][j] = knapsack_query[i][j];
                }
                else
                {
                    knapsack_query[i+1][j] = 
                        knapsack_query[i][j - coin_values[i]] + coin_values[i];
					
                    if (knapsack_query[i+1][j] < knapsack_query[i][j])
                    {
                        knapsack_query[i+1][j] = knapsack_query[i][j];
                    }
                }
            }
        }

        int dutch_one = knapsack_query[coin_count][knapsack_weight];
        int dutch_another = total_value - dutch_one;
        int diff = dutch_one - dutch_another;
        if (diff < 0)
        {
            diff = -diff;
        }
        printf("%d\n", diff);
	}

	return 0;
}