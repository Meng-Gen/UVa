// Backtracking.
#include <iostream>
#include <stdio.h>

int k;
int S[14];

bool is_used[14];
int solution_vector[6];

void backtrack(int dimension)
{    
    if ((dimension > 1) &&
        (solution_vector[dimension-1] <= solution_vector[dimension-2]))
    {
        return;
    }
    
    if (dimension == 6)
    {
        // Print solution.
        for (int i = 0; i < 6; i++)
        {
            printf("%d", solution_vector[i]);
            if (i != 5)
            {
                printf(" ");
            }
        }
        printf("\n");
        return;
    }

    for (int i = 0; i < k; i++)
    {
        if (!is_used[i])
        {
            solution_vector[dimension] = S[i];
            is_used[i] = true;
            backtrack(dimension + 1);
            is_used[i] = false;
        }
    }
}

int main(int argc, char* argv[])
{
    int testcase_id = 1;
    while (1)
    {
        std::cin >> k;
        if (k == 0)
        {
            break;
        }

        if (testcase_id > 1)
        {
            printf("\n");
        }

        for (int i = 0; i < 14; i++)
        {
            is_used[i] = false;
        }
        for (int i = 0; i < 6; i++)
        {
            solution_vector[i] = 0;
        }

        for (int i = 0; i < k; i++)
        {
            std::cin >> S[i];
        }
        backtrack(0);

        testcase_id++;
    }

    return 0;
}