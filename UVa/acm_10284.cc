#include <iostream>
#include <string>
#include <stdio.h>

inline int AsciiAlphaToLower(char c) {
    return c | 0x20;
}

inline bool IsInRange(int value, int lower_limit, int higher_limit) {
    return static_cast<unsigned int>(value - lower_limit) <=
        static_cast<unsigned int>(higher_limit - lower_limit);
}

inline bool IsDecimalDigit(char c) {
    return IsInRange(c, '0', '9');
}

// -----------------------------------------------------------------------------

char board[8][8] = {};

inline void ParseBoard(const std::string& fen)
{
    int x = 0;
    int y = 0;
    for (int i = 0; i < fen.size(); i++)
    {
        char c = fen[i];
        if (c == '/')
        {
            x++;
            y = 0;
        }
        else if (IsDecimalDigit(c))
        {
            int num_spaces = c - '0';
            for (int space_id = 0; space_id < num_spaces; space_id++)
            {
                board[x][y] = '.';
                y++;
            }
        }
        else 
        {
            board[x][y] = c;
            y++;
        }
    }
}

bool IsValid(int x, int y)
{
    return x >= 0 && x < 8 && y >= 0 && y < 8;
}

// -----------------------------------------------------------------------------

void FillRookAttackedSquares(int x, int y)
{
    for (int i = x-1; i >= 0; i--)
    {
        if (board[i][y] == '.')
        {
            board[i][y] = '*';
        }
        else if (board[i][y] != '*')
        {
            break;
        }
    }
    for (int i = x+1; i < 8; i++)
    {
        if (board[i][y] == '.')
        {
            board[i][y] = '*';
        }
        else if (board[i][y] != '*')
        {
            break;
        }
    }
    for (int j = y-1; j >= 0; j--)
    {
        if (board[x][j] == '.')
        {
            board[x][j] = '*';
        }
        else if (board[x][j] != '*')
        {
            break;
        }
    }
    for (int j = y+1; j < 8; j++)
    {
        if (board[x][j] == '.')
        {
            board[x][j] = '*';
        }
        else if (board[x][j] != '*')
        {
            break;
        }
    }
}

void FillKnightAttackedSquares(int x, int y)
{
    int attacked_x, attacked_y;
    int knight_x[8] = { 2,  2, 1,  1, -1, -1, -2, -2 };
    int knight_y[8] = { 1, -1, 2, -2,  2, -2,  1, -1 };
    for (int k = 0; k < 8; k++)
    {
        attacked_x = x + knight_x[k];
        attacked_y = y + knight_y[k];
        if (!IsValid(attacked_x, attacked_y))
        {
            continue;
        }
        if (board[attacked_x][attacked_y] == '.')
        {
            board[attacked_x][attacked_y] = '*';
        }
    }
}

void FillBishopAttackedSquares(int x, int y)
{
    int attacked_x, attacked_y;
    for (int i = x-1; i >= 0; i--)
    {
        attacked_x = i;
        attacked_y = y + i - x;
        if (!IsValid(attacked_x, attacked_y))
        {
            continue;
        }
        if (board[attacked_x][attacked_y] == '.')
        {
            board[attacked_x][attacked_y] = '*';
        }
        else if (board[attacked_x][attacked_y] != '*')
        {
            break;
        }
    }
    for (int i = x+1; i < 8; i++)
    {
        attacked_x = i;
        attacked_y = y + i - x;
        if (!IsValid(attacked_x, attacked_y))
        {
            continue;
        }
        if (board[attacked_x][attacked_y] == '.')
        {
            board[attacked_x][attacked_y] = '*';
        }
        else if (board[attacked_x][attacked_y] != '*')
        {
            break;
        }
    }
    for (int i = x-1; i >= 0; i--)
    {
        attacked_x = i;
        attacked_y = y - i + x;
        if (!IsValid(attacked_x, attacked_y))
        {
            continue;
        }
        if (board[attacked_x][attacked_y] == '.')
        {
            board[attacked_x][attacked_y] = '*';
        }
        else if (board[attacked_x][attacked_y] != '*')
        {
            break;
        }
    }
    for (int i = x+1; i < 8; i++)
    {
        attacked_x = i;
        attacked_y = y - i + x;
        if (!IsValid(attacked_x, attacked_y))
        {
            continue;
        }
        if (board[attacked_x][attacked_y] == '.')
        {
            board[attacked_x][attacked_y] = '*';
        }
        else if (board[attacked_x][attacked_y] != '*')
        {
            break;
        }
    }
}

void FillQueenAttackedSquares(int x, int y)
{
    FillRookAttackedSquares(x, y);
    FillBishopAttackedSquares(x, y);
}

void FillKingAttackedSquares(int x, int y)
{
    int attacked_x, attacked_y;
    for (int dx = -1; dx <= 1; dx++)
    {
        for (int dy = -1; dy <= 1; dy++)
        {
            attacked_x = x + dx;
            attacked_y = y + dy;
            if (!IsValid(attacked_x, attacked_y))
            {
                continue;
            }
            if (board[attacked_x][attacked_y] == '.')
            {
                board[attacked_x][attacked_y] = '*';
            }
        }
    }
}

void FillBlackPawnAttackedSquares(int x, int y)
{
    int attacked_x, attacked_y;
    int pawn_x[2] = { 1,  1 };
    int pawn_y[2] = { 1, -1 };
    for (int k = 0; k < 2; k++)
    {
        attacked_x = x + pawn_x[k];
        attacked_y = y + pawn_y[k];
        if (!IsValid(attacked_x, attacked_y))
        {
            continue;
        }
        if (board[attacked_x][attacked_y] == '.')
        {
            board[attacked_x][attacked_y] = '*';
        }
    }
}

void FillWhitePawnAttackedSquares(int x, int y)
{
    int attacked_x, attacked_y;
    int pawn_x[2] = { -1, -1 };
    int pawn_y[2] = {  1, -1 };
    for (int k = 0; k < 2; k++)
    {
        attacked_x = x + pawn_x[k];
        attacked_y = y + pawn_y[k];
        if (!IsValid(attacked_x, attacked_y))
        {
            continue;
        }
        if (board[attacked_x][attacked_y] == '.')
        {
            board[attacked_x][attacked_y] = '*';
        }
    }
}

void FillAttackedSquares()
{
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            char c = board[i][j];
            if (c == 'r' || c == 'R')
            {
                FillRookAttackedSquares(i, j);
            }
            else if (c == 'n' || c == 'N')
            {
                FillKnightAttackedSquares(i, j);
            }
            else if (c == 'b' || c == 'B')
            {
                FillBishopAttackedSquares(i, j);
            }
            else if (c == 'q' || c == 'Q')
            {
                FillQueenAttackedSquares(i, j);
            }
            else if (c == 'k' || c == 'K')
            {
                FillKingAttackedSquares(i, j);
            }
            else if (c == 'p')
            {
                FillBlackPawnAttackedSquares(i, j);
            }
            else if (c == 'P')
            {
                FillWhitePawnAttackedSquares(i, j);
            }
        }
    }
}

// -----------------------------------------------------------------------------

inline int GetUnoccupiedAttackedSquareCount()
{
    int count = 0;
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if (board[i][j] == '.')
            {
                count++;
            }
        }
    }
    return count;
}

// -----------------------------------------------------------------------------

int main(int argc, char* argv[]) 
{   
    std::string fen;
    while (std::cin >> fen)
    {
        ParseBoard(fen);
        FillAttackedSquares();
        std::cout << GetUnoccupiedAttackedSquareCount() << std::endl;
    }
    return 0;
}
