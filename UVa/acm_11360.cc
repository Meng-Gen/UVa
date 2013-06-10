#include <iostream>
#include <string>
#include <stdio.h>

char matrix[10][10];

int main(int argc, char* argv[]) 
{
    int num_testcases;
    std::cin >> num_testcases;

    for (int case_id = 1; case_id <= num_testcases; case_id++)
    {
        int matrix_dimension;
        std::cin >> matrix_dimension;
        for (int i = 0; i < matrix_dimension; i++)
        {
            for (int j = 0; j < matrix_dimension; j++)
            {
                std::cin >> matrix[i][j];
                matrix[i][j] -= '0';
            }
        }

        int num_operations;
        std::cin >> num_operations;
        std::string op;
        for (int op_id = 0; op_id < num_operations; op_id++)
        {
            std::cin >> op;
            if (op.compare("row") == 0)
            {
                int a, b;
                std::cin >> a >> b;

                int temp;
                for (int j = 0; j < matrix_dimension; j++)
                {
                    // 1-based to 0-based
                    temp = matrix[a-1][j];
                    matrix[a-1][j] = matrix[b-1][j];
                    matrix[b-1][j] = temp;
                }
            }
            else if (op.compare("col") == 0)
            {
                int a, b;
                std::cin >> a >> b;

                int temp;
                for (int i = 0; i < matrix_dimension; i++)
                {
                    // 1-based to 0-based
                    temp = matrix[i][a-1];
                    matrix[i][a-1] = matrix[i][b-1];
                    matrix[i][b-1] = temp;
                }
            }
            else if (op.compare("inc") == 0)
            {
                for (int i = 0; i < matrix_dimension; i++)
                {
                    for (int j = 0; j < matrix_dimension; j++)
                    {
                        matrix[i][j] = (matrix[i][j] + 1) % 10;
                    }
                }
            }
            else if (op.compare("dec") == 0)
            {
                for (int i = 0; i < matrix_dimension; i++)
                {
                    for (int j = 0; j < matrix_dimension; j++)
                    {
                        matrix[i][j] = (matrix[i][j] + 9) % 10;
                    }
                }
            }
            else // must be |transpose|
            {
                int temp;
                for (int i = 0; i < matrix_dimension; i++)
                {
                    for (int j = i+1; j < matrix_dimension; j++)
                    {
                        temp = matrix[i][j];
                        matrix[i][j] = matrix[j][i];
                        matrix[j][i] = temp;
                    }
                }
            }
        }

        printf("Case #%d\n", case_id);
        for (int i = 0; i < matrix_dimension; i++)
        {
            for (int j = 0; j < matrix_dimension; j++)
            {
                printf("%d", matrix[i][j]);
            }
            putchar('\n');
        }
        putchar('\n');
    }
    return 0;
}