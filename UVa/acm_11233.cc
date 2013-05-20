#include <iostream>
#include <map>
#include <string>
#include <stdio.h>

inline bool IsVowelChar(char c)
{
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

int main(int argc, char* argv[])
{
    int L;
    int N;
    std::cin >> L >> N;

    std::map<std::string, std::string> irregular_plural_map;
    std::string word;
    std::string plural;
    for (int i = 0; i < L; i++)
    {
        std::cin >> word >> plural;
        irregular_plural_map[word] = plural;
    }

    for (int i = 0; i < N; i++)
    {
        std::cin >> word;
        std::string irregular_plural = irregular_plural_map[word];

        // irregular
        if (irregular_plural.size())
        {
            std::cout << irregular_plural << std::endl;
            continue;
        }

        // regular
        unsigned int word_size = word.size();
        char c0_ = (word_size >= 1) ? word[word_size - 1] : -1;
        char c1_ = (word_size >= 2) ? word[word_size - 2] : -1; 

        if (c0_ == 'y' && (!IsVowelChar(c1_)))
        {
            std::cout << word.substr(0, word_size - 1) + "ies" << std::endl;
        }
        else if (c0_ == 'o' || c0_ == 's' || c0_ == 'x')
        {
            std::cout << word + "es" << std::endl;
        }
        else if ((c1_ == 'c' || c1_ == 's') && c0_ == 'h')
        {
            std::cout << word + "es" << std::endl;
        }
        else 
        {
            std::cout << word + "s" << std::endl;
        }        
    }

    return 0;
}