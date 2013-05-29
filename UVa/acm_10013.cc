#include <iostream>
#include <stdio.h>

int sum[1000002] = {};

int main(int argc, char* argv[])
{
    int num_testcases;
    std::cin >> num_testcases;
    for (int case_id = 0; case_id < num_testcases; case_id++)
    {
        if (case_id)
        {
            putchar('\n');
        }

        sum[0] = 0;

        int num_digits;
        std::cin >> num_digits;
        for (int i = 1; i <= num_digits; i++)
        {
            int a;
            int b;
            std::cin >> a >> b;
            sum[i] = a + b;
        }
        
        for (int i = num_digits; i > 0; i--)
        {
            sum[i-1] += (sum[i]/10);
            sum[i] %= 10;
        }

        if (sum[0])
        {
            putchar(sum[0] + '0');
        }
        for (int i = 1; i <= num_digits; i++)
        {
            putchar(sum[i] + '0');
        }
        putchar('\n');
    }
    return 0;
}