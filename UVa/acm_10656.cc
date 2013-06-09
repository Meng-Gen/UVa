#include <iostream>
#include <vector>
#include <stdio.h>

int main(int argc, char* argv[]) 
{
    int N;
    while (std::cin >> N && N)
    {
        std::vector<int> max_subsequence;
        int a;
        for (int i = 0; i < N; i++)
        {
            std::cin >> a;
            if (a)
            {
                max_subsequence.push_back(a);
            }
        }
        int length = max_subsequence.size();
        if (length)
        {
            printf("%d", max_subsequence[0]);
            for (int i = 1; i < length; i++)
            {
                printf(" %d", max_subsequence[i]);
            }
            putchar('\n');
        }
        else
        {
            puts("0");
        }
    }
    return 0;
}