#include <iostream>
#include <stdio.h>

int main(int argc, char* argv[]) 
{
    long long N;
    while (std::cin >> N && N)
    {
        int ages[102] = {};
        int curr_age;
        for (int i = 0; i < N; i++)
        {
            std::cin >> curr_age;
            ages[curr_age]++; // counting sort
        }

        bool is_first_term = true;
        for (int i = 0; i < 102; i++)
        {
            for (int j = 0; j < ages[i]; j++)
            {
                if (is_first_term)
                {
                    printf("%d", i);
                    is_first_term = false;
                }
                else
                {
                    printf(" %d", i);
                }
            }
        }
        putchar('\n');
    }
    return 0;
}