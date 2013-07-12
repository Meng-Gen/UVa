#include <iostream>
#include <stdio.h>

char puzzle[55][55] = {};
int N, M, S;

char raw_piece[55][55] = {};
int raw_n, raw_m;

char piece[55][55] = {};
int n, m;

// Special Yes Cases: 
//
// 2 2 1
// **
// .*
// 3 2
// ..
// ..
// ..
// 
// 2 2 1
// **
// .*
// 3 2
// ..
// ..
// **
void TrimPiece()
{
    bool is_empty_piece = true;

    int lower_n = 0;
    for (int i = 0; i < raw_n; i++)
    {
        bool are_empty = true;
        for (int j = 0; j < raw_m; j++)
        {
            if (raw_piece[i][j] != '.')
            {
                are_empty = false;
                break;
            }
        }
        if (!are_empty)
        {
            lower_n = i;
            is_empty_piece = false;
            break;
        }
    }
    
    if (is_empty_piece)
    {
        n = 0;
        m = 0;
        return;
    }

    int upper_n = raw_n;
    for (int i = raw_n - 1; i >= 0; i--)
    {
        bool are_empty = true;
        for (int j = 0; j < raw_m; j++)
        {
            if (raw_piece[i][j] != '.')
            {
                are_empty = false;
                break;
            }
        }
        if (!are_empty)
        {
            upper_n = i + 1;
            break;
        }
    }

    int lower_m = 0;
    for (int j = 0; j < raw_m; j++)
    {
        bool are_empty = true;
        for (int i = 0; i < raw_n; i++)
        {
            if (raw_piece[i][j] != '.')
            {
                are_empty = false;
                break;
            }
        }
        if (!are_empty)
        {
            lower_m = j;
            break;
        }
    }

    int upper_m = raw_m;
    for (int j = raw_m - 1; j >= 0; j--)
    {
        bool are_empty = true;
        for (int i = 0; i < raw_n; i++)
        {
            if (raw_piece[i][j] != '.')
            {
                are_empty = false;
                break;
            }
        }
        if (!are_empty)
        {
            upper_m = j + 1;
            break;
        }
    }

    for (int i = lower_n; i < upper_n; i++)
    {
        for (int j = lower_m; j < upper_m; j++)
        {
            piece[i - lower_n][j - lower_m] = raw_piece[i][j];
        }
    }

    n = upper_n - lower_n;
    m = upper_m - lower_m;
}

bool IsFound()
{
    if (n > N || m > M)
    {
        return false;
    }

    for (int x = 0; x <= N - n; x++)
    {
        for (int y = 0; y <= M - m; y++)
        {
            bool matched = true;
            for (int i = 0; i < n; i++)
            {
                if (!matched)
                {
                    break;
                }
                for (int j = 0; j < m; j++)
                {
                    if ((piece[i][j] == '*') && (puzzle[x + i][y + j] == '.'))
                    {
                        matched = false;
                        break;
                    }
                }
            }
            if (matched)
            {
                return true;
            }
        }
    }
    return false;
}

int main(int argc, char* argv[])
{
    int num_testcases;
    std::cin >> num_testcases;
    while (num_testcases--)
    {
        std::cin >> N >> M >> S;
        for (int i = 0; i < N; i++)
        {
            std::cin >> puzzle[i];
        }
        for (int i = 0; i < S; i++)
        {
            std::cin >> raw_n >> raw_m;
            for (int j = 0; j < raw_n; j++)
            {
                std::cin >> raw_piece[j];
            }

            TrimPiece();
            if (IsFound())
            {
                puts("Yes");
            }
            else
            {
                puts("No");
            }
        }

        putchar('\n');
    }
    return 0;
}