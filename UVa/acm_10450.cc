#include <iostream>
#include <stdio.h>

// Copy code from UVa 10334

int query[1001][300] = {};

inline void InitQueryTable()
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
}

int main(int argc, char* argv[])
{
    InitQueryTable();

    int num_testcases;
    std::cin >> num_testcases;
    for (int case_id = 1; case_id <= num_testcases; case_id++)
    {
        printf("Scenario #%d:\n", case_id);

        int n;
        std::cin >> n;

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
        printf("\n\n");
	}
}