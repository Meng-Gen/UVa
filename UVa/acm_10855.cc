#include <iostream>
#include <stdio.h>

int N, M;

char src[502][502] = {};
char matcher[4][502][502] = {};

void BuildRotatedMatcher()
{
    for (int d = 1; d < 4; d++)
    {
        for (int i = 0; i < M; i++)
        {
            for (int j = 0; j < M; j++)
            {
                matcher[d][j][M-1-i] = matcher[d-1][i][j];
            }
        }
    }
}

void ReadSquareContent()
{
    for (int i = 0; i < N; i++)
    {
        std::cin >> src[i];
    }
    for (int i = 0; i < M; i++)
    {
        std::cin >> matcher[0][i];
    }
}

bool IsMatched(int d, int x, int y)
{
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (matcher[d][i][j] != src[x+i][y+j])
            {
                return false;
            }
        }
    }
    return true;
}

int GetAppearanceCount(int d)
{
    int count = 0;
    for (int x = 0; x < N - M + 1; x++)
    {
        for (int y = 0; y < N - M + 1; y++)
        {
            if (IsMatched(d, x, y))
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
    while (std::cin >> N >> M && (N || M))
    {
        ReadSquareContent();
        BuildRotatedMatcher();
        for (int d = 0; d < 4; d++)
        {
            printf("%d", GetAppearanceCount(d));
            putchar((d == 3) ? '\n' : ' ');
        }
    }
    return 0;
}