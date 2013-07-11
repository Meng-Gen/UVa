#include <iostream>
#include <sstream>
#include <string>
#include <stdio.h>

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

int main(int argc, char* argv[])
{
    std::string source;
    std::stringstream buffer;
    int len;
    char c;
    bool has_hyphen = false;
    while (getline(std::cin, source) && (source != "#"))
    {
        len = source.size();
        for (int i = 0; i < len; i++)
        {
            c = source[i];
            if (IsAsciiAlpha(c))
            {
                buffer << c;
            }
            else if (c == ' ')
            {
                if (has_hyphen)
                {
                    std::cout << buffer.str() << std::endl << c;
                    has_hyphen = false;
                }
                else
                {
                    std::cout << buffer.str() << c;
                }
                buffer.str(std::string());
            }
            if (i == len - 1)
            {
                if (c != '-')
                {
                    std::cout << buffer.str() << std::endl;
                    buffer.str(std::string());
                }
                else 
                {
                    has_hyphen = true;
                    std::cout << std::endl;
                }
            }
        }
    }
    return 0;
}