#include <iostream>
#include <stdio.h>

char grid[101][101] = {};

bool IsRectangle(int lower_i, int upper_i, int lower_j, int upper_j)
{
    for (int i = lower_i; i <= upper_i; i++)
    {
        for (int j = lower_j; j <= upper_j; j++)
        {
            if (grid[i][j] != '1')
            {
                return false;
            }
        }
    }
    return true;
}

int main(int argc, char* argv[]) 
{
    int rows = 0;
    int columns = 0;
    while (std::cin >> rows && (rows != 0))
    {
        std::cin >> columns;
        
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < columns; j++)
            {
                std::cin >> grid[i][j];
            }
        }
        
        int rectangle_count = 0;
        for (int lower_i = 0; lower_i < rows; lower_i++)
        {
            for (int upper_i = lower_i; upper_i < rows; upper_i++)
            {
                for (int lower_j = 0; lower_j < columns; lower_j++)
                {
                    for (int upper_j = lower_j; upper_j < columns; upper_j++)
                    {
                        if (IsRectangle(lower_i, upper_i, lower_j, upper_j))
                        {
                            rectangle_count++;
                        }
                    }
                }
            }
        }
        printf("%d\n", rectangle_count);
    }
    return 0;
}