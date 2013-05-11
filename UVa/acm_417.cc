#include <iostream>
#include <map>
#include <string>
#include <stdio.h>

std::map<std::string, int> word_index;

void init_word_index()
{
    int curr_index = 1;
    for (char i = 'a'; i <= 'z'; i++)
    {
        word_index[std::string(1, i)] = curr_index;
        curr_index++;
    }
    
    for (char i = 'a'; i <= 'z'; i++)
    {
        for (char j = i + 1; j <= 'z'; j++)
        {
            char array_word[3] = { i, j, 0 };
            word_index[std::string(array_word)] = curr_index;
            curr_index++;
        }
    }

    for (char i = 'a'; i <= 'z'; i++)
    {
        for (char j = i + 1; j <= 'z'; j++)
        {
            for (char k = j + 1; k <= 'z'; k++)
            {
                char array_word[4] = { i, j, k, 0 };
                word_index[std::string(array_word)] = curr_index;
                curr_index++;
            }
        }
    }

    // Forgive me...
    for (char i = 'a'; i <= 'z'; i++)
    {
        for (char j = i + 1; j <= 'z'; j++)
        {
            for (char k = j + 1; k <= 'z'; k++)
            {
                for (char p = k + 1; p <= 'z'; p++)
                {
                    char array_word[5] = { i, j, k, p, 0 };
                    word_index[std::string(array_word)] = curr_index;
                    curr_index++;
                }
            }
        }
    }

    // Please forgive me...
    for (char i = 'a'; i <= 'z'; i++)
    {
        for (char j = i + 1; j <= 'z'; j++)
        {
            for (char k = j + 1; k <= 'z'; k++)
            {
                for (char p = k + 1; p <= 'z'; p++)
                {
                    for (char q = p + 1; q <= 'z'; q++)
                    {
                        char array_word[6] = { i, j, k, p, q, 0 };
                        word_index[std::string(array_word)] = curr_index;
                        curr_index++;
                    }
                }
            }
        }
    }
}

int main(int argc, char* argv[])
{
    init_word_index();

    std::string word;
    while (std::cin >> word)
    {
        std::cout << word_index[word] << std::endl;
    }
    return 0;
}