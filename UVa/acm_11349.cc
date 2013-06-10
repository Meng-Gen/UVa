#include <iostream>
#include <stdio.h>

long long matrix[102][102];
int N;

bool IsSymmetric()
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (matrix[i][j] != matrix[N-1-i][N-1-j])
            {
                return false;
            }
            if (matrix[i][j] < 0)
            {
                return false;
            }
        }
    }
    return true;
}

int main(int argc, char* argv[]) 
{
    int num_testcases;
    std::cin >> num_testcases;

    for (int case_id = 1; case_id <= num_testcases; case_id++)
    {
        char dummy[2]; // Eat |N| and |=| two characters
        std::cin >> dummy[0] >> dummy[1] >> N;
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                std::cin >> matrix[i][j];
            }
        }

        if (IsSymmetric())
        {
            printf("Test #%d: Symmetric.\n", case_id);
        }
        else
        {
            printf("Test #%d: Non-symmetric.\n", case_id);
        }
    }
    return 0;
}