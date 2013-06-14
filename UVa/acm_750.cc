#include <iostream>
#include <stdio.h>
#include <stdlib.h>

int queen_place[9] = {};
int solution_count;
int row, column;

bool IsGoodPosition(int queen, int row)
{
    for (int prev_queen = 1; prev_queen <= queen - 1; prev_queen++)
    {
        if (queen_place[prev_queen] == row || 
            (abs(queen_place[prev_queen] - row) == abs(prev_queen - queen)))
        {
            return false;
        }
    }
    return true;
}

inline void PrintSolution()
{
    solution_count++;
    printf("%2d     ", solution_count);
    for (int queen = 1; queen <= 8; queen++)
    {
        printf(" %d", queen_place[queen]);
    }
    putchar('\n');
}

void PutQueen(int queen)
{
    for (int i = 1; i <= 8; i++)
    {
        if (IsGoodPosition(queen, i))
        {
            queen_place[queen] = i;
            if (queen == 8 && queen_place[column] == row)
            {
                PrintSolution();
            }
            else
            {
                PutQueen(queen + 1);
            }
        }
    }
}

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
        std::cin >> row >> column;

        puts("SOLN       COLUMN");
        puts(" #      1 2 3 4 5 6 7 8");
        putchar('\n');

        for (int i = 0; i < 9; i++)
        {
            queen_place[i] = 0;
        }
        solution_count = 0;

        PutQueen(1);
    }
    
    return 0;
}