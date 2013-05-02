#include <iostream>
#include <stdio.h>

int main(int argc, char* argv[])
{
	int n;
	while(std::cin >> n)
	{
		for (int i = 1; i <= n; i++)
		{
			int	edges[3];
			int temp;
			
			std::cin >> edges[0] >> edges[1] >> edges[2];
			
			// Bubble sort.
			for (int j = 0; j < 3; j++)
			{
				for (int k = 0; k < 3; k++)
				{
					if (j != k && edges[j] < edges[k])
					{
						temp = edges[j];
						edges[j] = edges[k];
						edges[k] = temp;
					}
				}
			}
		
			printf("Case %d: ", i);
			if (edges[0] <= edges[2] - edges[1])
			{
				printf("Invalid\n");
			}
			else if (edges[0] == edges[2]) 
			{
				printf("Equilateral\n");
			}
			else if ((edges[0] == edges[1]) || (edges[1] == edges[2]))
			{
				printf("Isosceles\n");
			}
			else
			{
				printf("Scalene\n");
			}
		}
	}

	return 0;
}