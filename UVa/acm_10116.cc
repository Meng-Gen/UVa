#include <iostream>
#include <stdio.h>
#include <string.h>

int main(int argc, char* argv[]) 
{
    int rows;
    int columns; 
    int enter_pos; 
    while (std::cin >> rows >> columns >> enter_pos)
    {
        if (rows == 0 && columns == 0 && enter_pos == 0)
        {
            break;
        }
        char grid[20][20];
        for (int i = 0; i < rows; i++)
        {
            std::cin >> grid[i];
        }
        
        int visited[20][20];
        memset(visited, -1, sizeof(int) * 20 * 20);

        int x = 0;
        int y = enter_pos - 1;
        int moves = 0;

        visited[x][y] = 0;
        while(1) 
        {
            moves++;
            if (grid[x][y] == 'N')
            {
                x--;
            }
            else if (grid[x][y] == 'S')
            {
                x++;
            }
            else if (grid[x][y] == 'E')
            {
                y++;
            }
            else
            {
                y--;
            }
            if (x < 0 || y < 0 || x >= rows || y >= columns) 
            {
                printf("%d step(s) to exit\n", moves);
                break;
            }
            if (visited[x][y] != -1) 
            {
                printf
                (
                    "%d step(s) before a loop of %d step(s)\n", 
                    visited[x][y], 
                    moves - visited[x][y]
                );
                break;
            }
            visited[x][y] = moves;
        }
    }
    return 0;
}
