#include <iostream>
#include <stdio.h>

// If we use any C++ native datatype to store a(n), a(1000) will cause 
// your program overflowed.  Hence, we store each digit of a(n) in the array 
// with length = 300.
int query[1001][300] = {};

// a(n) = a(n-1) + a(n-2).
int main(int argc, char* argv[])
{
    query[0][0] = 1;
    query[1][0] = 2;
    for (int i = 2; i < 1001; i++)
    {
        for (int j = 0; j < 300; j++)
        {
            query[i][j] = query[i-1][j] + query[i-2][j];
        }

        // Normalize.
        for (int j = 0; j < 300; j++)
        {
            query[i][j+1] += query[i][j]/10;
            query[i][j] %= 10;
        }
    }

    int n;
    while(std::cin >> n) 
    {
        int j = 0;
        for (j = 299; j >= 0; j--)
        {
            if (query[n][j] != 0)
            {
                break;
            }
        }
        for (; j >= 0; j--)
        {
            printf("%d", query[n][j]);
        }
        printf("\n");
	}
}