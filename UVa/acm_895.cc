#include <iostream>
#include <string>
#include <stdio.h>

int dictionary[1005][26] = {};

int main(int argc, char* argv[])
{
    std::string buffer;
    int dictionary_size = 0;
    while (getline(std::cin, buffer) && (buffer != "#"))
    {
        for (int i = 0; i < buffer.size(); i++)
        {
            dictionary[dictionary_size][buffer[i] - 'a']++;
        }
        dictionary_size++;
    }

    char c = 0;
    while (getline(std::cin, buffer) && (buffer != "#"))
    {
        int letter[26] = {};
        for (int i = 0; i < buffer.size(); i++)
        {
            c = buffer[i];
            if (c >= 'a' && c <= 'z')
            {
                letter[c - 'a']++;
            }
        }

        int rv = 0;
        bool possible;
        for (int i = 0; i < dictionary_size; i++)
        {
            possible = true;
            for (int j = 0; j < 26; j++)
            {
                if (dictionary[i][j] > letter[j])
                {
                    possible = false;
                    break;
                }
            }
            if (possible)
            {
                rv++;
            }
        }
        printf("%d\n", rv);
    }
    return 0;
}