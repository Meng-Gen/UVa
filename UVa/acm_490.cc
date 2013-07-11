#include <iostream>
#include <string>
#include <stdio.h>

char S[102][102] = {};
int max_length = 0;
int x = 0;
int y = 0;

inline void ReadInput()
{
    std::string buffer;
    while (getline(std::cin, buffer))
    {
        int length = buffer.size();
        for (int j = 0; j < length; j++)
        {
            S[x][j] = buffer[j];
        }

        if (length > max_length)
        {
            max_length = length;
        }
        x++;
    }
}

inline void PrintRotatedSentences()
{
    for (int j = 0; j < max_length; j++)
    {
        for (int i = x - 1; i >= 0; i--)
        {
            putchar(S[i][j] ? S[i][j] : ' ');
        }
        putchar('\n');
    }
}

int main(int argc, char* argv[])
{
    ReadInput();
    PrintRotatedSentences();
    return 0;
}