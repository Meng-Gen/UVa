#include <iostream>
#include <map>
#include <string>
#include <stdio.h>

bool square[10002] = {};
std::map<int, int> square_root;

void InitSquareQuery()
{
    for (int i = 0; i <= 100; i++)
    {
        square[i * i] = true;
        square_root[i * i] = i;
    }
}

int main(int argc, char* argv[])
{
    InitSquareQuery();

    int num_testcases;
    std::cin >> num_testcases;
    getchar();
    while (num_testcases--)
    {
        std::string cipher_text;
        getline(std::cin, cipher_text);

        int length = cipher_text.size();
        if (!square[length])
        {
            puts("INVALID");
            continue;
        }

        int grid_length = square_root[length];
        for (int i = 0; i < grid_length; i++)
        {
            for (int j = 0; j < grid_length; j++)
            {
                putchar(cipher_text[j * grid_length + i]);
            }
        }
        putchar('\n');
    }

    return 0;
}