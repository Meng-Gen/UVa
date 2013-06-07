#include <algorithm>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>

int num_list[1001] = {};
int sums[500000] = {};

inline int minimum(int a, int b)
{
    return (a < b) ? a : b;
}

int main(int argc, char* argv[]) 
{
    int case_id = 1;
    int n;
    while (std::cin >> n && n)
    {
        printf("Case %d:\n", case_id);

        for (int i = 0; i < n; i++)
        {
            std::cin >> num_list[i];
        }

        int curr_pos = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = i+1; j < n; j++)
            {
                sums[curr_pos] = num_list[i] + num_list[j];
                curr_pos++;
            }
        }
        std::sort(sums, sums + curr_pos);

        int m;
        std::cin >> m;
        for (int i = 0; i < m; i++)
        {
            int query;
            std::cin >> query;

            int closest = sums[0];
            int diff = abs(closest - query);
            for (int i = 1; i < curr_pos; i++)
            {
                int curr_diff = abs(sums[i] - query);
                if (diff > curr_diff)
                {
                    diff = curr_diff;
                    closest = sums[i];
                }
            }
            printf("Closest sum to %d is %d.\n", query, closest);    
        }
        
        case_id++;
    }
    return 0;
}