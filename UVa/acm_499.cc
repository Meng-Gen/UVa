#include <algorithm>
#include <iostream>
#include <string>
#include <stdio.h>

char buffer[50000];

bool compare_on_letter_count(std::pair<char, int> lhs, std::pair<char, int> rhs)
{	
    if (lhs.second > rhs.second)
    {
        return true;
    }
    if (lhs.second < rhs.second)
    {
        return false;
    }
    if (lhs.first < rhs.first) 
    {
        return true;
    }
    return false;
}

int main(int argc, char* argv[])
{
    while (std::cin.getline(buffer, 50000))
    {
        std::pair<char, int> LetterCount[52];
        for (int i = 0; i < 26; i++)
        {
            LetterCount[i].first = 'A' + i;
            LetterCount[i].second = 0;
            LetterCount[i+26].first = 'a' + i;
            LetterCount[i+26].second = 0;
        }

        for (int j = 0; buffer[j] != '\0'; j++)
        {
            if (buffer[j] >= 'a' && buffer[j] <= 'z')
            {
                LetterCount[buffer[j] - 'a' + 26].second++;
            }
            else if (buffer[j] >= 'A' && buffer[j] <= 'Z')
            {
                LetterCount[buffer[j] - 'A'].second++;
            }
        }

        // Might overkill.
        std::sort(LetterCount, LetterCount + 52, compare_on_letter_count);

        int max_count = LetterCount[0].second;
        for (int i = 0; i < 52; i++)
        {
            if (LetterCount[i].second != max_count)
            {
                break;
            }
            printf("%c", LetterCount[i].first);
        }
        printf(" %d\n", max_count);
    }
    return 0;
}