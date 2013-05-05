#include <iostream>
#include <stdio.h>

int get_k(int n)
{
    // 0 = - 1 - 2 + 3.
    if (n == 0)
    {
        return 3;
    }
    if (n < 0)
    {
        n = -n;
    }

    int k = 0;
    for (; ; k++) 
    {
        // If 1 + 2 + ... + k - n is odd, at least
        // we can extend two terms + (k + 1) - (k + 2).
        if (k*(k+1)/2 >= n && (k*(k+1)/2 - n) % 2 == 0)
        {
            return k;
        }
    }

    // It should be not here.
    return -1;
}

int main(int argc, char* argv[])
{
    int testcase_count;
    scanf("%d", &testcase_count);

    while(testcase_count--) 
    {
        int n;
        scanf("%d", &n);
        printf("%d\n", get_k(n));

        if(testcase_count > 0)
        {
            printf("\n");
        }
	}
}