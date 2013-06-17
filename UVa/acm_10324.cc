#include <iostream>
#include <stdio.h>
#include <string.h>

int minimum(int a, int b) 
{
    return (a < b) ? a : b;
}

int maximum(int a, int b) 
{
    return (a > b) ? a : b;
}

char buffer[1000005] = {};

bool IsSameBetween(int lower_bound, int upper_bound)
{
    char c0 = buffer[lower_bound];
    for (int i = lower_bound + 1; i <= upper_bound; i++)
    {
        if (buffer[i] != c0)
        {
            return false;
        }
    }
    return true;
}

int main(int argc, char* argv[])
{
    int case_id = 1;
    while (std::cin >> buffer)
    {
        printf("Case %d:\n", case_id);
        case_id++;

        int num_queries;
        int index_i, index_j;    
        int lower_bound, upper_bound;

        std::cin >> num_queries;
        for (int query_id = 0; query_id < num_queries; query_id++)
        {
            std::cin >> index_i >> index_j;
            lower_bound = minimum(index_i, index_j);
            upper_bound = maximum(index_i, index_j);

            if (IsSameBetween(lower_bound, upper_bound))
            {
                puts("Yes");
            }
            else
            {
                puts("No");
            }
        }
    }
    return 0;
}