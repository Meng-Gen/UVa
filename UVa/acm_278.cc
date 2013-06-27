#include <iostream>
#include <stdio.h>

inline int minimum(int a, int b) 
{ 
    return (a < b) ? a : b; 
}

int main(int argc, char* argv[]) 
{   
    char chess;
    int m, n;

    int num_testcases;
    std::cin >> num_testcases;
    while (num_testcases--)
    {
        std::cin >> chess >> m >> n;
        if (chess == 'r' || chess == 'Q')
        {
            printf("%d\n", minimum(m, n));
        }
        else if (chess == 'K')
        {
            printf("%d\n", ((m+1)/2)*((n+1)/2));
        }
        else if (chess == 'k')
        {
            printf("%d\n", (m*n+1)/2);
        }
    }
    return 0;
}
