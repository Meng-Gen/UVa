#include <iostream>
#include <vector>
#include <stdio.h>

bool matrix[102][102] = {};

int main(int argc, char* argv[]) 
{
    int N;
    while (std::cin >> N && N)
    {
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                std::cin >> matrix[i][j];
            }
        }

        std::vector<int> corrupt_rows;
        for (int i = 0; i < N; i++)
        {
            int sum = 0;
            for (int j = 0; j < N; j++)
            {
                sum += matrix[i][j];
            }
            if (sum % 2 == 1)
            {
                corrupt_rows.push_back(i);
            }
        }

        std::vector<int> corrupt_columns;
        for (int j = 0; j < N; j++)
        {
            int sum = 0;
            for (int i = 0; i < N; i++)
            {
                sum += matrix[i][j];
            }
            if (sum % 2 == 1)
            {
                corrupt_columns.push_back(j);
            }
        }

        int corrupt_row_count = corrupt_rows.size();
        int corrupt_column_count = corrupt_columns.size();
        if (corrupt_row_count == 0 && corrupt_column_count == 0)
        {
            puts("OK");
        }
        else if (corrupt_row_count == 1 && corrupt_column_count == 1)
        {
            // 0-based to 1-based
            printf("Change bit (%d,%d)\n", 
                corrupt_rows[0] + 1, corrupt_columns[0] + 1);
        }
        else
        {
            puts("Corrupt");
        }
    }
    return 0;
}