#include <iostream>
#include <stdio.h>

int maximum(int a, int b)
{
    return (a > b) ? a : b;
}

int minimum(int a, int b)
{
    return (a < b) ? a : b;
}

// -----------------------------------------------------------------------------

struct Position 
{
    int i;
    int j;

    Position() : i(-1), j(-1) { }
    Position(int init_i, int init_j) : i(init_i), j(init_j) { }

    void Set(int init_i, int init_j) 
    {
        i = init_i;
        j = init_j;
    }
};

char board[8][10] = {};

bool IsEmptyBoard()
{
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if (board[i][j] != '.')
            {
                return false;
            }
        }
    }
    return true;
}

bool ReadBoard()
{
    for (int i = 0; i < 8; i++)
    {
        std::cin >> board[i];
    }
    return !IsEmptyBoard();
}

Position ChessPosition(char chess)
{
    Position king;
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if (board[i][j] == chess)
            {
                king.Set(i, j);
            }
        }
    }
    return king;
}

bool HasWhitePawnCheck(const Position& pawn, const Position& king)
{
    return pawn.i-1 == king.i && (pawn.j-1 == king.j || pawn.j+1 == king.j);
}

bool HasBlackPawnCheck(const Position& pawn, const Position& king)
{
    return pawn.i+1 == king.i && (pawn.j-1 == king.j || pawn.j+1 == king.j);
}

bool HasKnightCheck(const Position& knight, const Position& king)
{
    int knight_i[8] = { 2,  2, 1,  1, -1, -1, -2, -2 };
    int knight_j[8] = { 1, -1, 2, -2,  2, -2,  1, -1 };
    for (int k = 0; k < 8; k++)
    {
        if (knight.i + knight_i[k] == king.i && 
            knight.j + knight_j[k] == king.j)
        {
            return true;
        }
    }
    return false;
}

bool HasRookCheck(const Position& rook, const Position& king)
{
    if (rook.i == king.i)
    {
        int lower_bound = minimum(rook.j, king.j);
        int upper_bound = maximum(rook.j, king.j);
        for (int j = lower_bound + 1; j < upper_bound; j++)
        {
            if (board[rook.i][j] != '.')
            {
                return false;
            }
        }
        return true;
    }
    else if (rook.j == king.j)
    {
        int lower_bound = minimum(rook.i, king.i);
        int upper_bound = maximum(rook.i, king.i);
        for (int i = lower_bound + 1; i < upper_bound; i++)
        {
            if (board[i][rook.j] != '.')
            {
                return false;
            }
        }
        return true;
    }
    return false;
}

bool HasBishopCheck(const Position& bishop, const Position& king)
{
    if (bishop.i - king.i == bishop.j - king.j)
    {
        int i_lower_bound = minimum(bishop.i, king.i);
        int i_upper_bound = maximum(bishop.i, king.i);
        int j_lower_bound = minimum(bishop.j, king.j);
        int j_upper_bound = maximum(bishop.j, king.j);
        for (int k = 1; k < i_upper_bound - i_lower_bound; k++)
        {
            if (board[i_lower_bound + k][j_lower_bound + k] != '.')
            {
                return false;
            }
        }
        return true;
    }
    else if (bishop.i - king.i == king.j - bishop.j)
    {
        int i_lower_bound = minimum(bishop.i, king.i);
        int i_upper_bound = maximum(bishop.i, king.i);
        int j_lower_bound = minimum(bishop.j, king.j);
        int j_upper_bound = maximum(bishop.j, king.j);
        for (int k = 1; k < i_upper_bound - i_lower_bound; k++)
        {
            if (board[i_lower_bound + k][j_upper_bound - k] != '.')
            {
                return false;
            }
        }
        return true;
    }
    return false;
}

bool HasQueenCheck(const Position& queen, const Position& king)
{
    return HasRookCheck(queen, king) || HasBishopCheck(queen, king);
}

// -----------------------------------------------------------------------------

Position king;
Position chess;

bool IsBlackKingInCheck()
{
    king = ChessPosition('k');
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            chess.Set(i, j);
            char c = board[i][j];
            if ((c == 'P' && HasWhitePawnCheck(chess, king)) ||
                (c == 'N' && HasKnightCheck(chess, king)) ||
                (c == 'R' && HasRookCheck(chess, king)) ||
                (c == 'B' && HasBishopCheck(chess, king)) ||
                (c == 'Q' && HasQueenCheck(chess, king)))
            {
                return true;
            }
        }
    }
    return false;
}

bool IsWhiteKingInCheck()
{
    king = ChessPosition('K');
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            chess.Set(i, j);
            char c = board[i][j];
            if ((c == 'p' && HasBlackPawnCheck(chess, king)) ||
                (c == 'n' && HasKnightCheck(chess, king)) ||
                (c == 'r' && HasRookCheck(chess, king)) ||
                (c == 'b' && HasBishopCheck(chess, king)) ||
                (c == 'q' && HasQueenCheck(chess, king)))
            {
                return true;
            }
        }
    }
    return false;
}

// -----------------------------------------------------------------------------

int main(int argc, char* argv[]) 
{   
    int game_id = 1;
    while (ReadBoard())
    {
        if (IsBlackKingInCheck())
        {
            printf("Game #%d: black king is in check.\n", game_id);
        }
        else if (IsWhiteKingInCheck())
        {
            printf("Game #%d: white king is in check.\n", game_id);
        }
        else
        {
            printf("Game #%d: no king is in check.\n", game_id);
        }
        game_id++;
    }
    return 0;
}
