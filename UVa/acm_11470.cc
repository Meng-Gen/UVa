#include <iostream>
#include <stdio.h>

long long grid[12][12] = {};
long long matrix_sum[6] = {};

int main(int argc, char* argv[])
{
    int n;
    int case_id = 1;
    while (std::cin >> n && n)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                std::cin >> grid[i][j];
            }
        }

        printf("Case %d: ", case_id);
        if (n % 2 == 1)
        {
            for (int k = 0; k <= n/2; k++)
            {
                matrix_sum[k] = 0;
                for (int i = -k; i <= k; i++)
                {
                    for (int j = -k; j <= k; j++)
                    {
                        matrix_sum[k] += grid[n/2 + i][n/2 + j];
                    }
                }
            }
            for (int k = n/2; k >= 1; k--)
            {
                printf("%lld ", matrix_sum[k] - matrix_sum[k-1]);
            }
            printf("%lld\n", matrix_sum[0]);
        }
        else
        {
            for (int k = 0; k < n/2; k++)
            {
                matrix_sum[k] = 0;
                for (int i = 0; i <= 2 * k + 1; i++)
                {
                    for (int j = 0; j <= 2 * k + 1; j++)
                    {
                        matrix_sum[k] += grid[n/2-1-k+i][n/2-1-k+j];
                    }
                }
            }
            for (int k = n/2 - 1; k >= 1; k--)
            {
                printf("%lld ", matrix_sum[k] - matrix_sum[k-1]);
            }
            printf("%lld\n", matrix_sum[0]);
        }
        case_id++;
    }

    return 0;
}