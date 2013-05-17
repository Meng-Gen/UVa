#include <iostream>
#include <string>
#include <stdio.h>

inline int AlphaToLower(char c) {
    return c | 0x20;
}

inline bool IsInRange(int value, int lower_limit, int higher_limit) {
    return static_cast<unsigned int>(value - lower_limit) <=
        static_cast<unsigned int>(higher_limit - lower_limit);
}

inline bool IsAlpha(char c) {
    return IsInRange(AlphaToLower(c), 'a', 'z');
}

inline bool IsVowelAlpha(char c) {
    int v = AlphaToLower(c);
    return v == 'a' || v == 'e' || v == 'i' || v == 'o' || v == 'u';
}

int main(int argc, char* argv[])
{
    char word_buffer[5000] = {};
    bool word_phase = false;
    int c0_ = 0;

    char c;
    while (1) 
    {
        c = getchar();
        if (c == EOF) 
        { 
            break; 
        }

        if (word_phase)
        {
            if (IsAlpha(c))
            {
                word_buffer[c0_] = c;
                c0_++;
            }
            else
            {
                word_buffer[c0_] = 0;
                if (IsVowelAlpha(word_buffer[0])) 
                {
                    printf(word_buffer);
                } 
                else 
                {
                    word_buffer[c0_] = 0;
                    printf(word_buffer + 1);
                    putchar(word_buffer[0]);
                }
                printf("ay");
                putchar(c);
                word_phase = false;
                c0_ = 0;
            }
        }
        else
        {
            if (IsAlpha(c))
            {
                word_buffer[c0_] = c;
                c0_++;
                word_phase = true;
            }
            else
            {
                putchar(c);
            }
        }
    }

    return 0;
}