#include <iostream>
#include <string>
#include <stdio.h>

char puzzle[5][5] = {};

int empty_pos_x;
int empty_pos_y;

inline void SetEmptyPos()
{
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (puzzle[i][j] == ' ')
            {
                empty_pos_x = i;
                empty_pos_y = j;
                break;
            }
        }
    }    
}

// -----------------------------------------------------------------------------

bool MoveAbove()
{
    if (empty_pos_x == 0)
    {
        return false;
    }
    puzzle[empty_pos_x][empty_pos_y] = puzzle[empty_pos_x - 1][empty_pos_y];
    puzzle[empty_pos_x - 1][empty_pos_y] = ' ';
    empty_pos_x--;
    return true;
}

bool MoveBelow()
{
    if (empty_pos_x == 4)
    {
        return false;
    }
    puzzle[empty_pos_x][empty_pos_y] = puzzle[empty_pos_x + 1][empty_pos_y];
    puzzle[empty_pos_x + 1][empty_pos_y] = ' ';
    empty_pos_x++;
    return true;
}

bool MoveRight()
{
    if (empty_pos_y == 4)
    {
        return false;
    }
    puzzle[empty_pos_x][empty_pos_y] = puzzle[empty_pos_x][empty_pos_y + 1];
    puzzle[empty_pos_x][empty_pos_y + 1] = ' ';
    empty_pos_y++;
    return true;
}

bool MoveLeft()
{
    if (empty_pos_y == 0)
    {
        return false;
    }
    puzzle[empty_pos_x][empty_pos_y] = puzzle[empty_pos_x][empty_pos_y - 1];
    puzzle[empty_pos_x][empty_pos_y - 1] = ' ';
    empty_pos_y--;
    return true;
}

bool MovePuzzle()
{
    bool is_valid = true;
    std::string move_sequence;
    int L = 0;
    while (getline(std::cin, move_sequence))
    {
        L = move_sequence.size();
        for (int i = 0; i < L; i++)
        {
            if (!is_valid)
            {
                break;
            }
            if (move_sequence[i] == 'A')
            {
                if (!MoveAbove())
                {
                    is_valid = false;
                }
            }
            else if (move_sequence[i] == 'B')
            {
                if (!MoveBelow())
                {
                    is_valid = false;
                }
            }
            else if (move_sequence[i] == 'R')
            {
                if (!MoveRight())
                {
                    is_valid = false;
                }
            }
            else if (move_sequence[i] == 'L')
            {
                if (!MoveLeft())
                {
                    is_valid = false;
                }
            }
        }
        if (move_sequence[L - 1] == '0')
        {
            break;
        }
    }
    return is_valid;
}

// -----------------------------------------------------------------------------

void PrintPuzzle()
{
    for (int i = 0; i < 5; i++)
    {
        printf("%c", puzzle[i][0]);
        for (int j = 1; j < 5; j++)
        {
            printf(" %c", puzzle[i][j]);
        }
        putchar('\n');
    }
}

bool is_valid;
int case_id = 1;

void PrintSolution()
{
    if (case_id > 1)
    {
        putchar('\n');
    }
    printf("Puzzle #%d:\n", case_id);
    if (is_valid)
    {
        PrintPuzzle();
    }
    else
    {
        puts("This puzzle has no final configuration.");
    }
}

// -----------------------------------------------------------------------------

int main(int argc, char* argv[])
{
    std::string buffer;
    while (getline(std::cin, buffer) && (buffer != "Z"))
    {
        for (int j = 0; j < 5; j++)
        {
            puzzle[0][j] = buffer[j];
        }

        // Continue reading input
        for (int i = 1; i < 5; i++)
        {
            getline(std::cin, buffer);
            for (int j = 0; j < 5; j++)
            {
                puzzle[i][j] = buffer[j];
            }
        }

        SetEmptyPos();
        
        is_valid = MovePuzzle();
        
        PrintSolution();

        case_id++;
    }
    return 0;
}