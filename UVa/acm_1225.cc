#include <iostream>
#include <stdio.h>

int digit_counting[10001][10] = {};

void InitDigitCounting()
{
    for (int n = 1; n < 10001; n++)
    {
        for (int i = 0; i <= 9; i++)
        {
            digit_counting[n][i] = digit_counting[n-1][i];
        }

        int d = n;
        while (d)
        {
            digit_counting[n][d % 10]++;
            d /= 10;
        }
    }
}

int main(int argc, char* argv[])
{
    InitDigitCounting();

    int num_testcases;
    std::cin >> num_testcases;
    for (int case_id = 1; case_id <= num_testcases; case_id++)
    {
        int n;
        std::cin >> n;
        for (int i = 0; i <= 9; i++)
        {
            printf("%d", digit_counting[n][i]);
            if (i == 9)
            {
                putchar('\n');
            }
            else
            {
                putchar(' ');
            }
        }
    }
    
    return 0;
}