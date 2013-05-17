#include <iostream>
#include <map>
#include <stdio.h>

inline int AsciiAlphaToLower(char c) {
    return c | 0x20;
}

inline bool IsInRange(int value, int lower_limit, int higher_limit) {
    return static_cast<unsigned int>(value - lower_limit) <=
        static_cast<unsigned int>(higher_limit - lower_limit);
}

int main(int argc, char* argv[])
{
    char keyboard[] = "`1234567890-=qwertyuiop[]\\asdfghjkl;'zxcvbnm,./";
    std::map<char, char> decoder;
    for (int i = 2; keyboard[i] != 0; i++)
    {
        decoder[keyboard[i]] = keyboard[i - 2];
    }

    char c;
    while (1)
    {
        c = getchar();
        if (c == EOF)
        {
            break;
        }
        if (c == ' ' || c == '\n')
        {
            putchar(c);
        }
        else
        {
            if (IsInRange(c, 'A', 'Z'))
            {
                c = AsciiAlphaToLower(c);
            }
            putchar(decoder[c]);
        }
    }

    return 0;
}
