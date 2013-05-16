// Submit again if you got CE with the message
// ``virtual memory exhausted: Cannot allocate memory''

#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <stdio.h>

char buffer[30];

int main(int argc, char* argv[])
{
    std::stringstream english_word_builder;
    std::stringstream waterloo_word_builder;
    std::map<std::string, std::string> dictionary;
    while (std::cin.getline(buffer, 30))
    {
        if (buffer[0] == 0)
        {
            break;
        }

        int i = 0;
        english_word_builder.str("");
        for (; buffer[i] != ' '; i++)
        {
            english_word_builder << buffer[i];
        }

        i++;
        waterloo_word_builder.str("");
        for (; buffer[i] != 0; i++)
        {
            waterloo_word_builder << buffer[i];
        }
        dictionary[waterloo_word_builder.str()] = english_word_builder.str();
    }

    while (std::cin.getline(buffer, 30))
    {
        std::string translated_word = dictionary[buffer];
        if (translated_word.empty())
        {
            translated_word = "eh";
        }
        std::cout << translated_word << std::endl; 
    }

    return 0;
}