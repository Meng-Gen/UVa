#include <iostream>
#include <sstream>
#include <string>
#include <stdio.h>

// ----------------------------------------------------------------------------
// Char Predicates

inline int AsciiAlphaToLower(char c) {
    return c | 0x20;
}

inline bool IsInRange(int value, int lower_limit, int higher_limit) {
    return static_cast<unsigned int>(value - lower_limit) <=
        static_cast<unsigned int>(higher_limit - lower_limit);
}

inline bool IsAsciiAlpha(char c) {
    return IsInRange(AsciiAlphaToLower(c), 'a', 'z');
}

// ----------------------------------------------------------------------------

std::string Normalize(const std::string& sentence)
{
    std::stringstream builder;

    for (std::string::const_iterator it = sentence.begin();
        it != sentence.end(); it++)
    {
        char c = AsciiAlphaToLower(*it);
        if (IsAsciiAlpha(c))
        {
            builder << c;
        }
    }
    return builder.str();
}

bool IsPalindrome(const std::string& word)
{
    int length = word.size();
    for (int i = 0; i < length/2; i++)
    {
        if (word[i] != word[length-1-i])
        {
            return false;
        }
    }
    return true;
}

int main(int argc, char* argv[]) 
{   
    std::string sentence;
    while (getline(std::cin, sentence) && sentence != "DONE")
    {
        if (IsPalindrome(Normalize(sentence)))
        {
            puts("You won't be eaten!");
        }
        else
        {
            puts("Uh oh..");
        }
    }
    return 0;
}
