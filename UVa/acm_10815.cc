#include <algorithm>
#include <iostream>
#include <set>
#include <string> 
#include <sstream> 
#include <stdio.h>

char buffer[201];

inline int AsciiAlphaToLower(char c) {
    return c | 0x20;
}

inline bool IsInRange(int value, int lower_limit, int higher_limit) {
    return static_cast<unsigned int>(value - lower_limit) <=
        static_cast<unsigned int>(higher_limit - lower_limit);
}

int main(int argc, char* argv[])
{
    std::set<std::string> andy_dictionary;
    while (std::cin.getline(buffer, 201))
    {
        std::stringstream word_builder;
        bool is_begin_word = false;
        for (int i = 0; buffer[i] != '\0'; i++)
        {
            char c = AsciiAlphaToLower(buffer[i]);
            if (IsInRange(c, 'a', 'z'))
            {
                is_begin_word = true;
                word_builder << c;
            }
            else
            {
                if (is_begin_word)
                {
                    is_begin_word = false;
                    andy_dictionary.insert(word_builder.str());
                    word_builder.str("");
                }
            }
        }
        
        if (is_begin_word)
        {
            andy_dictionary.insert(word_builder.str());
        }
    }

    std::set<std::string>::iterator it;
    for (it = andy_dictionary.begin(); it != andy_dictionary.end(); ++it) 
    {
        std::cout << *it << std::endl;
    }

    return 0;
}