#include <iostream>
#include <map>
#include <stdio.h>

int cube[1001] = {};
std::map<int, int> cube_sum;
int taxicab_numbers[1554];

// Precalculate solution space and prune unnecessary calcuation
inline void InitTaxicabNumbers()
{
    for (int i = 0; i <= 1000; i++)
    {
        cube[i] = i*i*i;
    }

    for (int i = 1; i <= 1000; i++)
    {
        for (int j = i; j <= 1000; j++)
        {
            if (cube[i] > 1000100000 - cube[j])
            {
                break;
            }
            cube_sum[cube[i] + cube[j]]++;
        }
    }

    int curr_pos = 0;
    for (std::map<int, int>::iterator it = cube_sum.begin(); 
        it != cube_sum.end(); it++)
    {
        if (it->second > 1)
        {
            taxicab_numbers[curr_pos] = it->first;
            curr_pos++;
        }
    }
}

int main(int argc, char* argv[])
{
    InitTaxicabNumbers();

    int lower_bound, range;
    while (std::cin >> lower_bound >> range)
    {
        bool is_found = false;

        // # taxicab numbers are much less than 100000, 
        // and thus we search all taxicab numbers instead.
        for (int i = 0; i < 1554; i++)
        {
            if (taxicab_numbers[i] > lower_bound + range)
            {
                break;
            }
            if (taxicab_numbers[i] >= lower_bound)
            {
                is_found = true;
                printf("%d\n", taxicab_numbers[i]);
            }
        }
        if (!is_found)
        {
            puts("None");
        }
    }
    return 0;
}