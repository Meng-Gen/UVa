#include <iostream>
#include <stdio.h>

int numbers[1002];

int main(int argc, char* argv[])
{
    int N;
    while (std::cin >> N)
	{
        for (int i = 0; i < N; i++)
        {
            std::cin >> numbers[i];
        }

		// Bubble sort
        int flip_count = 0;
		for (int i = 0; i < N; i++)
		{
			for (int j = N-1; j > i; j--)
			{
				if (numbers[j-1] > numbers[j])
				{
					int temp = numbers[j-1];
					numbers[j-1] = numbers[j];
					numbers[j] = temp;
                    flip_count++;
				}
			}
		}
		printf("Minimum exchange operations : %d\n", flip_count);
	}
	
	return 0;
}