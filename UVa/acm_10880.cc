#include <algorithm>
#include <iostream>
#include <vector>
#include <stdio.h>

int main(int argc, char* argv[]) 
{
    int num_testcases;
    std::cin >> num_testcases;
    for (int case_id = 1; case_id <= num_testcases; case_id++)
    {
        long long C, R;
        std::cin >> C >> R;

        if (C == R)
        {
            printf("Case #%d: 0\n", case_id);
            continue;
        }

        long long Q = C - R;
        if (Q <= R)
        {
            printf("Case #%d:\n", case_id);
            continue;
        }
        
        std::vector<int> G_list;
        for (long long i = 1; i * i <= Q; i++)
        {
            if (Q % i == 0)
            {
                if (i > R) 
                {
                    G_list.push_back(i);
                }
                long long another = Q / i;
                if (another != i && another > R)
                {
                    G_list.push_back(another);
                }
            }
        }
        std::sort(G_list.begin(), G_list.end());
        printf("Case #%d:", case_id);
        for (std::vector<int>::iterator it = G_list.begin(); 
            it != G_list.end(); it++)
        {
            printf(" %d", *it);
        }
        putchar('\n');
    }
    return 0;
}