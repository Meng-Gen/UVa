#include <iostream>
#include <stdio.h>

// 59^3 - 58^3 = 10267.
long long cube[60];

// 999 = 12^3 - 9^3 = 10^3 - 1^3
int main(int argc, char* argv[])
{
    for (int i = 0; i < 60; i++)
    {
        cube[i] = i*i*i;
    }

    int N;
    while (std::cin >> N)
    {
        if (N <= 0)
        {
            break;
        }

        bool found = false;
        for (int i = 1; cube[i+1] - cube[i] <= N; i++)
        {
            for (int j = i+1; cube[j] - cube[i] <= N; j++)
            {
                if (N == (cube[j] - cube[i]))
                {
                    std::cout << j << " " << i << std::endl;
                    found = true;
                    // Only break the inner loop.
                    // You need to break the outer loop.
                    break;
                }
            }
            // Otherwise you will get a lot of WA because of 999.
            if (found)
            {
                break;
            }
        }

		if (!found)
        {
            std::cout << "No solution" << std::endl;
        }
	}

	return 0;
}