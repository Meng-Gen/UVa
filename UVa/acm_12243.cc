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

inline bool IsAsciiLowerAlpha(char c) {
    return IsInRange(c, 'a', 'z');
}

bool IsTautogram(const std::string& sentence)
{
    bool is_word_phase = false;
    bool is_first_word = true;
    char start_letter = 0;
    for (unsigned int i = 0; i < sentence.size(); i++)
    {
        char c = AsciiAlphaToLower(sentence[i]);
        if (is_word_phase)
        {
            if (IsAsciiLowerAlpha(c))
            {
                continue;
            }
            else
            {
                is_word_phase = false;
            }
        }
        else
        {
            if (IsAsciiLowerAlpha(c))
            {
                if (is_first_word)
                {
                    start_letter = c;
                    is_first_word = false;
                }
                else
                {
                    if (c != start_letter)
                    {
                        return false;
                    }
                }
                is_word_phase = true;
            }
        }
    }
    return true;
}

int main(int argc, char* argv[]) 
{
    std::string buffer;
    while (getline(std::cin, buffer) && (buffer != "*"))
    {
        if (IsTautogram(buffer))
        {
            puts("Y");
        }
        else
        {
            puts("N");
        }
    }
    return 0;
}